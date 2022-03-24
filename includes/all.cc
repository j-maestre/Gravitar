#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "xemath.cc"

//Ancho -> 256*4
//Alto -> 192*4
const int ANCHO = 1024, ALTO = 768, CENTROX = 512, CENTROY = 384 ;
const double dPI = 3.1415926535897;
unsigned char fps=60;
double current_time,last_time;
const float ANGLE_ROTATION = 3;
bool intro = true, interfaz = true;
int credits = 0;
bool scalating = false;

//Para escalar los puntos, cogemos los puntos de un mapa cualquiera, los normalizamos para pasarlos entre 0-1 y luego lo multiplicamos 
//Por el ancho y alto de nuestra pantalla para escalar cualquier mapa a nuestra pantalla


struct TColor{
  int r = 255;
  int g = 255;
  int b = 255;
  int a = 0;
};

struct TDisparo{
  float x,y;
  TColor color;
  bool disparando = false;
  xemath::Vector2 vecDirector = {0.0f,0.0f};
};

struct TPlayer{
  TDisparo *disparos;
  int disparosTotal = 0;
  xemath::Vector2 vecDirector = {0.0f,-15.0f};   //Esto es a donde apunta
  xemath::Vector2 vecPunta = {100.0f, 100.0f};
  float x = 500.0f;
  float y = 400.0f;
  xemath::Vector2 aceleration = {0.0f,0.0f};
  xemath::Vector2 velocity = {0.0f,0.0f}; //este depende de la direccion de la nave, cuando pulso w la aceleracion = aceleracion anterior + la nueva
  float velocidad = 0.1f;
  float angle;
  int nivel = 0;
  int vidas = 5;
  int fuel = 10000;
  int score = 0;
};

struct TEnemy{
  float x,y;
  bool vivo = true;
  TDisparo *disparos;
};

struct TFuel{
  float x,y;
  bool obtained = false;
};

struct TMap{
  float x,y;
};

//fwd = cos(angel),sin(angle)
//aceleration = fwd * 0.1f;
//vel += aceleration


TColor Rojo = {180,0,0};

TColor Verde = {0,180,0};
TColor VerdeClaro = {0,255,157};
TColor VerdeFuel = {144,210,145};
TColor VerdeScore = {72,147,74};

TColor Azul = {0,0,180};
TColor AzulClaro = {0,238,255};
TColor AzulText = {118,209,217};

TColor Blanco = {255,255,255};
TColor Negro = {0,0,0};

TColor Amarillo = {252,255,0};
TColor Morado = {255,0,243};
TColor MoradoOscuro = {192,0,255};
TColor Rosa = {255,0,154};

void Createcircle(float x, float y, float radio, TColor color,float excentricidadX = 1.0f,float excentricidadY = 1.0f, int points = 360, int extravagancia = -1, float peculiaridad = -1.0f){

    //Iniciar circulo
    float *circulo = (float*) malloc(sizeof(float)*(points * 2));
    float angle = (dPI*2) / (float) points;
    for(int i = 0; i<points; i++){
        if(extravagancia ==-1){
            *(circulo + (i * 2)) = (float) cos(angle * i) * excentricidadX;
            *(circulo + (i * 2 +1)) = (float) sin(angle * i) * excentricidadY;
        }else{
            //Cirulo raro
            if(i%extravagancia == 0){
                *(circulo + (i * 2)) = ((float) cos(angle * i) * excentricidadX) * peculiaridad;
                *(circulo + (i * 2 +1)) = ((float) sin(angle * i) * excentricidadY) * peculiaridad;
            }else{
                *(circulo + (i * 2)) = (float) cos(angle * i) * excentricidadX;
                *(circulo + (i * 2 +1)) = (float) sin(angle * i) * excentricidadY;

            }
        }
    }

    //Pintar circulo
    esat::DrawSetStrokeColor(color.r,color.g,color.b);
    esat::DrawSetFillColor(color.r,color.g,color.b,0);

    float *circleToDraw = (float*) malloc(sizeof(float)*(points*2));

    for(int i = 0; i<points; i++){
        *(circleToDraw + (i * 2)) = *(circulo + (i * 2)) * radio + x;
        *(circleToDraw + (i * 2 + 1)) = *(circulo + (i * 2 + 1)) * radio + y;
    }

    esat::DrawSolidPath(circleToDraw,points);
    free(circulo);
    free(circleToDraw);
}
float *pointsNormalized = (float*) malloc(sizeof(float)*76);
float *pointsFuel1Normalized = (float*) malloc(sizeof(float)*8);
float *pointsFuel2Normalized = (float*) malloc(sizeof(float)*8);
float *pointsFuel3Normalized = (float*) malloc(sizeof(float)*8);
float *pointsFuel4Normalized = (float*) malloc(sizeof(float)*8);

