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
    sprite = esat::SpriteFromFile("assets/map3.png"); 

	// InitMap4();

    esat::DrawSetTextFont("./includes/assets/fonts/texto.ttf");
	float zoom = 1.0f;
	int counter = 0;
	
  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {

    	last_time = esat::Time();
    	esat::DrawBegin();
    	esat::DrawClear(0,0,0);

        // esat::DrawSprite(sprite,X,Y);
		if(esat::IsKeyPressed('W')){
			zoom+=0.02f;
		}
		if(esat::IsKeyPressed('S')){
			zoom-=0.02f;
		}
		if(esat::IsKeyPressed('D')){
			X+=1.0f;
		}
		if (esat::IsKeyPressed('A')){
			X-= 1.0f;
		}

		esat::DrawSprite(sprite,{X,Y, 0, zoom, zoom, zoom});

        if(esat::MouseButtonDown(0)){
			printf("(map3.map+%d)->x = %.0f.0f;(map3.map+%d)->y = %.0f.0f;(map3.map+%d)->z = 1.0f;\n", counter, esat::MousePositionX(), counter, esat::MousePositionY(), counter);
			counter++;
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