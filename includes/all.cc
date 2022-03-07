#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Ancho -> 256*4
//Alto -> 192*4
const int ANCHO = 1024, ALTO = 768;
unsigned char fps=60;
double current_time,last_time;


struct TColor{
  int r = 255;
  int g = 255;
  int b = 255;
  int a = 0;
};
