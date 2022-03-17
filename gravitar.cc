#include "includes/all.cc"


int esat::main(int argc, char **argv) {


	esat::WindowInit(ANCHO,ALTO);
	WindowSetMouseVisibility(true);
	srand(time(NULL));
	InitMap1();
	InitPlayer();
    esat::DrawSetTextFont("./includes/assets/fonts/texto.ttf");
	
  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {

    	last_time = esat::Time();
    	esat::DrawBegin();
    	esat::DrawClear(0,0,0);
			InterfaceActions();
			if(!intro && !interfaz){
				PlayerActions();
				GeometriesActions();
			}


    	esat::DrawEnd();

    	//Control fps
    	do{
    		current_time = esat::Time();
    	}while((current_time-last_time)<=1000.0/fps);
    	esat::WindowFrame();
  }


  esat::WindowDestroy();
  free(pointsNormalized);

  return 0;

}
