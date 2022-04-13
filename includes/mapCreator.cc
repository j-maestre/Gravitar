#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

esat::SpriteHandle sprite;
const int ANCHO = 1024, ALTO = 768, CENTROX = 512, CENTROY = 384 ;
unsigned char fps=60;
double current_time,last_time;

int esat::main(int argc, char **argv) {


	esat::WindowInit(ANCHO,ALTO);
	WindowSetMouseVisibility(true);
	srand(time(NULL));
    float X = 0.0f, Y = 0.0f;
    sprite = esat::SpriteFromFile("assets/map2.png"); 

	// InitMap4();

    esat::DrawSetTextFont("./includes/assets/fonts/texto.ttf");
	
  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {

    	last_time = esat::Time();
    	esat::DrawBegin();
    	esat::DrawClear(0,0,0);

        esat::DrawSprite(sprite,X,Y);

        if(esat::MouseButtonDown(0)){
            printf("(map2.map+1)->x = %.0f.0f;(map2.map+1)->y = %.0f.0f;(map2.map+1)->z = 1.0f;\n",esat::MousePositionX(),esat::MousePositionY());
        }
        


    	esat::DrawEnd();

    	//Control fps
    	do{
    		current_time = esat::Time();
    	}while((current_time-last_time)<=1000.0/fps);
    	esat::WindowFrame();
  }


  esat::WindowDestroy();
  return 0;

}
