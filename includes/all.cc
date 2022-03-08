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
const float ANGLE_ROTATION = xemath::ToRadianes(3);


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
  float velocidad = 0.01f;

};


#include "player.cc"
