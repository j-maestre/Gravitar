#include "includes/all.cc"


int esat::main(int argc, char **argv) {


	esat::WindowInit(ANCHO,ALTO);
	WindowSetMouseVisibility(true);
	srand(time(NULL));
	esat::DrawSetTextFont("./includes/assets/fonts/fuente.ttf");
	
	InitPlayer();
	CreateMaps();
	InitVidasPoints();


	while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)){

    	last_time = esat::Time();
    	esat::DrawBegin();
    	esat::DrawClear(0,0,0);
		printf("GRAVITAR init\n");
		
		InterfaceActions();
		if(!intro && !interfaz){
			PlayerActions();
			GeometriesActions();
		}

		printf("GRAVITAR end\n");
    	esat::DrawEnd();//A veces se rompe aqui

		printf("Despues del draw end\n");
    	//Control fps
    	do{
			// printf("antes del time\n");
    		current_time = esat::Time();//Otras veces se rompe aqui
			// printf("despues del time\n");
    	}while((current_time-last_time)<=1000.0/fps);
    	esat::WindowFrame();
  }


  FreePointers();
  esat::WindowDestroy();
  
  


  return 0;

}
