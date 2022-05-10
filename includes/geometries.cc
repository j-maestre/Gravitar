int frameCont = -1;
int animationSelector = 0;
int animatorSelectorMedio = 0;
int scalateFramesCount = 0;
int scalateHorizontalFramesCount = 0;
float *scalateXaux = (float*) malloc(sizeof(float));
int scalateMatFramesCount = 0;

int bombExplosionFramesCount = 1;
bool bombColorChanger = false;

bool map1Complete = false;
bool map2Complete = false;
bool map5Complete = false;

void DrawHacks(){
    if(debug){
        esat::DrawSetStrokeColor(Amarillo.r,Amarillo.g,Amarillo.b);
        esat::DrawSetFillColor(Amarillo.r,Amarillo.r,Amarillo.r);
        esat::DrawText(10.0f,ALTO-100.0f,"GOD MODE");
    }else{
        printf("na de na");
    }
}

void ScalateHorizontalMap(float *map,float *pointsNormalized, int size, bool smaller = false){
    // printf("Scalating X[%f] Y[%f]\n",*pointsNormalized,*(pointsNormalized+1));
    for (int i = 0; i <size; i++){
        //Si hay zoom , multiplicamos el valor normalizado por el valor scalate para ir haciendolo más grande
        //Si no hay zoom, dividimos
        if(!smaller)*(map +(i*2))*=valorScalate;
        *(map +(i*2)) -=20;
        if(smaller)*(map +(i*2)) -=37;
        *(pointsNormalized+(i*2)) = *(map +(i*2)) + 150;
        //zoom?*(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1)) * valorScalate:*(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1))/valorScalate;
            
    }
}

void ScrollMap(float *points,int size,float scrollSize){
    for (int i = 0; i < size; i++){
        *(points + (i*2)) += -scrollSize;
    }
}

void ReturnMenu(){
    player.nivel = 0;
    scalating = false;
    scalateMatFramesCount = 0;
    InitEnemies();
    player.vecDirector.x = 0.0f;
    player.vecDirector.y = -15.0f;
    player.aceleration.x = 0.0f;
    player.aceleration.y = 0.0f;
    player.velocity.x = 0.0f;
    player.velocity.y = 0.0f;
    player.x = CENTROX;
    player.y = CENTROY;
    map1.escalar = 231.0f;
    map2.escalar = 231.0f;
    map3.escalar = 231.0f;

    map3Bomb.escalar = 231.0f;
    player.timeLeft = 23;
    bombFpsCounter = 0;
    bombShooted = false;
}

void CheckInputsGeometries(){



    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Backspace)){
        ReturnMenu();
    }

    if (esat::IsSpecialKeyDown(esat::kSpecialKey_F1)){
        printf("\n---------\n---------\n---------\nGod Mode Activated\n---------\n---------\n---------\n");
        debug = !debug;

    }
    if (esat::IsSpecialKeyDown(esat::kSpecialKey_F2)){
        printf("---------\n---------\n---------\nKill All Turrets\n---------\n---------\n---------\n");
        switch (player.nivel){
        case 1:
            turret1.vivo = false;
            turret2.vivo = false;
            turret3.vivo = false;
            turret4.vivo = false;
            turret5.vivo = false;
            turret6.vivo = false;
            turret7.vivo = false;
            turret8.vivo = false;
            break;
        case 2:
            turret9.vivo = false;
            turret10.vivo = false;
            turret11.vivo = false;
            turret12.vivo = false;
            turret13.vivo = false;
            turret14.vivo = false;
            turret15.vivo = false;
            turret16.vivo = false;

            
        break;
        default:
            break;
        }
        debug = !debug;
    }
}


void CheckFuelObtain(float *points, TFuelMat *Fuel){
    // printf("Obtained: %d\n",Fuel->obtained);
    if(*points > player.x-15 && *points< player.x+15 &&
     *(points+1)<player.y+40 && *(points+7)<player.y+40 && *(points+3) > player.y ){
            if(!Fuel->obtained){
                player.fuel += 3000;
                // printf("COLISION FUEL\n");
                (Fuel->obtained) = true;
            }
        }
}

void CheckShield(TFuelMat *fuel1,TFuelMat *fuel2,TFuelMat *fuel3,TFuelMat *fuel4){
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

        // float *pointsAux = (float*) malloc(sizeof(float)*8);

        float *pointsAux = fuel1->points;
        CheckFuelObtain(pointsAux,fuel1);
        pointsAux = fuel2->points;
        CheckFuelObtain(pointsAux,fuel2);
        pointsAux = fuel3->points;
        CheckFuelObtain(pointsAux,fuel3);
        pointsAux = fuel4->points;
        CheckFuelObtain(pointsAux, fuel4);
    }
}

