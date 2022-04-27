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
const bool debug = false;
const float ANGLE_ROTATION = 3;
bool intro = true, interfaz = true;
int credits = 0;
bool scalating = false;
bool scrollHorizontal = false;

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
  xemath::Vector2 velocity = {0.0f,0.0f}; //NO SE USAeste depende de la direccion de la nave, cuando pulso w la aceleracion = aceleracion anterior + la nueva
  float velocidad = 0.1f;
  float angle;
  int nivel = 0;
  int vidas = 5;
  int fuel = 10000;
  int score = 0;
  float gravityForce = 0.01f;
};

struct TEnemy{
  bool vivo = true;
  TDisparo *disparos;
  xemath::Vector2 vecDirector = {0.0f, -5.0f};
  xemath::Vector2 vecPunta = {100.0f, 200.0f};
  float x = 100.0f;
  float y = 300.0f;
  float velocidad = 1.5f;
  float gravityForce = 0.01f;
  float angle;
};

struct TFuel{
  float x,y;
  bool obtained = false;
};

struct TFuelNew{
  float *points;
  bool obtained = false;
};

struct TMap{
  esat::Vec3 *map;
  float escalar = 231.0f;
  int size;
};

float *points_tmp_map2 = (float *)malloc(sizeof(float) * 48);
float *points_tmp_map3 = (float *)malloc(sizeof(float) * 74);

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

void Createcircle(float x, float y, float radio, TColor color = Rosa,float excentricidadX = 1.0f,float excentricidadY = 1.0f, int points = 360, int extravagancia = -1, float peculiaridad = -1.0f){

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


TFuelNew *Fuel1 = (TFuelNew*) malloc(sizeof(TFuelNew));
TFuelNew *Fuel2 = (TFuelNew*) malloc(sizeof(TFuelNew));
TFuelNew *Fuel3 = (TFuelNew*) malloc(sizeof(TFuelNew));
TFuelNew *Fuel4 = (TFuelNew*) malloc(sizeof(TFuelNew));

float *pointsMap1Original = (float*) malloc(sizeof(float)*76);
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
float *pointsMap4Original = (float*) malloc(sizeof(float)*102);
float *pointsMap4pun = (float*) malloc(sizeof(float)*102);
float *points4Normalized = (float*) malloc(sizeof(float)*102);
float pointsMap4[51][3] = {
  {70,863,1},
  {127,831,1},
  {155,831,1},
  {168,798,1},
  {184,846,1},
  {190,838,1},
  {211,838,1},
  {225,814,1},
  {254,855,1},
  {281,855,1},
  {297,838,1},
  {310,790,1},
  {323,837,1},
  {352,862,1},
  {359,831,1},
  {373,831,1},
  {409,862,1},
  {415,831,1},
  {430,831,1},
  {437,863,1},
  {435,830,1},
  {479,854,1},
  {500,854,1},
  {521,815,1},
  {550,815,1},
  {564,791,1},
  {578,814,1},
  {592,791,1},
  {606,814,1},
  {627,814,1},
  {635,846,1},
  {648,846,1},
  {663,831,1},
  {677,799,1},
  {704,855,1},
  {719,855,1},
  {733,823,1},
  {747,855,1},
  {761,846,1},
  {776,846,1},
  {789,800,1},
  {804,846,1},
  {817,831,1},
  {833,831,1},
  {860,847,1},
  {881,831,1},
  {917,831,1},
  {930,792,1},
  {945,831,1},
  {958,831,1},
  {973,862,1},
};

float *points2Map4Original = (float*) malloc(sizeof(float)*13);
float *points2Map4pun = (float*) malloc(sizeof(float)*13);
float *points24Normalized = (float*) malloc(sizeof(float)*13);

float *points3Map4Original = (float*) malloc(sizeof(float)*11);
float *points3Map4pun = (float*) malloc(sizeof(float)*11);
float *points34Normalized = (float*) malloc(sizeof(float)*11);

float *points4Map4Original = (float*) malloc(sizeof(float)*23);
float *points4Map4pun = (float*) malloc(sizeof(float)*23);
float *points44Normalized = (float*) malloc(sizeof(float)*23);


float points2Map4[13][3] ={
   {11,311,1},
   {29,311,1},
   {42,330,1},
   {56,311,1},
   {64,311,1},
   {99,326,1},
   {112,311,1},
   {146,311,1},
   {131,296,1},
   {80,296,1},
   {63,296,1},
   {30,296,1},
   {11,296,1},
   
};

float points3Map4[11][3]{
  {352,431,1},
  {366,471,1},
  {380,431,1},
  {409,431,1},
  {422,463,1},
  {437,431,1},
  {465,431,1},
  {451,416,1},
  {410,416,1},
  {367,416,1},
  {352,431,1},
};

float points4Map4[23][3]{
  {622,431,1},
  {649,431,1},
  {664,471,1},
  {678,431,1},
  {706,431,1},
  {720,456,1},
  {735,431,1},
  {790,431,1},
  {853,431,1},
  {896,431,1},
  {933,431,1},
  {946,462,1},
  {960,431,1},
  {946,416,1},
  {905,416,1},
  {849,416,1},
  {800,416,1},
  {770,416,1},
  {730,416,1},
  {700,416,1},
  {670,416,1},
  {635,416,1},
  {622,411,1},

};



void DebugPointer(float *ptr, int sizePtr){
  for (int i = 0; i < sizePtr; i++){
    printf("Valor [%f] Memoria [%p]\n",*(ptr+i),(ptr+i));
  }
  printf("----------------\n");
  
}

TEnemy enemi1;

#include "player.cc"
#include "colisiones.cc"
#include "fuel.cc"
#include "gravity.cc"
#include "map.cc"
#include "enemies.cc"
#include "geometries.cc"
#include "interface.cc"