int frameCont = -1;
int animationSelector = 0;
int animatorSelectorMedio = 0;
int scalateFramesCount = 0;
int scalateHorizontalFramesCount = 0;
float *scalateXaux = (float*) malloc(sizeof(float));

//Init ma1 points TODO Quitar y poner los valores a mano en el puntero
void InitMap1Array(){
  for(int i = 0; i<38;++i){
      printf("X[%d] Y[%d]\n",(i*2),(i*2)+1);
    *(pointsMap1pun + (i*2)) = pointsMap1[i][0];
    *(pointsMap1pun + ((i*2) + 1)) = pointsMap1[i][1];
  }
}

void InitMap4Array(){
    for(int i = 0; i<102;++i){
      printf("X[%d] Y[%d]\n",(i*2),(i*2)+1);
    *(pointsMap4pun + (i*2)) = pointsMap4[i][0];
    *(pointsMap4pun + ((i*2) + 1)) = pointsMap4[i][1];
  }
}

void InitMap(float *mapa, float *points,float *original, int size, float Xmax, float Ymax){

    //Normalizado de la matriz 3x1
    for(int i = 0; i <size; i++){
        //Anterior

        // pointsMap1[i][0] = pointsMap1[i][0] / 843.0f;
        // pointsMap1[i][1] = pointsMap1[i][1] / 718.0f;
        // *(pointsNormalized+(i*2)) =  pointsMap1[i][0];
        // *(pointsNormalized+(i*2 + 1)) = pointsMap1[i][1];

        *(mapa+(i*2)) = *(mapa+(i*2)) / Xmax; 
        *(mapa+(i*2 + 1))= *(mapa+(i*2 + 1)) / Ymax; 

        *(points+(i*2)) =  *(mapa+(i*2)) / Xmax;
        *(points+(i*2 + 1)) = *(mapa+(i*2 + 1)) / Ymax;

        //Guardamos los valores originales para futuro resets

        *(original+(i*2)) = *(mapa+(i*2));
        *(original+(i*2 +1)) = *(mapa+(i*2 +1));
    };
    printf("Mapa normalizado X[%f] Y[%f]\n",*points,*(points+1));
    // InitFuelMap1();
    
}

void InitMaps(){
    InitMap1Array();
	InitMap(pointsMap1pun,pointsNormalized,pointsMap1Original,38.0f,843.0f,718.0f);
    InitMap4Array();
    InitMap(pointsMap4pun,points4Normalized,pointsMap4Original,51.0f,973.0f,763.0f);
}

void ScalateMap(float *map,float *pointsNormalized, int size,bool zoom = true){
    // printf("Scalating X[%f] Y[%f]\n",*pointsNormalized,*(pointsNormalized+1));
    for (int i = 0; i <size; i++){
        //Si hay zoom , multiplicamos el valor normalizado por el valor scalate para ir haciendolo más grande
        //Si no hay zoom, dividimos
        //TE HAS QUEDADO AQUI
        //Hay que dejar map como está, que son los puntos normalizados, y lo que tenemos que ampliar es pointsNormalized
        zoom?*(map +(i*2))*=valorScalate:*(map +(i*2))/= valorScalate;
        zoom?*(map +(i*2 +1))*=valorScalate:*(map +(i*2))/= valorScalate;
        *(pointsNormalized+(i*2)) = *(map +(i*2)) + 150;
        *(pointsNormalized+(i*2 + 1)) = *(map +(i*2 +1));

        //zoom?*(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1)) * valorScalate:*(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1))/valorScalate;

        // zoom?*(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1)) * valorScalate:*(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1))/valorScalate;
            
    }
}

void ScalateHorizontalMap(float *map,float *pointsNormalized, int size){
    printf("Scalating X[%f] Y[%f]\n",*pointsNormalized,*(pointsNormalized+1));
    for (int i = 0; i <size; i++){
        //Si hay zoom , multiplicamos el valor normalizado por el valor scalate para ir haciendolo más grande
        //Si no hay zoom, dividimos
        *(map +(i*2))*=valorScalate;
        *(map +(i*2)) -=20;
        *(pointsNormalized+(i*2)) = *(map +(i*2)) + 150;
        //zoom?*(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1)) * valorScalate:*(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1))/valorScalate;
            
    }
}

