// const int map2Size = 48;
float xPrueba = 0.0f;
float YPrueba = 0.0f;



float temporal = 1.0f;
int temporaliNT = 0;

void NormalizeFuel(TFuelMat mapa,float lenght,float sizeX = 1.0f, float sizeY = 1.0f){
    for (int i = 0; i < lenght; i++){
        // (mapa.map + i)->x -= CENTROX;
        // (mapa.map + i)->y -= CENTROY;
        (mapa.map + i)->x /= sizeX;
        (mapa.map + i)->y /= sizeY;
    }
    
}
void NormalizeTurret(TTurret mapa,float lenght,float sizeX = 1.0f, float sizeY = 1.0f){
    for (int i = 0; i < lenght; i++){
        // (mapa.map + i)->x -= CENTROX;
        // (mapa.map + i)->y -= CENTROY;
        (mapa.map + i)->x /= sizeX;
        (mapa.map + i)->y /= sizeY;
    }
    
}

bool figure1pointsCheck = false;
void DrawFigure1(TMap *m, int size, bool scalate = true, TColor color = Verde){
    esat::Vec2 tr_circle[250]; // Size de map1-> 91
    //?---------DEBUG---------
    if (IsSpecialKeyPressed(esat::kSpecialKey_Up)){
        YPrueba--;
    }
    if (IsSpecialKeyPressed(esat::kSpecialKey_Down)){
        YPrueba++;
    }
    if (IsSpecialKeyPressed(esat::kSpecialKey_Right)){
        xPrueba++;
    }
    if (IsSpecialKeyPressed(esat::kSpecialKey_Left)){
        xPrueba--;
    }
    
    if(esat::IsKeyPressed('T'))m->escalar++;
    if(esat::IsKeyPressed('Y'))m->escalar--;

    if(esat::IsKeyPressed('L')){
        for (int i = 0; i < size; i++){
        esat::Mat3 matIdentity = esat::Mat3Identity();
        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(1.1f, 1.0f), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(CENTROX, CENTROY+50), matIdentity);
        esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(m->map+i));
        tr_circle[i] = {tmp.x, tmp.y};
        
        }
    }

    if(esat::IsKeyPressed('P')){
        temporal+=0.01f;
        printf("%f\n", temporal);
    }
    if(esat::IsKeyPressed('O')){
        temporal-=0.01f;
        printf("%f\n",temporal);
    }
    if(esat::IsKeyDown('P')){
        temporaliNT+=1;
    }
    if(esat::IsKeyDown('O')){
        temporaliNT-=1;
    }

    //?---------END DEBUG---------



    if(scalate){
        m->escalar+=5;
    }
    
    //Scalating map
    bool checked = false;
    for (int i = 0; i < size; i++){
        esat::Mat3 matIdentity = esat::Mat3Identity();
        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(m->escalar, m->escalar), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(1.25f, 1.0f), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(CENTROX, CENTROY+50), matIdentity);
        esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(m->map+i));
        Createcircle((m->map + i)->x, (m->map + i)->y,5,Verde);
        tr_circle[i] = {tmp.x, tmp.y};
        
        if(!scalate && !figure1pointsCheck){
            *(points_tmp_map1 + (2 * i)) = tmp.x;
            *(points_tmp_map1 + (2 * i) + 1) = tmp.y;
        }
        checked = true;
    }
    if(!scalate && !figure1pointsCheck){
        figure1pointsCheck=true;
        printf("\n-------Solo 1 VEZ--------\n");
    }
    //Puntos para el puntero de las colisiones
    // if(scalate){
    //     for (int i = 0; i < size; i++){
    //         *(points_tmp_map1 + (2 * i)) = tr_circle[i].x;
    //         *(points_tmp_map1 + (2 * i) + 1) = tr_circle[i].y;
    //     }
    // }

    DrawTurretsMap1(scalate,tr_circle);
    DrawFuelMap1(scalate, tr_circle);

    esat::DrawSetStrokeColor(color.r, color.g, color.b);
    esat::DrawPath(&tr_circle[0].x,size);
    
}
bool figure2pointsCheck = false;
void DrawFigure2(TMap *m, int size, bool scalate = true, TColor color = Verde){
    esat::Vec2 tr_circle[250];

    if(scalate){
        m->escalar+=5;
        figure2pointsCheck = false;
    }

    
    //Scalating map
    for (int i = 0; i < size; i++){
        esat::Mat3 matIdentity = esat::Mat3Identity();
        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(m->escalar+1.50f, m->escalar), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(CENTROX, CENTROY+50), matIdentity);
        esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(m->map+i));
        tr_circle[i] = {tmp.x, tmp.y};

        //Comprobacion de errores
        if((m->map + i)->x > 10000.0f || (m->map + i)->x < -10000.0f || (m->map + i)->y > 10000.0f || (m->map + i)->y < -10000.0f || (m->map + i)->z > 10000.0f || (m->map + i)->z < -10000.0f){
            printf("Mapvalues X->%f Y->%f Z->%f\n", (m->map + i)->x, (m->map + i)->y, (m->map + i)->z);
        }
        if(!scalate && !figure2pointsCheck){
            *(points_tmp_map2 + (2 * i)) = tmp.x;
            *(points_tmp_map2 + (2 * i + 1)) = tmp.y;
        }
    }
    if(!scalate && !figure2pointsCheck){
        figure2pointsCheck=true;
        printf("\n-------Solo 1 VEZ map2--------\n");
    }

    //Puntos para el puntero de las colisiones
    // if(scalate && m->escalar > 400){
    // printf("-------------------Size-> %d\n",size);
    // if(m->escalar > 400){
    //     for (int i = 0; i < size; i++){
    //         *(points_tmp_map2 + 2 * i) = tr_circle[i].x;
    //         *(points_tmp_map2 + 2 * i + 1) = tr_circle[i].y;
    //     }
    // }

    printf("Antes de Draw Turrets\n");
    DrawTurretsMap2(scalate,tr_circle);
    printf("Despues de Draw Turrets\n");
    printf("Antes de Draw Fuel\n");
    DrawFuelMap2(scalate, tr_circle);
    printf("Despues de Draw Fuel\n");

    printf("Antes de Draw Map\n");
    esat::DrawSetStrokeColor(color.r, color.g, color.b);
    esat::DrawPath(&tr_circle[0].x,size);
    printf("Despues de Draw Map\n");
    printf("---TODO OK EN MAP---\n");
    //Esto está bien, llega hasta el final
    
}

bool figure3pointsCheck = false;
bool figure3BombapointsCheck = false;
//Draw Map Bomba
void DrawFigure3(TMap *m, int size, bool scalate = true, TColor color = Verde){

    // printf("Escalar-> %f\n",m->escalar);
    if(scalate){
        m->escalar+=5;
    }

    esat::Vec2 tr_circle[200];

    for (int i = 0; i < size; i++){
         // Scalar cada mat3
        esat::Mat3 matIdentity = esat::Mat3Identity();
        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(m->escalar, m->escalar), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(CENTROX, CENTROY), matIdentity);
        esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(m->map+i) );

        tr_circle[i] = {tmp.x, tmp.y};

        // Createcircle(tmp.x,tmp.y,7);

        //Mapa
        if(!scalate && !figure3pointsCheck){
            *(points_tmp_map3 + (2 * i)) = tmp.x;
            *(points_tmp_map3 + (2 * i + 1)) = tmp.y;
        }
        
    }

    if(!scalate && !figure3pointsCheck){
        figure3pointsCheck=true;
        printf("\n-------Solo 1 VEZ MAPA--------\n");
    }

    esat::DrawSetStrokeColor(color.r, color.g, color.b);
    // esat::DrawSetFillColor(0,0,0);
    esat::DrawPath(&tr_circle[0].x,size-1);
 
}

void DrawFigure3Bomba(TMap *m, int size, TColor color = Verde, bool scalate = true){
    //escalar tiene que llegar a 731
    // printf("Size de la bomba-> %d\n",size);

    if(scalate){
        m->escalar+=5;
    }


    esat::Vec2 tr_circle_bomba[200];
    for (int i = 0; i < size; i++){
        // Scalar cada mat3
        esat::Mat3 matIdentity = esat::Mat3Identity();
        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(m->escalar, m->escalar), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(CENTROX, CENTROY), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(CENTROX-402.0f, CENTROY - 214.0f), matIdentity);
        esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(m->map+i) );

        tr_circle_bomba[i] = {tmp.x, tmp.y};
    }

    //Bomba
    // if(!scalate && !figure3BombapointsCheck){
    //     for (int i = 0; i < size; i++){
    //             *(points_tmp_map2_bomb + 2 * i) = tr_circle_bomba[i].x;
    //             *(points_tmp_map2_bomb + 2 * i + 1) = tr_circle_bomba[i].y;
    //     }
    // }
    

    if(!scalate && !figure3BombapointsCheck){
        figure3BombapointsCheck=true;
        printf("\n-------Solo 1 VEZ Bomba--------\n");
    }
    // printf("debug 3\n");

    esat::DrawSetStrokeColor(color.r, color.g, color.b);
    esat::DrawPath(&tr_circle_bomba[0].x,size);
    // printf("debug 5\n");
    printf("-----DRAW TODO OK-----\n");
}

