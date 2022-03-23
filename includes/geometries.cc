int frameCont = -1;
int animationSelector = 0;
int animatorSelectorMedio = 0;
int scalateFramesCount = 0;



// TMap *map1 = (TMap*) malloc(sizeof(TMap)*10);

// void InitMaps(){
//     map1->x = 213.0f;
//     map1->y = 42.0f;
//     (map1+1)->x = 361.0f;
//     (map1+1)->y = 209.0f;
//     (map1+2)->x = 68.0f;
//     (map1+2)->y = 538.0f;

// }

void InitMap1(){
    //Dividir la matriz por los elementos mas grandes para que los valores esten entre 0-1    
    //843,718,1

    //Normalizado de la matriz 3x1
    for(int i = 0; i <38; i++){
        pointsMap1[i][0] = pointsMap1[i][0] / 843.0f;
        pointsMap1[i][1] = pointsMap1[i][1] / 718.0f;
        // *(pointsNormalized+(i*2)) =  pointsMap1[i][0] / 843.0f;
        // *(pointsNormalized+(i*2 + 1)) = pointsMap1[i][1] / 718.0f;
        *(pointsNormalized+(i*2)) =  pointsMap1[i][0];
        *(pointsNormalized+(i*2 + 1)) = pointsMap1[i][1];
    };
    InitFuelMap1();
}



void ScalateMap(float map[38][3],bool zoom = true){
    for (int i = 0; i < 38; i++){
            
        zoom?map[i][0] = map[i][0] * valorScalate:map[i][0] = map[i][0] / valorScalate;;
        
        // map[i][1] = map[i][1] * valorScalate;

        // map[i][0] = (CENTROX - map[i][0]) * valorScalate + CENTROX;
        // map[i][1] = (CENTROY - map[i][1]) * valorScalate + CENTROY;
        
    //*(pointsNormalized+(i*2)) = (map[i][0] + ( ((CENTROX*valorScalate) / CENTROX) + CENTROX) ) ;
            *(pointsNormalized+(i*2)) = map[i][0] + 150;

            zoom?*(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1)) *valorScalate:*(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1)) /valorScalate;;
            
        // *(pointsNormalized+(i*2)) =(CENTROX - *(pointsNormalized+(i*2)) ) * valorScalate + CENTROX;
        // *(pointsNormalized+(i*2 + 1)) = (CENTROY - *(pointsNormalized+(i*2 + 1)) ) * valorScalate +CENTROY;
    }
    
    
}

void CheckInputsGeometries(){

    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Up)){
        ScalateMap(pointsMap1);
    }
    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Down)){
        ScalateMap(pointsMap1,false);
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

}


void CheckFuelObtain(float *points, TFuel *Fuel){
    if(*points > player.x-15 && *points< player.x+15 && *(points+1)<player.y+40 && *(points+7)<player.y+40 && *(points+3) > player.y ){
            if(!Fuel->obtained){
                player.fuel += 3000;
                printf("COLISION FUEL\n");
                Fuel->obtained = true;
            }
        }
}
void CheckShield(){
    if(esat::IsKeyPressed('S')){
        //Activate fuel
        player.fuel--;
        // xemath::Vector2 aux ={(player.x + player.vecDirector.x)- player.x,(player.y + player.vecDirector.y)- player.y};
        // xemath::Vector2 shield1 = {player.x,player.y,player.x-10,player};
        esat::DrawSetStrokeColor(Verde.r,Verde.g,Verde.b);
        esat::DrawLine(player.x,player.y,player.x-15,player.y+40);
        esat::DrawLine(player.x,player.y,player.x+15,player.y+40);

        //Check colision with fuel

        //Vector que une los puntos de los rayos
        // xemath::Vector2 vector = {(player.x+10 - player.x-10),(player.y+30-player.y+30)};
        esat::DrawSetStrokeColor(255,0,0);
        esat::DrawLine(player.x-15,player.y+40,player.x+15,player.y+40);

        CheckFuelObtain(pointsFuel1Normalized,Fuel1);
        CheckFuelObtain(pointsFuel2Normalized,Fuel2);

    }
}


void GeometriesActions(){
    frameCont<=1000?frameCont++:frameCont=0;
    TColor color = Blanco;
    float modulo;
    xemath::Vector2 nivel1;
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
            Createcircle(500.0f,400.0f,40.0f,Blanco,1.0f,0.8f,8);
            Createcircle(500.0f,400.0f,40.0f,color,0.8f,0.6f,8);

            Createcircle(800.0f,600.0f,40.0f,Amarillo,1.0f,0.8f,8);
            Createcircle(800.0f,600.0f,40.0f,Azul,1.5f,0.2f,6);

            //Inferior izquierda
            Createcircle(150.0f,700.0f,20.0f,Rojo,1.0f,0.8f,8);
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

            Createcircle(600.0f,200.0f,30.0f,Amarillo,1.0f,1.0f,8,2,0.2f);

            Createcircle(900.0f,120.0f,25.0f,Rosa,1.0f,1.0f,32,8,0.75f);
            esat::DrawLine(900.0f,120.0f,player.x,player.y);
            //Check colision
            nivel1 = {900.0f - player.x, 120.0f-player.y};
            modulo = xemath::Vec2Modulo(nivel1);
            if(modulo<40){
                //Tp to level 1
                scalating = true;
                player.nivel = 1;
                player.vecDirector.x = 0.0f;
                player.vecDirector.y = -15.0f;
                player.aceleration.x = 0.0f;
                player.aceleration.y = 0.0f;
                player.velocity.x = 0.0f;
                player.velocity.y = 0.0f;
                player.x = CENTROX;
                player.y = CENTROY;
            }
        break;
        case 1:
            //Pintar mapa1
            CheckInputsGeometries();
           

            if(scalateFramesCount<=134){
                ScalateMap(pointsMap1);
                ScalateFuel(pointsFuel1Map1,pointsFuel1Normalized);
                ScalateFuel(pointsFuel2Map1,pointsFuel2Normalized);
                scalateFramesCount++;
                if(scalateFramesCount>=135)scalating = false;
            }

            esat::DrawSetStrokeColor(Verde.r,Verde.g,Verde.b);
            esat::DrawPath(pointsNormalized,38);
            esat::DrawSetStrokeColor(0,0,255);

            printf("%d",Fuel2->obtained);
            if(Fuel2->obtained){
                printf("FUEL2-> TRUE\n");
            }else{
                printf("FUEL2-> FALSE\n");
            }
            if(!(Fuel1->obtained))esat::DrawPath(pointsFuel1Normalized,4);
            if(!(Fuel2->obtained))esat::DrawPath(pointsFuel2Normalized,4);
            CheckShield();
            CheckMapColision();
            CheckShootColision();   

        break;
    }
}