void CheckGalaxyColision(float x, float y, int level, int margin = 50){
    if(level==1)Createcircle(x,y,10,Verde);
    float modulo;
    xemath::Vector2 nivel;
    nivel = {x - player.x, y-player.y};
    modulo = xemath::Vec2Modulo(nivel);
    if(modulo<margin){
        printf("Level-> %d", level);

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
        scalateHorizontalFramesCount = 0;

        //Set original points
        // float *original = nullptr;
        // float *nuevo = nullptr;
        // int lenght = 0;

        switch (level){
        case 1:
            if(!map1.normalized){
                NormalizeMap(map1, 91, 928.0f, 739.0f);
                map1.normalized = true;
            }
            player.y = 112.8f;
            player.x = 514.8f;
    
        break;
        case 2:
            if(!map2.normalized){
                NormalizeMap(map2,49, 892.0f, 714.0f);
                map2.normalized = true;
            }
            player.y = 112.8f;
            player.x = 480.8f;
            break;
        case 4:
            // lenght = 102;
            // original = pointsMap1Original;
            // nuevo = pointsMap1pun;
            // pointsMap4pun = pointsMap4Original;
            break;
        case 5:
            if(!map3.normalized){
                printf("Normalizando map3\n");
                NormalizeMap(map3,74, 931.0f, 724.0f);
                NormalizeMap(map3Bomb,map3Bomb.size, 699.0f, 489.0f);
                map3.normalized = true;
            }
            break;
        default:
            break;
        }

        // printf("RESET MAP!\n");

        // for (int i = 0; i < lenght; i++){
        //     *(nuevo+(i*2)) = *(original+(i*2));
        //     *(nuevo+(i*2 +1)) = *(original+(i*2 +1));
        // }
        
    }
}



void CheckScrollX(float *points, int size, float *points2, int size2,float *points3, int size3,float *points4, int size4){
    //Check si ha llegado al borde desplazable
    if((player.x>=ANCHO-100 && player.aceleration.x > 0) || (player.x<=100 && player.aceleration.x <0)){
        if( (player.aceleration.x > 0 && *(points+(size-2))>=ANCHO) || (player.aceleration.x < 0 && *points<0) ){
            scrollHorizontal = true;
            ScrollMap(points, size,player.aceleration.x);
            ScrollMap(points2, size2,player.aceleration.x);
            ScrollMap(points3, size3,player.aceleration.x);
            ScrollMap(points4, size4,player.aceleration.x);
            ApplyShotScroll();
        }else{
             scrollHorizontal = false;
        }

    }else{
        scrollHorizontal = false;
    }
}

void TurretShotController(TTurret *turret, float *points, int index = 0){

    //Disparo a la torreta
    if(turret->vivo){
        ShotTurret(&(*turret), points, index);
        //*Colision disparo del jugador con la torreta
        if(CheckShootColision(points,4,true)){
            turret->vivo = false;
            // printf("\n-------- COLISION CON TURRET %d --------\n",index);
        }

        //*Colision disparo torreta con el mapa
    }
 
}

void CheckGoBack(bool bomb = false){
    if(player.y <= 23.050344f){
        if(bomb){
            map5Complete = true;
        }
        ReturnMenu();
    }
}