void DrawLogo(TMap *m, int size, bool scalate,int iteration1 = 0,int iteration2 = 0){
    if(scalate){
        m->escalar+=2;
    }

    esat::Vec2 tr_circle[200];

    for (int i = 0; i < size; i++){
        esat::Mat3 matIdentity = esat::Mat3Identity();
        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(m->escalar+150.0f, m->escalar-50.0f), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(CENTROX+90, CENTROY), matIdentity);
        esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(m->map+i) );
        tr_circle[i] = {tmp.x, tmp.y};
        esat::DrawSetStrokeColor(Rojo.r, Rojo.g, Rojo.b);
        if(i<=1 || iteration1 == i || iteration2 == i)esat::DrawLine(CENTROX-50,CENTROY,tmp.x,tmp.y);
        
        // esat::DrawLine(CENTROX,CENTROY,(logoG.map+1)->x,(logoG.map+1)->y);
    }
    esat::DrawSetStrokeColor(Azul.r, Azul.g, Azul.b);
    esat::DrawSetFillColor(0, 0, 0,0);
    esat::DrawSolidPath(&tr_circle[0].x,size);

}

int bombFpsCounter = 0;

void DrawTimeLeft(){
    esat::DrawSetStrokeColor(0,0,255);
    esat::DrawSetFillColor(0,0,255);
    esat::DrawText(246.0f,397.0f,"ESCAPE TIME");
    // esat::DrawText(318.0f,560.0f,"SHOOT REACTOR");
    printf("Despues de pintar shoot reactor\n");
    
    bombFpsCounter++;
    if(bombFpsCounter%fps == 0){
        player.timeLeft--;
    }

    char *aux = (char*) malloc(sizeof(char)*4);
    itoa(player.timeLeft,aux,10);
    *(aux+strlen(aux)) = '\0';
    printf("Antes de pintar\n");
    esat::DrawText(246.0f, 457.0f, aux);//PETA AQUIII
    printf("Despues de pintar\n");

 


    // printf("Draw time debug 7\n");
    free(aux);
    printf("DrawTime OK\n");

}



esat::Mat3 UpdateBaseFigure(TMap mapa, bool scalate = true){
    //Con esto escalo y traslado al centro
    if(scalate)mapa.escalar +=0.02f;
    esat::Mat3 m = esat::Mat3Identity();
    m = esat::Mat3Multiply(esat::Mat3Scale(mapa.escalar,mapa.escalar),m);
    // m = esat::Mat3Multiply(esat::Mat3Rotate(g_angle),m);
    m = esat::Mat3Multiply(esat::Mat3Translate(CENTROX,CENTROY),m);
    // m = esat::Mat3Multiply(esat::Mat3Translate((float) esat::MousePositionX(),(float) esat::MousePositionY()),m);
    return m;
}

//**************** Map2 points **************** 
TMap map1;
TMap map2;
TMap map3;
TMap map4;
TMap map3Bomb;
TMap logoG;
TMap logoR;
TMap logoA;
TMap logoV;
TMap logoI;
TMap logoT;
TMap logoA2;
TMap logoR2;

void InitTurret(TTurret *turret){
    turret->map = (esat::Vec3 *)malloc(sizeof(esat::Vec3) * 8);
    turret->points = (float *)malloc(sizeof(float) * 16);
    turret->vivo = true;
    turret->disparos = (TDisparo *)malloc(sizeof(TDisparo) * 4);
    (turret->disparos)->disparando = false;
    (turret->disparos + 1)->disparando = false;
    (turret->disparos + 2)->disparando = false;
    (turret->disparos + 3)->disparando = false;

    (turret->map + 0)->x = 110.0f;
    (turret->map + 0)->y = 216.0f;
    (turret->map + 0)->z = 1.0f;
    (turret->map + 1)->x = 124.0f;
    (turret->map + 1)->y = 217.0f;
    (turret->map + 1)->z = 1.0f;
    (turret->map + 2)->x = 141.0f;
    (turret->map + 2)->y = 199.0f;
    (turret->map + 2)->z = 1.0f;
    (turret->map + 3)->x = 141.0f;
    (turret->map + 3)->y = 181.0f;
    (turret->map + 3)->z = 1.0f;
    (turret->map + 4)->x = 129.0f;
    (turret->map + 4)->y = 214.0f;
    (turret->map + 4)->z = 1.0f;
    (turret->map + 5)->x = 138.0f;
    (turret->map + 5)->y = 205.0f;
    (turret->map + 5)->z = 1.0f;
    (turret->map + 6)->x = 146.0f;
    (turret->map + 6)->y = 213.0f;
    (turret->map + 6)->z = 1.0f;
    (turret->map + 7)->x = 137.0f;
    (turret->map + 7)->y = 222.0f;
    (turret->map + 7)->z = 1.0f;

    NormalizeTurret(*turret, 8, 146.0f, 222.0f);
}


