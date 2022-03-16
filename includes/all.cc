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
const int ANCHO = 1024, ALTO = 768;
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

struct TPlayer{
  xemath::Vector2 vecDirector = {0.0f,-15.0f};   //Esto es a donde apunta
  xemath::Vector2 vecPunta = {100.0f, 100.0f};
  float x = 100.0f;
  float y = 100.0f;
  xemath::Vector2 aceleration = {0.0f,0.0f};
  xemath::Vector2 velocity = {0.0f,0.0f}; //este depende de la direccion de la nave, cuando pulso w la aceleracion = aceleracion anterior + la nueva
  float velocidad = 0.1f;
  float angle;
  int nivel = 1;

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

TColor Azul = {0,0,180};
TColor AzulClaro = {0,238,255};

TColor Blanco = {255,255,255};
TColor Negro = {0,0,0};

TColor Amarillo = {252,255,0};
TColor Morado = {255,0,243};
TColor MoradoOscuro = {192,0,255};
TColor Rosa = {255,0,154};


#include "player.cc"
#include "geometries.cc"