void GeometriesActions(){
    CheckInputsGeometries();
    DrawHacks();
    frameCont<=1000?frameCont++:frameCont=0;
    TColor color = Blanco;
    int xIzInf;
    int yIzInf;
    int xIzInf2;
    int yIzInf2;
    switch(player.nivel){
        //MAPA MENU
        case 0:
            // Pintar las galaxias
            //  X Y Radio Color ExcentricidadX ExcentricidadY Puntos Extravagancia(cuando hay que invertir la Y) Peculiaridad(cuanto hay que restarle a la Y)
            if(turret9.vivo || turret10.vivo || turret11.vivo || turret12.vivo || turret13.vivo || turret14.vivo || turret15.vivo || turret16.vivo){
                Createcircle(250.0f, 150.0f, 40.0f, Rojo, 1.0f, 0.8f, 8);
                CheckGalaxyColision(250.0f,150.0f,2);
            }else{
                map2Complete = true;
            }
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

            if(!map5Complete){
                Createcircle(100.0f,350.0f,40.0f,Rojo,1.0f,1.0f,32,8,0.8f);
                CheckGalaxyColision(100.0f,350.0f,5);
            }

            Createcircle(600.0f,200.0f,30.0f,Amarillo,1.0f,1.0f,8,2,0.2f);
            CheckGalaxyColision(600.0f,200.0f,6);

            if(turret1.vivo || turret2.vivo || turret3.vivo || turret4.vivo || turret5.vivo || turret6.vivo || turret7.vivo || turret8.vivo){
                Createcircle(900.0f,120.0f,25.0f,Rosa,1.0f,1.0f,32,8,0.75f);
                CheckGalaxyColision(900.0f,120.0f,1,40);
            }else{
                map1Complete = true;
            }

            //Pintar enemigos
            if(enemi1.canMove)DrawEnemy1(&enemi1);
            MoveEnemy(&enemi1);

            break;
            CheckInputsGeometries();
        //*MATRICES
        case 1: 
            //Pintar mapa1
            CheckInputsGeometries();

            if(scalateMatFramesCount <= 120){
                DrawFigure1(&map1,map1.size);
                scalateMatFramesCount++;
                if(scalateMatFramesCount>=120)scalating = false;
            }else{
                DrawFigure1(&map1,map1.size,false);
                //Llamar a colisiones
                CheckMapColision(points_tmp_map1,map1.size-1);
                CheckShootColision(points_tmp_map1,map1.size-1);
                CheckShield(&fuel1,&fuel2,&fuel3,&fuel4);

                TurretShotController(&turret1, turret1_points,1);
                TurretShotController(&turret2, turret2_points);
                TurretShotController(&turret3, turret3_points);
                TurretShotController(&turret4, turret4_points);
                TurretShotController(&turret5, turret5_points);
                TurretShotController(&turret6, turret6_points);
                TurretShotController(&turret7, turret7_points);
                TurretShotController(&turret8, turret8_points);
            }
            CheckGoBack();

            break;
        case 2: //*MATRICES

            if(scalateMatFramesCount <= 110){
                // esat::Mat3 aux = UpdateBaseFigure(map2);
                DrawFigure2(&map2, 49);
                scalateMatFramesCount++;
                if(scalateMatFramesCount>=109)scalating = false;
            }else{
                // esat::Mat3 aux = UpdateBaseFigure(map2,false);
                DrawFigure2(&map2, 49, false);
                //Llamar a colisiones

                TurretShotController(&turret9, turret1_points, 1);
                TurretShotController(&turret10, turret2_points, 1);
                TurretShotController(&turret11, turret3_points, 1);
                TurretShotController(&turret12, turret4_points, 1);
                TurretShotController(&turret13, turret5_points, 1);
                TurretShotController(&turret14, turret6_points, 1);
                TurretShotController(&turret15, turret7_points, 1);
                TurretShotController(&turret16, turret8_points, 1);

                CheckMapColision(points_tmp_map2,48);
                CheckShootColision(points_tmp_map2,48);

                CheckShield(&fuel5, &fuel6, &fuel7, &fuel8);

                CheckGoBack();
        
             
                
            }
            CheckInputsGeometries();

            break;
        case 4:
            CheckInputsGeometries();
  

        break;
        case 5: //*MATRICES
            if(scalateMatFramesCount <= 100){
                DrawFigure3(&map3,map3.size);
                DrawFigure3(&map3Bomb, map3Bomb.size, true, Morado,true);
                scalateMatFramesCount++;
                if(scalateMatFramesCount>=20)scalating = false;
            }else{
                DrawFigure3(&map3,map3.size,false);

                //Animacion de la bomba
                TColor color = Morado;
                if(bombShooted){
                    bombExplosionFramesCount++;
                    if(bombExplosionFramesCount%(fps/2) == 0){
                        bombColorChanger = !bombColorChanger;
                    }
                    bombColorChanger?color = Rojo:color = Azul;
                    
                }

                if(bombExplosionFramesCount%(fps*TIME_TO_EXPLOSION) == 0){
                    //La bomba ha explotado
                    player.timeLeft = 0;
                } 
                DrawFigure3(&map3Bomb, map3Bomb.size, false, color,true);

                // CheckShootBomb();

                DrawTimeLeft();
                if(player.timeLeft<0){
                    //Explota la bomba
                    player.vidas--;
                    ReturnMenu();
                }

                //Llamar a colisiones
                CheckMapColision(points_tmp_map3,74);
                CheckShootColision(points_tmp_map3,74);

                //Colision con la bomba
                CheckShootColision(points_tmp_map2_bomb,map3Bomb.size-1,false,true);
                //Size de bomb 11

                CheckGoBack(true);
            }
            CheckInputsGeometries();

            break;

        default:
        break;
    }
}