void CreateMaps(){

    //Map1
    InitTurret(&turret1);
    InitTurret(&turret2);
    InitTurret(&turret3);
    InitTurret(&turret4);
    InitTurret(&turret5);
    InitTurret(&turret6);
    InitTurret(&turret7);
    InitTurret(&turret8);
    
    //Map2
    InitTurret(&turret9);
    InitTurret(&turret10);
    InitTurret(&turret11);
    InitTurret(&turret12);
    InitTurret(&turret13);
    InitTurret(&turret14);
    InitTurret(&turret15);
    InitTurret(&turret16);

    logoG.map = nullptr;
    logoG.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*12);
    logoG.size = 12;
    logoG.escalar = 0.0f;

    logoR.map = nullptr;
    logoR.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*15);
    logoR.size = 15;
    logoR.escalar = 0.0f;
    
    logoA.map = nullptr;
    logoA.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*12);
    logoA.size = 12;
    logoA.escalar = 0.0f;
    
    logoV.map = nullptr;
    logoV.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*11);
    logoV.size = 11;
    logoV.escalar = 0.0f;
    
    logoI.map = nullptr;
    logoI.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*4);
    logoI.size = 4;
    logoI.escalar = 0.0f;
    
    logoT.map = nullptr;
    logoT.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*8);
    logoT.size = 8;
    logoT.escalar = 0.0f;
    
    logoA2.map = nullptr;
    logoA2.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*12);
    logoA2.size = 12;
    logoA2.escalar = 0.0f;
    
    logoR2.map = nullptr;
    logoR2.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*14);
    logoR2.size = 14;
    logoR2.escalar = 0.0f;

    (logoG.map+0)->x = 284.0f;(logoG.map+0)->y = 192.0f;(logoG.map+0)->z = 1.0f;
    (logoG.map+1)->x = 193.0f;(logoG.map+1)->y = 210.0f;(logoG.map+1)->z = 1.0f;
    (logoG.map+2)->x = 263.0f;(logoG.map+2)->y = 86.0f;(logoG.map+2)->z = 1.0f;
    (logoG.map+3)->x = 331.0f;(logoG.map+3)->y = 75.0f;(logoG.map+3)->z = 1.0f;
    (logoG.map+4)->x = 317.0f;(logoG.map+4)->y = 98.0f;(logoG.map+4)->z = 1.0f;
    (logoG.map+5)->x = 278.0f;(logoG.map+5)->y = 105.0f;(logoG.map+5)->z = 1.0f;
    (logoG.map+6)->x = 241.0f;(logoG.map+6)->y = 163.0f;(logoG.map+6)->z = 1.0f;
    (logoG.map+7)->x = 277.0f;(logoG.map+7)->y = 156.0f;(logoG.map+7)->z = 1.0f;
    (logoG.map+8)->x = 284.0f;(logoG.map+8)->y = 140.0f;(logoG.map+8)->z = 1.0f;
    (logoG.map+9)->x = 265.0f;(logoG.map+9)->y = 146.0f;(logoG.map+9)->z = 1.0f;
    (logoG.map+10)->x = 285.0f;(logoG.map+10)->y = 118.0f;(logoG.map+10)->z = 1.0f;
    (logoG.map+11)->x = 315.0f;(logoG.map+11)->y = 112.0f;(logoG.map+11)->z = 1.0f;

    (logoR.map+0)->x = 354.0f;(logoR.map+0)->y = 180.0f;(logoR.map+0)->z = 1.0f;
    (logoR.map+1)->x = 328.0f;(logoR.map+1)->y = 186.0f;(logoR.map+1)->z = 1.0f;
    (logoR.map+2)->x = 338.0f;(logoR.map+2)->y = 143.0f;(logoR.map+2)->z = 1.0f;
    (logoR.map+3)->x = 329.0f;(logoR.map+3)->y = 140.0f;(logoR.map+3)->z = 1.0f;
    (logoR.map+4)->x = 330.0f;(logoR.map+4)->y = 121.0f;(logoR.map+4)->z = 1.0f;
    (logoR.map+5)->x = 346.0f;(logoR.map+5)->y = 120.0f;(logoR.map+5)->z = 1.0f;
    (logoR.map+6)->x = 328.0f;(logoR.map+6)->y = 108.0f;(logoR.map+6)->z = 1.0f;
    (logoR.map+7)->x = 299.0f;(logoR.map+7)->y = 192.0f;(logoR.map+7)->z = 1.0f;
    (logoR.map+8)->x = 272.0f;(logoR.map+8)->y = 199.0f;(logoR.map+8)->z = 1.0f;
    (logoR.map+9)->x = 311.0f;(logoR.map+9)->y = 85.0f;(logoR.map+9)->z = 1.0f;
    (logoR.map+10)->x = 338.0f;(logoR.map+10)->y = 80.0f;(logoR.map+10)->z = 1.0f;
    (logoR.map+11)->x = 373.0f;(logoR.map+11)->y = 107.0f;(logoR.map+11)->z = 1.0f;
    (logoR.map+12)->x = 367.0f;(logoR.map+12)->y = 129.0f;(logoR.map+12)->z = 1.0f;
    (logoR.map+13)->x = 360.0f;(logoR.map+13)->y = 135.0f;(logoR.map+13)->z = 1.0f;
    (logoR.map+14)->x = 368.0f;(logoR.map+14)->y = 141.0f;(logoR.map+14)->z = 1.0f;

    (logoA.map+0)->x = 418.0f;(logoA.map+0)->y = 189.0f;(logoA.map+0)->z = 1.0f;
    (logoA.map+1)->x = 394.0f;(logoA.map+1)->y = 189.0f;(logoA.map+1)->z = 1.0f;
    (logoA.map+2)->x = 405.0f;(logoA.map+2)->y = 116.0f;(logoA.map+2)->z = 1.0f;
    (logoA.map+3)->x = 392.0f;(logoA.map+3)->y = 124.0f;(logoA.map+3)->z = 1.0f;
    (logoA.map+4)->x = 398.0f;(logoA.map+4)->y = 124.0f;(logoA.map+4)->z = 1.0f;
    (logoA.map+5)->x = 394.0f;(logoA.map+5)->y = 144.0f;(logoA.map+5)->z = 1.0f;
    (logoA.map+6)->x = 378.0f;(logoA.map+6)->y = 144.0f;(logoA.map+6)->z = 1.0f;
    (logoA.map+7)->x = 371.0f;(logoA.map+7)->y = 188.0f;(logoA.map+7)->z = 1.0f;
    (logoA.map+8)->x = 349.0f;(logoA.map+8)->y = 188.0f;(logoA.map+8)->z = 1.0f;
    (logoA.map+9)->x = 368.0f;(logoA.map+9)->y = 121.0f;(logoA.map+9)->z = 1.0f;
    (logoA.map+10)->x = 398.0f;(logoA.map+10)->y = 95.0f;(logoA.map+10)->z = 1.0f;
    (logoA.map+11)->x = 431.0f;(logoA.map+11)->y = 88.0f;(logoA.map+11)->z = 1.0f;

    (logoV.map+0)->x = 490.0f;(logoV.map+0)->y = 202.0f;(logoV.map+0)->z = 1.0f;
    (logoV.map+1)->x = 465.0f;(logoV.map+1)->y = 201.0f;(logoV.map+1)->z = 1.0f;
    (logoV.map+2)->x = 441.0f;(logoV.map+2)->y = 163.0f;(logoV.map+2)->z = 1.0f;
    (logoV.map+3)->x = 446.0f;(logoV.map+3)->y = 95.0f;(logoV.map+3)->z = 1.0f;
    (logoV.map+4)->x = 470.0f;(logoV.map+4)->y = 96.0f;(logoV.map+4)->z = 1.0f;
    (logoV.map+5)->x = 462.0f;(logoV.map+5)->y = 140.0f;(logoV.map+5)->z = 1.0f;
    (logoV.map+6)->x = 476.0f;(logoV.map+6)->y = 161.0f;(logoV.map+6)->z = 1.0f;
    (logoV.map+7)->x = 491.0f;(logoV.map+7)->y = 141.0f;(logoV.map+7)->z = 1.0f;
    (logoV.map+8)->x = 485.0f;(logoV.map+8)->y = 97.0f;(logoV.map+8)->z = 1.0f;
    (logoV.map+9)->x = 503.0f;(logoV.map+9)->y = 96.0f;(logoV.map+9)->z = 1.0f;
    (logoV.map+10)->x = 510.0f;(logoV.map+10)->y = 161.0f;(logoV.map+10)->z = 1.0f;

    (logoI.map+0)->x = 561.0f;(logoI.map+0)->y = 189.0f;(logoI.map+0)->z = 1.0f;
    (logoI.map+1)->x = 536.0f;(logoI.map+1)->y = 188.0f;(logoI.map+1)->z = 1.0f;
    (logoI.map+2)->x = 527.0f;(logoI.map+2)->y = 91.0f;(logoI.map+2)->z = 1.0f;
    (logoI.map+3)->x = 554.0f;(logoI.map+3)->y = 91.0f;(logoI.map+3)->z = 1.0f;

    (logoT.map+0)->x = 643.0f;(logoT.map+0)->y = 198.0f;(logoT.map+0)->z = 1.0f;
    (logoT.map+1)->x = 615.0f;(logoT.map+1)->y = 196.0f;(logoT.map+1)->z = 1.0f;
    (logoT.map+2)->x = 599.0f;(logoT.map+2)->y = 107.0f;(logoT.map+2)->z = 1.0f;
    (logoT.map+3)->x = 588.0f;(logoT.map+3)->y = 107.0f;(logoT.map+3)->z = 1.0f;
    (logoT.map+4)->x = 580.0f;(logoT.map+4)->y = 85.0f;(logoT.map+4)->z = 1.0f;
    (logoT.map+5)->x = 644.0f;(logoT.map+5)->y = 91.0f;(logoT.map+5)->z = 1.0f;
    (logoT.map+6)->x = 647.0f;(logoT.map+6)->y = 112.0f;(logoT.map+6)->z = 1.0f;
    (logoT.map+7)->x = 639.0f;(logoT.map+7)->y = 108.0f;(logoT.map+7)->z = 1.0f;

    (logoA2.map+0)->x = 765.0f;(logoA2.map+0)->y = 202.0f;(logoA2.map+0)->z = 1.0f;
    (logoA2.map+1)->x = 739.0f;(logoA2.map+1)->y = 194.0f;(logoA2.map+1)->z = 1.0f;
    (logoA2.map+2)->x = 714.0f;(logoA2.map+2)->y = 111.0f;(logoA2.map+2)->z = 1.0f;
    (logoA2.map+3)->x = 700.0f;(logoA2.map+3)->y = 122.0f;(logoA2.map+3)->z = 1.0f;
    (logoA2.map+4)->x = 703.0f;(logoA2.map+4)->y = 122.0f;(logoA2.map+4)->z = 1.0f;
    (logoA2.map+5)->x = 715.0f;(logoA2.map+5)->y = 144.0f;(logoA2.map+5)->z = 1.0f;
    (logoA2.map+6)->x = 699.0f;(logoA2.map+6)->y = 144.0f;(logoA2.map+6)->z = 1.0f;
    (logoA2.map+7)->x = 712.0f;(logoA2.map+7)->y = 190.0f;(logoA2.map+7)->z = 1.0f;
    (logoA2.map+8)->x = 684.0f;(logoA2.map+8)->y = 183.0f;(logoA2.map+8)->z = 1.0f;
    (logoA2.map+9)->x = 670.0f;(logoA2.map+9)->y = 117.0f;(logoA2.map+9)->z = 1.0f;
    (logoA2.map+10)->x = 707.0f;(logoA2.map+10)->y = 83.0f;(logoA2.map+10)->z = 1.0f;
    (logoA2.map+11)->x = 725.0f;(logoA2.map+11)->y = 88.0f;(logoA2.map+11)->z = 1.0f;

    (logoR2.map+0)->x = 913.0f;(logoR2.map+0)->y = 215.0f;(logoR2.map+0)->z = 1.0f;
    (logoR2.map+1)->x = 884.0f;(logoR2.map+1)->y = 209.0f;(logoR2.map+1)->z = 1.0f;
    (logoR2.map+2)->x = 852.0f;(logoR2.map+2)->y = 149.0f;(logoR2.map+2)->z = 1.0f;
    (logoR2.map+3)->x = 829.0f;(logoR2.map+3)->y = 144.0f;(logoR2.map+3)->z = 1.0f;
    (logoR2.map+4)->x = 820.0f;(logoR2.map+4)->y = 127.0f;(logoR2.map+4)->z = 1.0f;
    (logoR2.map+5)->x = 828.0f;(logoR2.map+5)->y = 124.0f;(logoR2.map+5)->z = 1.0f;
    (logoR2.map+6)->x = 811.0f;(logoR2.map+6)->y = 109.0f;(logoR2.map+6)->z = 1.0f;
    (logoR2.map+7)->x = 849.0f;(logoR2.map+7)->y = 202.0f;(logoR2.map+7)->z = 1.0f;
    (logoR2.map+8)->x = 822.0f;(logoR2.map+8)->y = 196.0f;(logoR2.map+8)->z = 1.0f;
    (logoR2.map+9)->x = 774.0f;(logoR2.map+9)->y = 78.0f;(logoR2.map+9)->z = 1.0f;
    (logoR2.map+10)->x = 819.0f;(logoR2.map+10)->y = 83.0f;(logoR2.map+10)->z = 1.0f;
    (logoR2.map+11)->x = 860.0f;(logoR2.map+11)->y = 116.0f;(logoR2.map+11)->z = 1.0f;
    (logoR2.map+12)->x = 874.0f;(logoR2.map+12)->y = 135.0f;(logoR2.map+12)->z = 1.0f;
    (logoR2.map+13)->x = 867.0f;(logoR2.map+13)->y = 137.0f;(logoR2.map+13)->z = 1.0f;

    //Map1
    map1.map = nullptr;
    map1.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*91);
    map1.size = 91;
    //Fuel
    fuel1.map = nullptr;
    fuel1.map = (esat::Vec3*) malloc(sizeof(esat::Vec3) * 4);
    fuel1.size = 4;

    //Map1 fuels
    fuel1.points = (float*) malloc(sizeof(float)*8);
    fuel2.points = (float*) malloc(sizeof(float)*8);
    fuel3.points = (float*) malloc(sizeof(float)*8);
    fuel4.points = (float*) malloc(sizeof(float)*8);

    fuel1.obtained = false;
    fuel2.obtained = false;
    fuel3.obtained = false;
    fuel4.obtained = false;

    map1.normalized = false;
    map2.normalized = false;
    map3.normalized = false;
    map4.normalized = false;

    

    // fuel2.map = nullptr;
    // fuel2.map = (esat::Vec3 *)malloc(sizeof(esat::Vec3) * 4);

    (fuel1.map+0)->x = 20.0f;(fuel1.map+0)->y = 20.0f;(fuel1.map+0)->z = 1.0f;
    (fuel1.map+1)->x = 20.0f;(fuel1.map+1)->y = 40.0f;(fuel1.map+1)->z = 1.0f;
    (fuel1.map+2)->x = 40.0f;(fuel1.map+2)->y = 40.0f;(fuel1.map+2)->z = 1.0f;
    (fuel1.map+3)->x = 40.0f;(fuel1.map+3)->y = 20.0f;(fuel1.map+3)->z = 1.0f;

    NormalizeFuel(fuel1, 4, 40, 40);

    (map1.map+0)->x = 149.0f;(map1.map+0)->y = 391.0f;(map1.map+0)->z = 1.0f;
    (map1.map+1)->x = 168.0f;(map1.map+1)->y = 348.0f;(map1.map+1)->z = 1.0f;
    (map1.map+2)->x = 191.0f;(map1.map+2)->y = 299.0f;(map1.map+2)->z = 1.0f;
    (map1.map+3)->x = 212.0f;(map1.map+3)->y = 252.0f;(map1.map+3)->z = 1.0f;
    (map1.map+4)->x = 236.0f;(map1.map+4)->y = 197.0f;(map1.map+4)->z = 1.0f;
    (map1.map+5)->x = 260.0f;(map1.map+5)->y = 145.0f;(map1.map+5)->z = 1.0f;
    (map1.map+6)->x = 279.0f;(map1.map+6)->y = 101.0f;(map1.map+6)->z = 1.0f;
    (map1.map+7)->x = 306.0f;(map1.map+7)->y = 43.0f;(map1.map+7)->z = 1.0f;
    (map1.map+8)->x = 384.0f;(map1.map+8)->y = 43.0f;(map1.map+8)->z = 1.0f;
    (map1.map+9)->x = 417.0f;(map1.map+9)->y = 79.0f;(map1.map+9)->z = 1.0f;
    (map1.map+10)->x = 461.0f;(map1.map+10)->y = 129.0f;(map1.map+10)->z = 1.0f;
    (map1.map+11)->x = 424.0f;(map1.map+11)->y = 170.0f;(map1.map+11)->z = 1.0f;
    (map1.map+12)->x = 383.0f;(map1.map+12)->y = 216.0f;(map1.map+12)->z = 1.0f;
    (map1.map+13)->x = 418.0f;(map1.map+13)->y = 255.0f;(map1.map+13)->z = 1.0f;
    (map1.map+14)->x = 460.0f;(map1.map+14)->y = 303.0f;(map1.map+14)->z = 1.0f;
    (map1.map+15)->x = 383.0f;(map1.map+15)->y = 303.0f;(map1.map+15)->z = 1.0f;
    (map1.map+16)->x = 349.0f;(map1.map+16)->y = 265.0f;(map1.map+16)->z = 1.0f;
    (map1.map+17)->x = 305.0f;(map1.map+17)->y = 216.0f;(map1.map+17)->z = 1.0f;
    (map1.map+18)->x = 270.0f;(map1.map+18)->y = 255.0f;(map1.map+18)->z = 1.0f;
    (map1.map+19)->x = 229.0f;(map1.map+19)->y = 303.0f;(map1.map+19)->z = 1.0f;
    (map1.map+20)->x = 305.0f;(map1.map+20)->y = 303.0f;(map1.map+20)->z = 1.0f;
    (map1.map+21)->x = 272.0f;(map1.map+21)->y = 341.0f;(map1.map+21)->z = 1.0f;
    (map1.map+22)->x = 231.0f;(map1.map+22)->y = 386.0f;(map1.map+22)->z = 1.0f;
    (map1.map+23)->x = 191.0f;(map1.map+23)->y = 431.0f;(map1.map+23)->z = 1.0f;
    (map1.map+24)->x = 151.0f;(map1.map+24)->y = 478.0f;(map1.map+24)->z = 1.0f;
    (map1.map+25)->x = 228.0f;(map1.map+25)->y = 478.0f;(map1.map+25)->z = 1.0f;
    (map1.map+26)->x = 188.0f;(map1.map+26)->y = 522.0f;(map1.map+26)->z = 1.0f;
    (map1.map+27)->x = 151.0f;(map1.map+27)->y = 564.0f;(map1.map+27)->z = 1.0f;
    (map1.map+28)->x = 217.0f;(map1.map+28)->y = 639.0f;(map1.map+28)->z = 1.0f;
    (map1.map+29)->x = 261.0f;(map1.map+29)->y = 688.0f;(map1.map+29)->z = 1.0f;
    (map1.map+30)->x = 306.0f;(map1.map+30)->y = 739.0f;(map1.map+30)->z = 1.0f;
    (map1.map+31)->x = 384.0f;(map1.map+31)->y = 739.0f;(map1.map+31)->z = 1.0f;
    (map1.map+32)->x = 427.0f;(map1.map+32)->y = 689.0f;(map1.map+32)->z = 1.0f;
    (map1.map+33)->x = 461.0f;(map1.map+33)->y = 652.0f;(map1.map+33)->z = 1.0f;
    (map1.map+34)->x = 384.0f;(map1.map+34)->y = 651.0f;(map1.map+34)->z = 1.0f;
    (map1.map+35)->x = 348.0f;(map1.map+35)->y = 611.0f;(map1.map+35)->z = 1.0f;
    (map1.map+36)->x = 306.0f;(map1.map+36)->y = 565.0f;(map1.map+36)->z = 1.0f;
    (map1.map+37)->x = 383.0f;(map1.map+37)->y = 565.0f;(map1.map+37)->z = 1.0f;
    (map1.map+38)->x = 462.0f;(map1.map+38)->y = 565.0f;(map1.map+38)->z = 1.0f;
    (map1.map+39)->x = 506.0f;(map1.map+39)->y = 513.0f;(map1.map+39)->z = 1.0f;
    (map1.map+40)->x = 544.0f;(map1.map+40)->y = 472.0f;(map1.map+40)->z = 1.0f;
    (map1.map+41)->x = 586.0f;(map1.map+41)->y = 424.0f;(map1.map+41)->z = 1.0f;
    (map1.map+42)->x = 619.0f;(map1.map+42)->y = 389.0f;(map1.map+42)->z = 1.0f;
    (map1.map+43)->x = 654.0f;(map1.map+43)->y = 350.0f;(map1.map+43)->z = 1.0f;
    (map1.map+44)->x = 694.0f;(map1.map+44)->y = 303.0f;(map1.map+44)->z = 1.0f;
    (map1.map+45)->x = 770.0f;(map1.map+45)->y = 304.0f;(map1.map+45)->z = 1.0f;
    (map1.map+46)->x = 733.0f;(map1.map+46)->y = 347.0f;(map1.map+46)->z = 1.0f;
    (map1.map+47)->x = 696.0f;(map1.map+47)->y = 392.0f;(map1.map+47)->z = 1.0f;
    (map1.map+48)->x = 731.0f;(map1.map+48)->y = 431.0f;(map1.map+48)->z = 1.0f;
    (map1.map+49)->x = 773.0f;(map1.map+49)->y = 478.0f;(map1.map+49)->z = 1.0f;
    (map1.map+50)->x = 850.0f;(map1.map+50)->y = 477.0f;(map1.map+50)->z = 1.0f;
    (map1.map+51)->x = 811.0f;(map1.map+51)->y = 522.0f;(map1.map+51)->z = 1.0f;
    (map1.map+52)->x = 773.0f;(map1.map+52)->y = 565.0f;(map1.map+52)->z = 1.0f;
    (map1.map+53)->x = 666.0f;(map1.map+53)->y = 563.0f;(map1.map+53)->z = 1.0f;
    (map1.map+54)->x = 541.0f;(map1.map+54)->y = 565.0f;(map1.map+54)->z = 1.0f;
    (map1.map+55)->x = 577.0f;(map1.map+55)->y = 606.0f;(map1.map+55)->z = 1.0f;
    (map1.map+56)->x = 617.0f;(map1.map+56)->y = 652.0f;(map1.map+56)->z = 1.0f;
    (map1.map+57)->x = 680.0f;(map1.map+57)->y = 652.0f;(map1.map+57)->z = 1.0f;
    (map1.map+58)->x = 772.0f;(map1.map+58)->y = 652.0f;(map1.map+58)->z = 1.0f;
    (map1.map+59)->x = 818.0f;(map1.map+59)->y = 599.0f;(map1.map+59)->z = 1.0f;
    (map1.map+60)->x = 851.0f;(map1.map+60)->y = 564.0f;(map1.map+60)->z = 1.0f;
    (map1.map+61)->x = 893.0f;(map1.map+61)->y = 516.0f;(map1.map+61)->z = 1.0f;
    (map1.map+62)->x = 928.0f;(map1.map+62)->y = 477.0f;(map1.map+62)->z = 1.0f;
    (map1.map+63)->x = 886.0f;(map1.map+63)->y = 430.0f;(map1.map+63)->z = 1.0f;
    (map1.map+64)->x = 851.0f;(map1.map+64)->y = 390.0f;(map1.map+64)->z = 1.0f;
    (map1.map+65)->x = 774.0f;(map1.map+65)->y = 392.0f;(map1.map+65)->z = 1.0f;
    (map1.map+66)->x = 808.0f;(map1.map+66)->y = 350.0f;(map1.map+66)->z = 1.0f;
    (map1.map+67)->x = 849.0f;(map1.map+67)->y = 304.0f;(map1.map+67)->z = 1.0f;
    (map1.map+68)->x = 814.0f;(map1.map+68)->y = 263.0f;(map1.map+68)->z = 1.0f;
    (map1.map+69)->x = 773.0f;(map1.map+69)->y = 217.0f;(map1.map+69)->z = 1.0f;
    (map1.map+70)->x = 698.0f;(map1.map+70)->y = 216.0f;(map1.map+70)->z = 1.0f;
    (map1.map+71)->x = 616.0f;(map1.map+71)->y = 216.0f;(map1.map+71)->z = 1.0f;
    (map1.map+72)->x = 583.0f;(map1.map+72)->y = 254.0f;(map1.map+72)->z = 1.0f;
    (map1.map+73)->x = 540.0f;(map1.map+73)->y = 303.0f;(map1.map+73)->z = 1.0f;
    (map1.map+74)->x = 503.0f;(map1.map+74)->y = 262.0f;(map1.map+74)->z = 1.0f;

    (map1.map+75)->x = 462.0f;(map1.map+75)->y = 217.0f;(map1.map+75)->z = 1.0f;
    (map1.map+76)->x = 501.0f;(map1.map+76)->y = 173.0f;(map1.map+76)->z = 1.0f;
    (map1.map+77)->x = 535.0f;(map1.map+77)->y = 133.0f;(map1.map+77)->z = 1.0f;
    (map1.map+78)->x = 576.0f;(map1.map+78)->y = 88.0f;(map1.map+78)->z = 1.0f;
    (map1.map+79)->x = 617.0f;(map1.map+79)->y = 43.0f;(map1.map+79)->z = 1.0f;
    (map1.map+80)->x = 694.0f;(map1.map+80)->y = 42.0f;(map1.map+80)->z = 1.0f;
    (map1.map+81)->x = 695.0f;(map1.map+81)->y = 31.0f;(map1.map+81)->z = 1.0f;
    (map1.map+82)->x = 719.0f;(map1.map+82)->y = 71.0f;(map1.map+82)->z = 1.0f;
    (map1.map+83)->x = 743.0f;(map1.map+83)->y = 110.0f;(map1.map+83)->z = 1.0f;
    (map1.map+84)->x = 768.0f;(map1.map+84)->y = 151.0f;(map1.map+84)->z = 1.0f;
    (map1.map+85)->x = 800.0f;(map1.map+85)->y = 197.0f;(map1.map+85)->z = 1.0f;
    (map1.map+86)->x = 825.0f;(map1.map+86)->y = 235.0f;(map1.map+86)->z = 1.0f;
    (map1.map+87)->x = 851.0f;(map1.map+87)->y = 270.0f;(map1.map+87)->z = 1.0f;
    (map1.map+88)->x = 880.0f;(map1.map+88)->y = 313.0f;(map1.map+88)->z = 1.0f;
    (map1.map+89)->x = 904.0f;(map1.map+89)->y = 350.0f;(map1.map+89)->z = 1.0f;
    (map1.map+90)->x = 927.0f;(map1.map+90)->y = 384.0f;(map1.map+90)->z = 1.0f;

    //Map2

    // Map2 fuels
    fuel5.points = (float *)malloc(sizeof(float) * 8);
    fuel6.points = (float *)malloc(sizeof(float) * 8);
    fuel7.points = (float *)malloc(sizeof(float) * 8);
    fuel8.points = (float *)malloc(sizeof(float) * 8);

    fuel5.obtained = false;
    fuel6.obtained = false;
    fuel7.obtained = false;
    fuel8.obtained = false;

    map2.map = nullptr;
    map2.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*49);
    map2.size = 49;
    (map2.map)->x = 127.0f;(map2.map)->y = 407.0f;(map2.map)->z = 1.0f;
    (map2.map+1)->x = 175.0f;(map2.map+1)->y = 461.0f;(map2.map+1)->z = 1.0f;
    (map2.map+2)->x = 223.0f;(map2.map+2)->y = 461.0f;(map2.map+2)->z = 1.0f;
    (map2.map+3)->x = 162.0f;(map2.map+3)->y = 527.0f;(map2.map+3)->z = 1.0f;
    (map2.map+4)->x = 222.0f;(map2.map+4)->y = 527.0f;(map2.map+4)->z = 1.0f;
    (map2.map+5)->x = 258.0f;(map2.map+5)->y = 568.0f;(map2.map+5)->z = 1.0f;
    (map2.map+6)->x = 290.0f;(map2.map+6)->y = 540.0f;(map2.map+6)->z = 1.0f;
    (map2.map+7)->x = 354.0f;(map2.map+7)->y = 608.0f;(map2.map+7)->z = 1.0f;
    (map2.map+8)->x = 293.0f;(map2.map+8)->y = 676.0f;(map2.map+8)->z = 1.0f;
    (map2.map+9)->x = 354.0f;(map2.map+9)->y = 675.0f;(map2.map+9)->z = 1.0f;
    (map2.map+10)->x = 414.0f;(map2.map+10)->y = 608.0f;(map2.map+10)->z = 1.0f;
    (map2.map+11)->x = 365.0f;(map2.map+11)->y = 554.0f;(map2.map+11)->z = 1.0f;
    (map2.map+12)->x = 414.0f;(map2.map+12)->y = 500.0f;(map2.map+12)->z = 1.0f;
    (map2.map+13)->x = 472.0f;(map2.map+13)->y = 500.0f;(map2.map+13)->z = 1.0f;
    (map2.map+14)->x = 510.0f;(map2.map+14)->y = 541.0f;(map2.map+14)->z = 1.0f;
    (map2.map+15)->x = 700.0f;(map2.map+15)->y = 541.0f;(map2.map+15)->z = 1.0f;
    (map2.map+16)->x = 605.0f;(map2.map+16)->y = 648.0f;(map2.map+16)->z = 1.0f;
    (map2.map+17)->x = 664.0f;(map2.map+17)->y = 714.0f;(map2.map+17)->z = 1.0f;
    (map2.map+18)->x = 701.0f;(map2.map+18)->y = 674.0f;(map2.map+18)->z = 1.0f;
    (map2.map+19)->x = 663.0f;(map2.map+19)->y = 674.0f;(map2.map+19)->z = 1.0f;
    (map2.map+20)->x = 724.0f;(map2.map+20)->y = 608.0f;(map2.map+20)->z = 1.0f;
    (map2.map+21)->x = 772.0f;(map2.map+21)->y = 608.0f;(map2.map+21)->z = 1.0f;
    (map2.map+22)->x = 797.0f;(map2.map+22)->y = 580.0f;(map2.map+22)->z = 1.0f;
    (map2.map+23)->x = 759.0f;(map2.map+23)->y = 540.0f;(map2.map+23)->z = 1.0f;
    (map2.map+24)->x = 797.0f;(map2.map+24)->y = 487.0f;(map2.map+24)->z = 1.0f;
    (map2.map+25)->x = 773.0f;(map2.map+25)->y = 461.0f;(map2.map+25)->z = 1.0f;
    (map2.map+26)->x = 797.0f;(map2.map+26)->y = 433.0f;(map2.map+26)->z = 1.0f;
    (map2.map+27)->x = 867.0f;(map2.map+27)->y = 433.0f;(map2.map+27)->z = 1.0f;
    (map2.map+28)->x = 892.0f;(map2.map+28)->y = 407.0f;(map2.map+28)->z = 1.0f;
    (map2.map+29)->x = 845.0f;(map2.map+29)->y = 354.0f;(map2.map+29)->z = 1.0f;
    (map2.map+30)->x = 833.0f;(map2.map+30)->y = 354.0f;(map2.map+30)->z = 1.0f;
    (map2.map+31)->x = 772.0f;(map2.map+31)->y = 286.0f;(map2.map+31)->z = 1.0f;
    (map2.map+32)->x = 796.0f;(map2.map+32)->y = 259.0f;(map2.map+32)->z = 1.0f;
    (map2.map+33)->x = 736.0f;(map2.map+33)->y = 260.0f;(map2.map+33)->z = 1.0f;
    (map2.map+34)->x = 701.0f;(map2.map+34)->y = 219.0f;(map2.map+34)->z = 1.0f;
    (map2.map+35)->x = 664.0f;(map2.map+35)->y = 219.0f;(map2.map+35)->z = 1.0f;
    (map2.map+36)->x = 605.0f;(map2.map+36)->y = 57.0f;(map2.map+36)->z = 1.0f;
    (map2.map+37)->x = 510.0f;(map2.map+37)->y = 110.0f;(map2.map+37)->z = 1.0f;
    (map2.map+38)->x = 544.0f;(map2.map+38)->y = 111.0f;(map2.map+38)->z = 1.0f;
    (map2.map+39)->x = 592.0f;(map2.map+39)->y = 164.0f;(map2.map+39)->z = 1.0f;
    (map2.map+40)->x = 546.0f;(map2.map+40)->y = 218.0f;(map2.map+40)->z = 1.0f;
    (map2.map+41)->x = 461.0f;(map2.map+41)->y = 219.0f;(map2.map+41)->z = 1.0f;
    (map2.map+42)->x = 376.0f;(map2.map+42)->y = 204.0f;(map2.map+42)->z = 1.0f;
    (map2.map+43)->x = 413.0f;(map2.map+43)->y = 245.0f;(map2.map+43)->z = 1.0f;
    (map2.map+44)->x = 366.0f;(map2.map+44)->y = 245.0f;(map2.map+44)->z = 1.0f;
    (map2.map+45)->x = 318.0f;(map2.map+45)->y = 300.0f;(map2.map+45)->z = 1.0f;
    (map2.map+46)->x = 293.0f;(map2.map+46)->y = 300.0f;(map2.map+46)->z = 1.0f;
    (map2.map+47)->x = 198.0f;(map2.map+47)->y = 407.0f;(map2.map+47)->z = 1.0f;
    (map2.map+48)->x = 127.0f;(map2.map+48)->y = 407.0f;(map2.map+48)->z = 1.0f;

    //Map 3
    map3.map = nullptr;
    map3.map = (esat::Vec3*) malloc(sizeof(esat::Vec3) * 74);
    map3.size = 74;
    (map3.map+0)->x = 246.0f;(map3.map+0)->y = 47.0f;(map3.map+0)->z = 1.0f;
    (map3.map+1)->x = 288.0f;(map3.map+1)->y = 94.0f;(map3.map+1)->z = 1.0f;
    (map3.map+2)->x = 316.0f;(map3.map+2)->y = 126.0f;(map3.map+2)->z = 1.0f;
    (map3.map+3)->x = 341.0f;(map3.map+3)->y = 153.0f;(map3.map+3)->z = 1.0f;
    (map3.map+4)->x = 367.0f;(map3.map+4)->y = 182.0f;(map3.map+4)->z = 1.0f;
    (map3.map+5)->x = 334.0f;(map3.map+5)->y = 219.0f;(map3.map+5)->z = 1.0f;
    (map3.map+6)->x = 306.0f;(map3.map+6)->y = 253.0f;(map3.map+6)->z = 1.0f;
    (map3.map+7)->x = 272.0f;(map3.map+7)->y = 289.0f;(map3.map+7)->z = 1.0f;
    (map3.map+8)->x = 241.0f;(map3.map+8)->y = 324.0f;(map3.map+8)->z = 1.0f;
    (map3.map+9)->x = 210.0f;(map3.map+9)->y = 360.0f;(map3.map+9)->z = 1.0f;
    (map3.map+10)->x = 175.0f;(map3.map+10)->y = 397.0f;(map3.map+10)->z = 1.0f;
    (map3.map+11)->x = 126.0f;(map3.map+11)->y = 453.0f;(map3.map+11)->z = 1.0f;
    (map3.map+12)->x = 152.0f;(map3.map+12)->y = 482.0f;(map3.map+12)->z = 1.0f;
    (map3.map+13)->x = 181.0f;(map3.map+13)->y = 515.0f;(map3.map+13)->z = 1.0f;
    (map3.map+14)->x = 203.0f;(map3.map+14)->y = 541.0f;(map3.map+14)->z = 1.0f;
    (map3.map+15)->x = 235.0f;(map3.map+15)->y = 576.0f;(map3.map+15)->z = 1.0f;
    (map3.map+16)->x = 261.0f;(map3.map+16)->y = 605.0f;(map3.map+16)->z = 1.0f;
    (map3.map+17)->x = 293.0f;(map3.map+17)->y = 641.0f;(map3.map+17)->z = 1.0f;
    (map3.map+18)->x = 329.0f;(map3.map+18)->y = 681.0f;(map3.map+18)->z = 1.0f;
    (map3.map+19)->x = 368.0f;(map3.map+19)->y = 725.0f;(map3.map+19)->z = 1.0f;
    (map3.map+20)->x = 424.0f;(map3.map+20)->y = 724.0f;(map3.map+20)->z = 1.0f;
    (map3.map+21)->x = 476.0f;(map3.map+21)->y = 725.0f;(map3.map+21)->z = 1.0f;
    (map3.map+22)->x = 525.0f;(map3.map+22)->y = 725.0f;(map3.map+22)->z = 1.0f;
    (map3.map+23)->x = 579.0f;(map3.map+23)->y = 725.0f;(map3.map+23)->z = 1.0f;
    (map3.map+24)->x = 642.0f;(map3.map+24)->y = 724.0f;(map3.map+24)->z = 1.0f;
    (map3.map+25)->x = 690.0f;(map3.map+25)->y = 724.0f;(map3.map+25)->z = 1.0f;
    (map3.map+26)->x = 726.0f;(map3.map+26)->y = 684.0f;(map3.map+26)->z = 1.0f;
    (map3.map+27)->x = 768.0f;(map3.map+27)->y = 636.0f;(map3.map+27)->z = 1.0f;
    (map3.map+28)->x = 812.0f;(map3.map+28)->y = 587.0f;(map3.map+28)->z = 1.0f;
    (map3.map+29)->x = 851.0f;(map3.map+29)->y = 545.0f;(map3.map+29)->z = 1.0f;
    (map3.map+30)->x = 889.0f;(map3.map+30)->y = 502.0f;(map3.map+30)->z = 1.0f;
    (map3.map+31)->x = 931.0f;(map3.map+31)->y = 454.0f;(map3.map+31)->z = 1.0f;
    (map3.map+32)->x = 886.0f;(map3.map+32)->y = 404.0f;(map3.map+32)->z = 1.0f;
    (map3.map+33)->x = 852.0f;(map3.map+33)->y = 365.0f;(map3.map+33)->z = 1.0f;
    (map3.map+34)->x = 818.0f;(map3.map+34)->y = 325.0f;(map3.map+34)->z = 1.0f;
    (map3.map+35)->x = 789.0f;(map3.map+35)->y = 295.0f;(map3.map+35)->z = 1.0f;
    (map3.map+36)->x = 765.0f;(map3.map+36)->y = 268.0f;(map3.map+36)->z = 1.0f;
    (map3.map+37)->x = 730.0f;(map3.map+37)->y = 229.0f;(map3.map+37)->z = 1.0f;
    (map3.map+38)->x = 646.0f;(map3.map+38)->y = 227.0f;(map3.map+38)->z = 1.0f;
    (map3.map+39)->x = 581.0f;(map3.map+39)->y = 228.0f;(map3.map+39)->z = 1.0f;
    (map3.map+40)->x = 528.0f;(map3.map+40)->y = 229.0f;(map3.map+40)->z = 1.0f;
    (map3.map+41)->x = 493.0f;(map3.map+41)->y = 268.0f;(map3.map+41)->z = 1.0f;
    (map3.map+42)->x = 448.0f;(map3.map+42)->y = 318.0f;(map3.map+42)->z = 1.0f;
    (map3.map+43)->x = 489.0f;(map3.map+43)->y = 365.0f;(map3.map+43)->z = 1.0f;
    (map3.map+44)->x = 530.0f;(map3.map+44)->y = 410.0f;(map3.map+44)->z = 1.0f;
    (map3.map+45)->x = 570.0f;(map3.map+45)->y = 455.0f;(map3.map+45)->z = 1.0f;
    (map3.map+46)->x = 609.0f;(map3.map+46)->y = 499.0f;(map3.map+46)->z = 1.0f;
    (map3.map+47)->x = 674.0f;(map3.map+47)->y = 499.0f;(map3.map+47)->z = 1.0f;
    (map3.map+48)->x = 729.0f;(map3.map+48)->y = 500.0f;(map3.map+48)->z = 1.0f;
    (map3.map+49)->x = 733.0f;(map3.map+49)->y = 414.0f;(map3.map+49)->z = 1.0f;
    (map3.map+50)->x = 689.0f;(map3.map+50)->y = 365.0f;(map3.map+50)->z = 1.0f;
    (map3.map+51)->x = 648.0f;(map3.map+51)->y = 364.0f;(map3.map+51)->z = 1.0f;
    (map3.map+52)->x = 608.0f;(map3.map+52)->y = 364.0f;(map3.map+52)->z = 1.0f;
    (map3.map+53)->x = 569.0f;(map3.map+53)->y = 319.0f;(map3.map+53)->z = 1.0f;
    (map3.map+54)->x = 689.0f;(map3.map+54)->y = 320.0f;(map3.map+54)->z = 1.0f;
    (map3.map+55)->x = 740.0f;(map3.map+55)->y = 376.0f;(map3.map+55)->z = 1.0f;
    (map3.map+56)->x = 810.0f;(map3.map+56)->y = 453.0f;(map3.map+56)->z = 1.0f;
    (map3.map+57)->x = 775.0f;(map3.map+57)->y = 495.0f;(map3.map+57)->z = 1.0f;
    (map3.map+58)->x = 734.0f;(map3.map+58)->y = 540.0f;(map3.map+58)->z = 1.0f;
    (map3.map+59)->x = 696.0f;(map3.map+59)->y = 582.0f;(map3.map+59)->z = 1.0f;
    (map3.map+60)->x = 649.0f;(map3.map+60)->y = 635.0f;(map3.map+60)->z = 1.0f;
    (map3.map+61)->x = 586.0f;(map3.map+61)->y = 635.0f;(map3.map+61)->z = 1.0f;
    (map3.map+62)->x = 508.0f;(map3.map+62)->y = 635.0f;(map3.map+62)->z = 1.0f;
    (map3.map+63)->x = 408.0f;(map3.map+63)->y = 635.0f;(map3.map+63)->z = 1.0f;
    (map3.map+64)->x = 325.0f;(map3.map+64)->y = 542.0f;(map3.map+64)->z = 1.0f;
    (map3.map+65)->x = 290.0f;(map3.map+65)->y = 501.0f;(map3.map+65)->z = 1.0f;
    (map3.map+66)->x = 247.0f;(map3.map+66)->y = 453.0f;(map3.map+66)->z = 1.0f;
    (map3.map+67)->x = 295.0f;(map3.map+67)->y = 400.0f;(map3.map+67)->z = 1.0f;
    (map3.map+68)->x = 352.0f;(map3.map+68)->y = 335.0f;(map3.map+68)->z = 1.0f;
    (map3.map+69)->x = 402.0f;(map3.map+69)->y = 281.0f;(map3.map+69)->z = 1.0f;
    (map3.map+70)->x = 448.0f;(map3.map+70)->y = 229.0f;(map3.map+70)->z = 1.0f;
    (map3.map+71)->x = 500.0f;(map3.map+71)->y = 171.0f;(map3.map+71)->z = 1.0f;
    (map3.map+72)->x = 553.0f;(map3.map+72)->y = 109.0f;(map3.map+72)->z = 1.0f;
    (map3.map+73)->x = 608.0f;(map3.map+73)->y = 48.0f;(map3.map+73)->z = 1.0f;


    //Map3 Bomb
    map3Bomb.map = nullptr;
    map3Bomb.map = (esat::Vec3*) malloc(sizeof(esat::Vec3) * 11);
    map3Bomb.size = 11;
    (map3Bomb.map+0)->x = 468.0f;(map3Bomb.map+0)->y = 274.0f;(map3Bomb.map+0)->z = 1.0f;
    (map3Bomb.map+1)->x = 498.0f;(map3Bomb.map+1)->y = 286.0f;(map3Bomb.map+1)->z = 1.0f;
    (map3Bomb.map+2)->x = 468.0f;(map3Bomb.map+2)->y = 299.0f;(map3Bomb.map+2)->z = 1.0f;
    (map3Bomb.map+3)->x = 458.0f;(map3Bomb.map+3)->y = 287.0f;(map3Bomb.map+3)->z = 1.0f;
    (map3Bomb.map+4)->x = 489.0f;(map3Bomb.map+4)->y = 276.0f;(map3Bomb.map+4)->z = 1.0f;
    (map3Bomb.map+5)->x = 499.0f;(map3Bomb.map+5)->y = 286.0f;(map3Bomb.map+5)->z = 1.0f;
    (map3Bomb.map+6)->x = 489.0f;(map3Bomb.map+6)->y = 298.0f;(map3Bomb.map+6)->z = 1.0f;
    (map3Bomb.map+7)->x = 468.0f;(map3Bomb.map+7)->y = 299.0f;(map3Bomb.map+7)->z = 1.0f;
    (map3Bomb.map+8)->x = 489.0f;(map3Bomb.map+8)->y = 299.0f;(map3Bomb.map+8)->z = 1.0f;
    (map3Bomb.map+9)->x = 458.0f;(map3Bomb.map+9)->y = 287.0f;(map3Bomb.map+9)->z = 1.0f;
    (map3Bomb.map+10)->x = 469.0f;(map3Bomb.map+10)->y = 276.0f;(map3Bomb.map+10)->z = 1.0f;

    //Map4

    map4.map = nullptr;
    map4.map = (esat::Vec3*) malloc(sizeof(esat::Vec3) * 83);
    map4.size = 83;
    (map4.map+0)->x = 36.0f;(map4.map+0)->y = 736.0f;(map4.map+0)->z = 1.0f;
    (map4.map+1)->x = 51.0f;(map4.map+1)->y = 726.0f;(map4.map+1)->z = 1.0f;
    (map4.map+2)->x = 65.0f;(map4.map+2)->y = 718.0f;(map4.map+2)->z = 1.0f;
    (map4.map+3)->x = 79.0f;(map4.map+3)->y = 710.0f;(map4.map+3)->z = 1.0f;
    (map4.map+4)->x = 94.0f;(map4.map+4)->y = 701.0f;(map4.map+4)->z = 1.0f;
    (map4.map+5)->x = 122.0f;(map4.map+5)->y = 701.0f;(map4.map+5)->z = 1.0f;
    (map4.map+6)->x = 131.0f;(map4.map+6)->y = 684.0f;(map4.map+6)->z = 1.0f;
    (map4.map+7)->x = 137.0f;(map4.map+7)->y = 670.0f;(map4.map+7)->z = 1.0f;
    (map4.map+8)->x = 143.0f;(map4.map+8)->y = 685.0f;(map4.map+8)->z = 1.0f;
    (map4.map+9)->x = 148.0f;(map4.map+9)->y = 703.0f;(map4.map+9)->z = 1.0f;
    (map4.map+10)->x = 153.0f;(map4.map+10)->y = 718.0f;(map4.map+10)->z = 1.0f;
    (map4.map+11)->x = 161.0f;(map4.map+11)->y = 710.0f;(map4.map+11)->z = 1.0f;
    (map4.map+12)->x = 184.0f;(map4.map+12)->y = 710.0f;(map4.map+12)->z = 1.0f;
    (map4.map+13)->x = 190.0f;(map4.map+13)->y = 698.0f;(map4.map+13)->z = 1.0f;
    (map4.map+14)->x = 197.0f;(map4.map+14)->y = 685.0f;(map4.map+14)->z = 1.0f;
    (map4.map+15)->x = 206.0f;(map4.map+15)->y = 699.0f;(map4.map+15)->z = 1.0f;
    (map4.map+16)->x = 212.0f;(map4.map+16)->y = 709.0f;(map4.map+16)->z = 1.0f;
    (map4.map+17)->x = 221.0f;(map4.map+17)->y = 719.0f;(map4.map+17)->z = 1.0f;
    (map4.map+18)->x = 230.0f;(map4.map+18)->y = 727.0f;(map4.map+18)->z = 1.0f;
    (map4.map+19)->x = 256.0f;(map4.map+19)->y = 727.0f;(map4.map+19)->z = 1.0f;
    (map4.map+20)->x = 265.0f;(map4.map+20)->y = 719.0f;(map4.map+20)->z = 1.0f;
    (map4.map+21)->x = 273.0f;(map4.map+21)->y = 711.0f;(map4.map+21)->z = 1.0f;
    (map4.map+22)->x = 280.0f;(map4.map+22)->y = 688.0f;(map4.map+22)->z = 1.0f;
    (map4.map+23)->x = 288.0f;(map4.map+23)->y = 661.0f;(map4.map+23)->z = 1.0f;
    (map4.map+24)->x = 295.0f;(map4.map+24)->y = 683.0f;(map4.map+24)->z = 1.0f;
    (map4.map+25)->x = 300.0f;(map4.map+25)->y = 697.0f;(map4.map+25)->z = 1.0f;
    (map4.map+26)->x = 304.0f;(map4.map+26)->y = 711.0f;(map4.map+26)->z = 1.0f;
    (map4.map+27)->x = 314.0f;(map4.map+27)->y = 720.0f;(map4.map+27)->z = 1.0f;
    (map4.map+28)->x = 323.0f;(map4.map+28)->y = 727.0f;(map4.map+28)->z = 1.0f;
    (map4.map+29)->x = 333.0f;(map4.map+29)->y = 735.0f;(map4.map+29)->z = 1.0f;
    (map4.map+30)->x = 337.0f;(map4.map+30)->y = 720.0f;(map4.map+30)->z = 1.0f;
    (map4.map+31)->x = 341.0f;(map4.map+31)->y = 702.0f;(map4.map+31)->z = 1.0f;
    (map4.map+32)->x = 356.0f;(map4.map+32)->y = 702.0f;(map4.map+32)->z = 1.0f;
    (map4.map+33)->x = 369.0f;(map4.map+33)->y = 715.0f;(map4.map+33)->z = 1.0f;
    (map4.map+34)->x = 382.0f;(map4.map+34)->y = 725.0f;(map4.map+34)->z = 1.0f;
    (map4.map+35)->x = 393.0f;(map4.map+35)->y = 735.0f;(map4.map+35)->z = 1.0f;
    (map4.map+36)->x = 397.0f;(map4.map+36)->y = 723.0f;(map4.map+36)->z = 1.0f;
    (map4.map+37)->x = 401.0f;(map4.map+37)->y = 702.0f;(map4.map+37)->z = 1.0f;
    (map4.map+38)->x = 416.0f;(map4.map+38)->y = 702.0f;(map4.map+38)->z = 1.0f;
    (map4.map+39)->x = 420.0f;(map4.map+39)->y = 721.0f;(map4.map+39)->z = 1.0f;
    (map4.map+40)->x = 423.0f;(map4.map+40)->y = 737.0f;(map4.map+40)->z = 1.0f;
    (map4.map+41)->x = 436.0f;(map4.map+41)->y = 722.0f;(map4.map+41)->z = 1.0f;
    (map4.map+42)->x = 454.0f;(map4.map+42)->y = 701.0f;(map4.map+42)->z = 1.0f;
    (map4.map+43)->x = 462.0f;(map4.map+43)->y = 713.0f;(map4.map+43)->z = 1.0f;
    (map4.map+44)->x = 468.0f;(map4.map+44)->y = 727.0f;(map4.map+44)->z = 1.0f;
    (map4.map+45)->x = 490.0f;(map4.map+45)->y = 727.0f;(map4.map+45)->z = 1.0f;
    (map4.map+46)->x = 502.0f;(map4.map+46)->y = 707.0f;(map4.map+46)->z = 1.0f;
    (map4.map+47)->x = 514.0f;(map4.map+47)->y = 686.0f;(map4.map+47)->z = 1.0f;
    (map4.map+48)->x = 543.0f;(map4.map+48)->y = 686.0f;(map4.map+48)->z = 1.0f;
    (map4.map+49)->x = 559.0f;(map4.map+49)->y = 659.0f;(map4.map+49)->z = 1.0f;
    (map4.map+50)->x = 574.0f;(map4.map+50)->y = 685.0f;(map4.map+50)->z = 1.0f;
    (map4.map+51)->x = 589.0f;(map4.map+51)->y = 659.0f;(map4.map+51)->z = 1.0f;
    (map4.map+52)->x = 604.0f;(map4.map+52)->y = 686.0f;(map4.map+52)->z = 1.0f;
    (map4.map+53)->x = 627.0f;(map4.map+53)->y = 686.0f;(map4.map+53)->z = 1.0f;
    (map4.map+54)->x = 630.0f;(map4.map+54)->y = 701.0f;(map4.map+54)->z = 1.0f;
    (map4.map+55)->x = 635.0f;(map4.map+55)->y = 718.0f;(map4.map+55)->z = 1.0f;
    (map4.map+56)->x = 648.0f;(map4.map+56)->y = 718.0f;(map4.map+56)->z = 1.0f;
    (map4.map+57)->x = 663.0f;(map4.map+57)->y = 701.0f;(map4.map+57)->z = 1.0f;
    (map4.map+58)->x = 671.0f;(map4.map+58)->y = 684.0f;(map4.map+58)->z = 1.0f;
    (map4.map+59)->x = 679.0f;(map4.map+59)->y = 667.0f;(map4.map+59)->z = 1.0f;
    (map4.map+60)->x = 687.0f;(map4.map+60)->y = 687.0f;(map4.map+60)->z = 1.0f;
    (map4.map+61)->x = 696.0f;(map4.map+61)->y = 703.0f;(map4.map+61)->z = 1.0f;
    (map4.map+62)->x = 709.0f;(map4.map+62)->y = 727.0f;(map4.map+62)->z = 1.0f;
    (map4.map+63)->x = 725.0f;(map4.map+63)->y = 727.0f;(map4.map+63)->z = 1.0f;
    (map4.map+64)->x = 731.0f;(map4.map+64)->y = 711.0f;(map4.map+64)->z = 1.0f;
    (map4.map+65)->x = 739.0f;(map4.map+65)->y = 695.0f;(map4.map+65)->z = 1.0f;
    (map4.map+66)->x = 748.0f;(map4.map+66)->y = 712.0f;(map4.map+66)->z = 1.0f;
    (map4.map+67)->x = 754.0f;(map4.map+67)->y = 726.0f;(map4.map+67)->z = 1.0f;
    (map4.map+68)->x = 768.0f;(map4.map+68)->y = 719.0f;(map4.map+68)->z = 1.0f;
    (map4.map+69)->x = 785.0f;(map4.map+69)->y = 719.0f;(map4.map+69)->z = 1.0f;
    (map4.map+70)->x = 791.0f;(map4.map+70)->y = 698.0f;(map4.map+70)->z = 1.0f;
    (map4.map+71)->x = 799.0f;(map4.map+71)->y = 670.0f;(map4.map+71)->z = 1.0f;
    (map4.map+72)->x = 808.0f;(map4.map+72)->y = 695.0f;(map4.map+72)->z = 1.0f;
    (map4.map+73)->x = 815.0f;(map4.map+73)->y = 718.0f;(map4.map+73)->z = 1.0f;
    (map4.map+74)->x = 829.0f;(map4.map+74)->y = 703.0f;(map4.map+74)->z = 1.0f;
    (map4.map+75)->x = 845.0f;(map4.map+75)->y = 702.0f;(map4.map+75)->z = 1.0f;
    (map4.map+76)->x = 874.0f;(map4.map+76)->y = 718.0f;(map4.map+76)->z = 1.0f;
    (map4.map+77)->x = 897.0f;(map4.map+77)->y = 701.0f;(map4.map+77)->z = 1.0f;
    (map4.map+78)->x = 935.0f;(map4.map+78)->y = 701.0f;(map4.map+78)->z = 1.0f;
    (map4.map+79)->x = 950.0f;(map4.map+79)->y = 660.0f;(map4.map+79)->z = 1.0f;
    (map4.map+80)->x = 965.0f;(map4.map+80)->y = 703.0f;(map4.map+80)->z = 1.0f;
    (map4.map+81)->x = 979.0f;(map4.map+81)->y = 703.0f;(map4.map+81)->z = 1.0f;
    (map4.map+82)->x = 994.0f;(map4.map+82)->y = 733.0f;(map4.map+82)->z = 1.0f;

}

void NormalizeMap(TMap mapa,float lenght,float sizeX, float sizeY){
    for (int i = 0; i < lenght; i++){
        (mapa.map + i)->x -= CENTROX;
        (mapa.map + i)->y -= CENTROY;
        (mapa.map + i)->x /= sizeX;
        (mapa.map + i)->y /= sizeY;
    }
    
}
void NormalizeLogoMat(TMap mapa,float lenght,float sizeX, float sizeY){
    for (int i = 0; i < lenght; i++){
        (mapa.map + i)->x -= CENTROX;
        (mapa.map + i)->y -= CENTROY;
        (mapa.map + i)->x /= sizeX;
        (mapa.map + i)->y /= sizeY;
    }
    
}
//**************** End ****************
