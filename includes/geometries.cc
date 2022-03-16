int frameCont = -1;
int animationSelector = 0;
int animatorSelectorMedio = 0;
float valorScalate = 1.05f;
int scalateFramesCount = 0;
float pointsMap1[38][3] = {
        {74,374,1},
        {307,30,1},
        {382,115,1},
        {306,202,1},
        {382,287,1},
        {305,287,1},
        {229,202,1},
        {153,287,1},
        {229,287,1},
        {76,459,1},
        {152,459,1},
        {76,545,1},
        {229,718,1},
        {306,718,1},
        {382,631,1},
        {306,631,1},
        {230,545,1},
        {383,545,1},
        {613,288,1},
        {689,288,1},
        {614,374,1},
        {689,459,1},
        {766,459,1},
        {690,545,1},
        {460,545,1},
        {537,631,1},
        {690,631,1},
        {843,459,1},
        {768,374,1},
        {690,374,1},
        {766,288,1},
        {690,202,1},
        {536,202,1},
        {460,287,1},
        {383,202,1},
        {536,30,1},
        {620,30,1},
        {843,368,1},
    };


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
}



void ScalateMap(float map[38][3]){
    for (int i = 0; i < 38; i++){
        map[i][0] = map[i][0] * valorScalate;
        // map[i][1] = map[i][1] * valorScalate;

        // map[i][0] = (CENTROX - map[i][0]) * valorScalate + CENTROX;
        // map[i][1] = (CENTROY - map[i][1]) * valorScalate + CENTROY;
        
    //*(pointsNormalized+(i*2)) = (map[i][0] + ( ((CENTROX*valorScalate) / CENTROX) + CENTROX) ) ;
            *(pointsNormalized+(i*2)) = map[i][0];
            *(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1)) *valorScalate;
        // *(pointsNormalized+(i*2)) =(CENTROX - *(pointsNormalized+(i*2)) ) * valorScalate + CENTROX;
        // *(pointsNormalized+(i*2 + 1)) = (CENTROY - *(pointsNormalized+(i*2 + 1)) ) * valorScalate +CENTROY;
    }
    
}

void CheckInputsGeometries(){

    if(esat::IsKeyPressed('Q')){
        printf("inputttt");
        ScalateMap(pointsMap1);
    }
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
                player.nivel = 1;
            }
        break;
        case 1:
            //Pintar mapa1
            CheckInputsGeometries();
           
            esat::DrawSetStrokeColor(Verde.r,Verde.g,Verde.b);

            if(scalateFramesCount<=135){
                ScalateMap(pointsMap1);
                scalateFramesCount++;
            }
    
            esat::DrawSetFillColor(255,255,255);
            esat::DrawPath(pointsNormalized,38);
            CheckMapColision();
            
            

           
            

        break;
    }
}