TFuel *Fuel1 = (TFuel*) malloc(sizeof(TFuel)*8);
TFuel *Fuel2 = (TFuel*) malloc(sizeof(TFuel)*8);
TFuel *Fuel3 = (TFuel*) malloc(sizeof(TFuel)*8);
TFuel *Fuel4 = (TFuel*) malloc(sizeof(TFuel)*8);

float *pointsMap1pun = (float*) malloc(sizeof(float)*76);
float pointsMap1[38][3] = {
        {74,374,1},
        {307,30,1},
        {382,115,1},
        {306,202,1},
        {382,287,1},
        {305,287,1},
        {229,202,1},
        {153,287,1},
        {229,287,1},
        {76,459,1},
        {152,459,1},
        {76,545,1},
        {229,718,1},
        {306,718,1},
        {382,631,1},
        {306,631,1},
        {230,545,1},
        {383,545,1},
        {613,288,1},
        {689,288,1},
        {614,374,1},
        {689,459,1},
        {766,459,1},
        {690,545,1},
        {460,545,1},
        {537,631,1},
        {690,631,1},
        {843,459,1},
        {768,374,1},
        {690,374,1},
        {766,288,1},
        {690,202,1},
        {536,202,1},
        {460,287,1},
        {383,202,1},
        {536,30,1},
        {620,30,1},
        {843,368,1},
    };




float valorScalate = 1.05f;
float pointsFuel1Map1[4][3] = {
  {117,460},
  {117,476},
  {132,476},
  {132,460},
};
float pointsFuel2Map1[4][3] = {
  {252,719},
  {252,734},
  {267,734},
  {267,719},
};
float pointsFuel3Map1[4][3] = {
  {620,632},
  {620,647},
  {635,647},
  {635,632}
};
float pointsFuel4Map1[4][3] = {
  {700,459},
  {700,474},
  {715,474},
  {715,459}
};

//Map 4 with X scroll
float *pointsMap4pun = (float*) malloc(sizeof(float)*102);
float *points4Normalized = (float*) malloc(sizeof(float)*102);
float pointsMap4[51][3] = {
  {70,763,1},
  {127,731,1},
  {155,731,1},
  {168,698,1},
  {184,746,1},
  {190,738,1},
  {211,738,1},
  {225,714,1},
  {254,755,1},
  {281,755,1},
  {297,738,1},
  {310,690,1},
  {323,737,1},
  {352,762,1},
  {359,731,1},
  {373,731,1},
  {409,762,1},
  {415,731,1},
  {430,731,1},
  {437,763,1},
  {435,730,1},
  {479,754,1},
  {500,754,1},
  {521,715,1},
  {550,715,1},
  {564,691,1},
  {578,714,1},
  {592,691,1},
  {606,714,1},
  {627,714,1},
  {635,746,1},
  {648,746,1},
  {663,731,1},
  {677,699,1},
  {704,755,1},
  {719,755,1},
  {733,723,1},
  {747,755,1},
  {761,746,1},
  {776,746,1},
  {789,700,1},
  {804,746,1},
  {817,731,1},
  {833,731,1},
  {860,747,1},
  {881,731,1},
  {917,731,1},
  {930,692,1},
  {945,731,1},
  {958,731,1},
  {973,762,1},
};


#include "player.cc"
#include "colisiones.cc"
#include "fuel.cc"
#include "geometries.cc"
#include "interface.cc"