void ScrollMap(float *points,int size,float scrollSize){
    for (int i = 0; i < size; i++){
        *(points + (i*2)) += -scrollSize;
    }
}

void CheckInputsGeometries(){

    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Up)){
        ScalateMap(pointsMap1pun,pointsNormalized,38);
    }
    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Down)){
        ScalateMap(pointsMap1pun,pointsNormalized,38,false);
    }

    // printf("Raton X[%f], Y[%f]\n",esat::MousePositionX(),esat::MousePositionY());
    if(esat::IsKeyPressed('H')){
        for (int i = 0; i < 38; i++){
            *(pointsNormalized+(i*2)) +=2 ;
        }
    }
    if(esat::IsKeyPressed('F')){
        for (int i = 0; i < 38; i++){
            *(pointsNormalized+(i*2)) -=2 ;
        }
    }
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Backspace)){
        player.nivel = 0;
        scalating = false;
        InitMap1Array();
        InitMaps();
	    // InitMap(pointsMap1pun,pointsNormalized,pointsMap1Original,38.0f,843.0f,718.0f);
        // ResetFuelPoints(pointsFuel1Map1,pointsFuel1Normalized);
    }
}

void CheckFuelObtain(float *points, TFuelNew *Fuel){
    printf("Obtained: %d\n",Fuel->obtained);
    if(*points > player.x-15 && *points< player.x+15 && *(points+1)<player.y+40 && *(points+7)<player.y+40 && *(points+3) > player.y ){
            if(!Fuel->obtained){
                player.fuel += 3000;
                printf("COLISION FUEL\n");
                (Fuel->obtained) = true;
            }
        }
}

void CheckShield(){
    if(esat::IsKeyPressed('S')){
        //Activate fuel
        player.fuel--;
        esat::DrawSetStrokeColor(Verde.r,Verde.g,Verde.b);
        esat::DrawLine(player.x,player.y,player.x-15,player.y+40);
        esat::DrawLine(player.x,player.y,player.x+15,player.y+40);

        //Check colision with fuel

        //Vector que une los puntos de los rayos
        // esat::DrawSetStrokeColor(255,0,0);
        // esat::DrawLine(player.x-15,player.y+40,player.x+15,player.y+40);

        CheckFuelObtain(pointsFuel1Normalized,Fuel1);
        CheckFuelObtain(pointsFuel2Normalized,Fuel2);
        CheckFuelObtain(pointsFuel3Normalized,Fuel3);
        CheckFuelObtain(pointsFuel4Normalized,Fuel4);

    }
}

void CheckGalaxyColision(float x, float y, int level, int margin = 50){
    float modulo;
    xemath::Vector2 nivel;
    nivel = {x - player.x, y-player.y};
    modulo = xemath::Vec2Modulo(nivel);
    if(modulo<margin){
        //Tp to level 
        scalating = true;
        player.nivel = level;
        player.vecDirector.x = 0.0f;
        player.vecDirector.y = -15.0f;
        player.aceleration.x = 0.0f;
        player.aceleration.y = 0.0f;
        player.velocity.x = 0.0f;
        player.velocity.y = 0.0f;
        player.x = CENTROX;
        player.y = CENTROY;
        scalateFramesCount = 0;

        //Set original points
        float *original = nullptr;
        float *nuevo = nullptr;
        int lenght = 0;

        switch (level){
        case 1:
            lenght = 76;    
            original = pointsMap1Original;
            nuevo = pointsMap1pun;
            Fuel1->points = (float*) malloc(sizeof(float)*8);
            Fuel2->points = (float*) malloc(sizeof(float)*8);
            Fuel3->points = (float*) malloc(sizeof(float)*8);
            Fuel4->points = (float*) malloc(sizeof(float)*8);
            InitFuelMap1(pointsFuel1Map1,pointsFuel1Normalized,Fuel1);
            InitFuelMap1(pointsFuel2Map1,pointsFuel2Normalized,Fuel2);
            printf("Fuel2 points X[%f] Y[%f]\n", *(Fuel2->points),*(Fuel2->points+1));
            InitFuelMap1(pointsFuel3Map1,pointsFuel3Normalized,Fuel3);
            InitFuelMap1(pointsFuel4Map1,pointsFuel4Normalized,Fuel4);
            // pointsMap1pun = pointsMap1Original;
        break;
        case 4:
            lenght = 102;
            original = pointsMap1Original;
            nuevo = pointsMap1pun;
            // pointsMap4pun = pointsMap4Original;
            break;
        default:
            break;
        }

        printf("RESET MAP!\n");

        for (int i = 0; i < lenght; i++){
            *(nuevo+(i*2)) = *(original+(i*2));
            *(nuevo+(i*2 +1)) = *(original+(i*2 +1));
        }
        
    }
}

