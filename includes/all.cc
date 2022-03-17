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
const double dPI = 3.141592653589793238462643383279502884197169;
unsigned char fps=60;
double current_time,last_time;
const float ANGLE_ROTATION = 3;

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
  float x = 100.0f;
  float y = 100.0f;
  xemath::Vector2 aceleration = {0.0f,0.0f};
  xemath::Vector2 velocity = {0.0f,0.0f}; //este depende de la direccion de la nave, cuando pulso w la aceleracion = aceleracion anterior + la nueva
  float velocidad = 0.1f;
  float angle;
  int nivel = 1;
  int fuel = 10000;
  int score = 0;
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



#include "player.cc"
#include "colisiones.cc"
#include "geometries.cc"
#include "interface.cc"