void CheckScrollX(float *points, int size){
    //Check si ha llegado al borde desplazable
    Createcircle(*points, *(points+1),3,Blanco);
    if( (player.x>=ANCHO-100 && player.aceleration.x > 0) || (player.x<=100 && player.aceleration.x <0)){
        if( (player.aceleration.x > 0 && *(points+(size-2))>=ANCHO) || (player.aceleration.x < 0 && *points<0) ){
            scrollHorizontal = true;
            ScrollMap(points, size,player.aceleration.x);
        }else{
             scrollHorizontal = false;
        }

    }else{
        scrollHorizontal = false;
    }
}

void GeometriesActions(){
    frameCont<=1000?frameCont++:frameCont=0;
    TColor color = Blanco;
    int xIzInf;
    int yIzInf;
    int xIzInf2;
    int yIzInf2;
    switch(player.nivel){
        //MAPA MENU
        case 0:
            //Pintar las galaxias
            // X Y Radio Color ExcentricidadX ExcentricidadY Puntos Extravagancia(cuando hay que invertir la Y) Peculiaridad(cuanto hay que restarle a la Y)
            Createcircle(250.0f,150.0f,40.0f,Rojo,1.0f,0.8f,8);
            CheckGalaxyColision(250.0f,150.0f,2);

            //Medio
            if(frameCont % 15 == 0){
                animatorSelectorMedio==7?animatorSelectorMedio=0:animatorSelectorMedio++;
            }
            switch(animatorSelectorMedio){
                case 0:color = Rojo;break;
                case 1:color = MoradoOscuro;break;
                case 2:color = Morado;break;
                case 3:color = Rosa;break;
                case 4:color = Azul;break;
                case 5:color = AzulClaro;break;
                case 6:color = Verde;break;
                case 7:color = Amarillo;break;
            }
            //RESPAWN
            Createcircle(500.0f,400.0f,40.0f,Blanco,1.0f,0.8f,8);
            Createcircle(500.0f,400.0f,40.0f,color,0.8f,0.6f,8);

            Createcircle(800.0f,600.0f,40.0f,Amarillo,1.0f,0.8f,8);
            Createcircle(800.0f,600.0f,40.0f,Azul,1.5f,0.2f,6);
            CheckGalaxyColision(800.0f,600.0f,3);

            //Inferior izquierda
            Createcircle(150.0f,700.0f,20.0f,Rojo,1.0f,0.8f,8);
            CheckGalaxyColision(150.0f,700.0f,4);

            esat::DrawSetStrokeColor(Verde.r,Verde.g,Verde.b);
            xIzInf = 130.0f;
            yIzInf = 680.0f;
            xIzInf2 = 170.0f;
            yIzInf2 = 720.0f;
            if(frameCont%30==0){
                animationSelector==3?animationSelector=0:animationSelector++;
            }

            switch(animationSelector){
                case 0:
                    xIzInf = 130.0f; 
                    yIzInf = 680.0f;
                    xIzInf2 = 170.0f;
                    yIzInf2 = 720.0f;
                break;
                case 1:
                    xIzInf = 150.0f; 
                    yIzInf = 675.0f;
                    xIzInf2 = 150.0f;
                    yIzInf2 = 725.0f;
                break;
                case 2:
                    xIzInf = 170.0f; 
                    yIzInf = 680.0f;
                    xIzInf2 = 130.0f;
                    yIzInf2 = 720.0f;
                break;
                case 3:
                    xIzInf = 120.0f; 
                    yIzInf = 700.0f;
                    xIzInf2 = 180.0f;
                    yIzInf2 = 700.0f;
                break;
                default:
                    xIzInf = 175.0f; 
                    yIzInf = 700.0f;
                    xIzInf2 = 125.0f;
                    yIzInf2 = 700.0f;
                break;
            }
            esat::DrawLine(xIzInf,yIzInf,xIzInf2,yIzInf2);
            // Createcircle(150.0f,700.0f,20.0f,Verde,1.5f,0.2f,8);


            Createcircle(100.0f,350.0f,40.0f,Rojo,1.0f,1.0f,32,8,0.8f);
            CheckGalaxyColision(100.0f,350.0f,5);

            Createcircle(600.0f,200.0f,30.0f,Amarillo,1.0f,1.0f,8,2,0.2f);
            CheckGalaxyColision(600.0f,200.0f,6);


            Createcircle(900.0f,120.0f,25.0f,Rosa,1.0f,1.0f,32,8,0.75f);
            CheckGalaxyColision(900.0f,120.0f,1,40);
            
        break;
        case 1:
            //Pintar mapa1
            CheckInputsGeometries();
           

            if(scalateFramesCount<=133){
                ScalateMap(pointsMap1pun,pointsNormalized,38);
                ScalateFuelNew(Fuel1->points,pointsFuel1Normalized);
                ScalateFuelNew(Fuel2->points,pointsFuel2Normalized);
                ScalateFuelNew(Fuel3->points,pointsFuel3Normalized);
                ScalateFuelNew(Fuel4->points,pointsFuel4Normalized);
                scalateFramesCount++;
                if(scalateFramesCount>=133)scalating = false;
            }

            esat::DrawSetStrokeColor(Verde.r,Verde.g,Verde.b);
            esat::DrawPath(pointsNormalized,38);
            esat::DrawSetStrokeColor(0,0,255);
            // printf("PointsFuel1Normalized X[%f] Y[%f]\n",*pointsFuel1Normalized,*(pointsFuel1Normalized+1));
            if(!(Fuel1->obtained))esat::DrawPath(pointsFuel1Normalized,4);
            if(!(Fuel2->obtained))esat::DrawPath(pointsFuel2Normalized,4);
            if(!(Fuel3->obtained))esat::DrawPath(pointsFuel3Normalized,4);
            if(!(Fuel4->obtained))esat::DrawPath(pointsFuel4Normalized,4);
            CheckShield();
            if(!debug)CheckMapColision(pointsNormalized,38);
            CheckShootColision(pointsNormalized,38);

            if(!scalating)AplyGravity((float) CENTROX,(float) CENTROY);

        break;
        case 4:
            CheckInputsGeometries();
            if(scalateFramesCount<=130){
                //Zoom1 vertical & horizontal
                ScalateMap(pointsMap4pun,points4Normalized,51);
                scalateFramesCount++;
            }else if(scalateHorizontalFramesCount<=20){
                //Zoom2 solo horizontal
                ScalateHorizontalMap(pointsMap4pun,points4Normalized,51);
                scalateHorizontalFramesCount++;
                if(scalateHorizontalFramesCount>=3)scalating = false;
            }
            esat::DrawSetStrokeColor(Verde.r,Verde.g,Verde.b);
            esat::DrawPath(points4Normalized,51);
            CheckMapColision(points4Normalized,51);
            CheckShootColision(points4Normalized,51);
            CheckScrollX(points4Normalized,102);

            //Make gravity
            // player.aceleration.y -= 5;

        break;

        default:
            CheckInputsGeometries();
        break;
    }
}



