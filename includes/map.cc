// const int map2Size = 48;
float xPrueba = 0.0f;
float YPrueba = 0.0f;
TFuelMat fuel1;
TFuelMat fuel2;
TFuelMat fuel3;
TFuelMat fuel4;

//Map1 turrets
TTurret turret1;
TTurret turret2;
TTurret turret3;
TTurret turret4;
TTurret turret5;
TTurret turret6;
TTurret turret7;
TTurret turret8;
float *turret1_points = (float*) malloc(sizeof(float)*8);
float *turret2_points = (float*) malloc(sizeof(float)*8);
float *turret3_points = (float*) malloc(sizeof(float)*8);
float *turret4_points = (float*) malloc(sizeof(float)*8);
float *turret5_points = (float*) malloc(sizeof(float)*8);
float *turret6_points = (float*) malloc(sizeof(float)*8);
float *turret7_points = (float*) malloc(sizeof(float)*8);
float *turret8_points = (float*) malloc(sizeof(float)*8);
float temporal = 1.0f;
int temporaliNT = 0;

void NormalizeFuel(TFuelMat mapa,float lenght,float sizeX, float sizeY){
    for (int i = 0; i < lenght; i++){
        // (mapa.map + i)->x -= CENTROX;
        // (mapa.map + i)->y -= CENTROY;
        (mapa.map + i)->x /= sizeX;
        (mapa.map + i)->y /= sizeY;
    }
    
}
void NormalizeTurret(TTurret mapa,float lenght,float sizeX, float sizeY){
    for (int i = 0; i < lenght; i++){
        // (mapa.map + i)->x -= CENTROX;
        // (mapa.map + i)->y -= CENTROY;
        (mapa.map + i)->x /= sizeX;
        (mapa.map + i)->y /= sizeY;
    }
    
}

void DrawFigure1(TMap *m, int size, bool scalate = true, TColor color = Verde){
 
    
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

    if(scalate){
        m->escalar+=5;
    }

    //El escalar de fuel tiene que llegar a 30
    if(fuel1.escalar<30)fuel1.escalar+=0.3f;
    if(fuel2.escalar<30)fuel2.escalar+=0.3f;
    if(fuel3.escalar<30)fuel3.escalar+=0.3f;
    if(fuel4.escalar<30)fuel4.escalar+=0.3f;


    esat::Vec2 tr_circle[91];
    esat::Vec2 tr_fuel[4];
    esat::Vec2 tr_fuel2[4];
    esat::Vec2 tr_fuel3[4];
    esat::Vec2 tr_fuel4[4];

    //Turret1
    esat::Vec2 tr_turret11[4];
    esat::Vec2 tr_turret12[4];
    
    //Turret2
    esat::Vec2 tr_turret21[4];
    esat::Vec2 tr_turret22[4];

    //Turret3
    esat::Vec2 tr_turret31[4];
    esat::Vec2 tr_turret32[4];
    
    //Turret4
    esat::Vec2 tr_turret41[4];
    esat::Vec2 tr_turret42[4];
    
    //Turret5
    esat::Vec2 tr_turret51[4];
    esat::Vec2 tr_turret52[4];
    
    //Turret6
    esat::Vec2 tr_turret61[4];
    esat::Vec2 tr_turret62[4];
    
    //Turret7
    esat::Vec2 tr_turret71[4];
    esat::Vec2 tr_turret72[4];
    
    //Turret8
    esat::Vec2 tr_turret81[4];
    esat::Vec2 tr_turret82[4];

    //Scalating map
    for (int i = 0; i < size; i++){
        esat::Mat3 matIdentity = esat::Mat3Identity();
        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(m->escalar, m->escalar), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(1.25f, 1.0f), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(CENTROX, CENTROY+50), matIdentity);
        esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(m->map+i));
        tr_circle[i] = {tmp.x, tmp.y};
        
    }
    
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
    // printf("%f\n",temporal);


    //Drawing turrets
    //Draw Base
    for (int i = 0; i < 4; i++){
        esat::Mat3 matIdentity = esat::Mat3Identity();
        esat::Mat3 matIdentity2 = esat::Mat3Identity();
        esat::Mat3 matIdentity3 = esat::Mat3Identity();
        esat::Mat3 matIdentity4 = esat::Mat3Identity();
        esat::Mat3 matIdentity5 = esat::Mat3Identity();
        esat::Mat3 matIdentity6 = esat::Mat3Identity();
        esat::Mat3 matIdentity7 = esat::Mat3Identity();
        esat::Mat3 matIdentity8 = esat::Mat3Identity();

        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(turret1.escalar, turret1.escalar), matIdentity);
        matIdentity2 = esat::Mat3Multiply(esat::Mat3Scale(turret2.escalar, turret2.escalar), matIdentity2);
        matIdentity3 = esat::Mat3Multiply(esat::Mat3Scale(turret3.escalar, turret3.escalar), matIdentity3);
        matIdentity4 = esat::Mat3Multiply(esat::Mat3Scale(turret4.escalar, turret4.escalar), matIdentity4);
        matIdentity5 = esat::Mat3Multiply(esat::Mat3Scale(turret5.escalar, turret5.escalar), matIdentity5);
        matIdentity6 = esat::Mat3Multiply(esat::Mat3Scale(turret6.escalar, turret6.escalar), matIdentity6);
        matIdentity7 = esat::Mat3Multiply(esat::Mat3Scale(turret7.escalar, turret7.escalar), matIdentity7);
        matIdentity8 = esat::Mat3Multiply(esat::Mat3Scale(turret8.escalar, turret8.escalar), matIdentity8);

        matIdentity = esat::Mat3Multiply(esat::Mat3Rotate(5.999997f), matIdentity);
        matIdentity2 = esat::Mat3Multiply(esat::Mat3Rotate(5.999997f), matIdentity2);
        matIdentity3 = esat::Mat3Multiply(esat::Mat3Rotate(-1.5f), matIdentity3);
        matIdentity4 = esat::Mat3Multiply(esat::Mat3Rotate(1.6f), matIdentity4);
        matIdentity5 = esat::Mat3Multiply(esat::Mat3Rotate(2.79f), matIdentity5);
        matIdentity6 = esat::Mat3Multiply(esat::Mat3Rotate(2.79f), matIdentity6);
        matIdentity7 = esat::Mat3Multiply(esat::Mat3Rotate(-1.5f), matIdentity7);
        matIdentity8 = esat::Mat3Multiply(esat::Mat3Rotate(2.79f), matIdentity8);

        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[20].x-158.0f, tr_circle[20].y), matIdentity);
        matIdentity2 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[18].x - 113.0f, tr_circle[18].y - 50.0f), matIdentity2);
        matIdentity3 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[11].x - 100.0f, tr_circle[11].y + 174.0f), matIdentity3);
        matIdentity4 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[35].x +82.0f, tr_circle[35].y-94.5f), matIdentity4);
        matIdentity5 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[42].x + 70.5f, tr_circle[42].y + 96.0f), matIdentity5);
        matIdentity6 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[44].x + 70.5f, tr_circle[44].y + 96.0f), matIdentity6);
        matIdentity7 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[52].x - 120.5f, tr_circle[52].y - 68.5f), matIdentity7);
        matIdentity8 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[59].x + 90.0f, tr_circle[59].y + 70.0f), matIdentity8);
        // printf("TemporalINT-> %d\n",temporaliNT);

        esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(turret1.map + i));
        esat::Vec3 tmp2 = esat::Mat3TransformVec3(matIdentity2, *(turret2.map + i));
        esat::Vec3 tmp3 = esat::Mat3TransformVec3(matIdentity3, *(turret3.map + i));
        esat::Vec3 tmp4 = esat::Mat3TransformVec3(matIdentity4, *(turret4.map + i));
        esat::Vec3 tmp5 = esat::Mat3TransformVec3(matIdentity5, *(turret5.map + i));
        esat::Vec3 tmp6 = esat::Mat3TransformVec3(matIdentity6, *(turret6.map + i));
        esat::Vec3 tmp7 = esat::Mat3TransformVec3(matIdentity7, *(turret7.map + i));
        esat::Vec3 tmp8 = esat::Mat3TransformVec3(matIdentity8, *(turret8.map + i));

        tr_turret11[i] = {tmp.x, tmp.y};
        tr_turret21[i] = {tmp2.x, tmp2.y};
        tr_turret31[i] = {tmp3.x, tmp3.y};
        tr_turret41[i] = {tmp4.x, tmp4.y};
        tr_turret51[i] = {tmp5.x, tmp5.y};
        tr_turret61[i] = {tmp6.x, tmp6.y};
        tr_turret71[i] = {tmp7.x, tmp7.y};
        tr_turret81[i] = {tmp8.x, tmp8.y};
    }

    //Draw head
    for (int i = 4; i < 8; i++){
        esat::Mat3 matIdentity = esat::Mat3Identity();
        esat::Mat3 matIdentity2 = esat::Mat3Identity();
        esat::Mat3 matIdentity3 = esat::Mat3Identity();
        esat::Mat3 matIdentity4 = esat::Mat3Identity();
        esat::Mat3 matIdentity5 = esat::Mat3Identity();
        esat::Mat3 matIdentity6 = esat::Mat3Identity();
        esat::Mat3 matIdentity7 = esat::Mat3Identity();
        esat::Mat3 matIdentity8 = esat::Mat3Identity();

        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(turret1.escalar, turret1.escalar), matIdentity);
        matIdentity2 = esat::Mat3Multiply(esat::Mat3Scale(turret2.escalar, turret2.escalar), matIdentity2);
        matIdentity3 = esat::Mat3Multiply(esat::Mat3Scale(turret3.escalar, turret3.escalar), matIdentity3);
        matIdentity4 = esat::Mat3Multiply(esat::Mat3Scale(turret4.escalar, turret4.escalar), matIdentity4);
        matIdentity5 = esat::Mat3Multiply(esat::Mat3Scale(turret5.escalar, turret5.escalar), matIdentity5);
        matIdentity6 = esat::Mat3Multiply(esat::Mat3Scale(turret6.escalar, turret6.escalar), matIdentity6);
        matIdentity7 = esat::Mat3Multiply(esat::Mat3Scale(turret7.escalar, turret7.escalar), matIdentity7);
        matIdentity8 = esat::Mat3Multiply(esat::Mat3Scale(turret8.escalar, turret8.escalar), matIdentity8);

        matIdentity = esat::Mat3Multiply(esat::Mat3Rotate(5.999997f), matIdentity);
        matIdentity2 = esat::Mat3Multiply(esat::Mat3Rotate(5.999997f), matIdentity2);
        matIdentity3 = esat::Mat3Multiply(esat::Mat3Rotate(-1.5f), matIdentity3);
        matIdentity4 = esat::Mat3Multiply(esat::Mat3Rotate(1.6f), matIdentity4);
        matIdentity5 = esat::Mat3Multiply(esat::Mat3Rotate(2.79f), matIdentity5);
        matIdentity6 = esat::Mat3Multiply(esat::Mat3Rotate(2.79f), matIdentity6);
        matIdentity7 = esat::Mat3Multiply(esat::Mat3Rotate(-1.5f), matIdentity7);
        matIdentity8 = esat::Mat3Multiply(esat::Mat3Rotate(2.79f), matIdentity8);

        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[20].x - 158.0f, tr_circle[20].y), matIdentity);
        matIdentity2 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[18].x -113.0f, tr_circle[18].y -50.0f), matIdentity2);
        matIdentity3 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[11].x - 100.0f, tr_circle[11].y + 174.0f), matIdentity3);
        matIdentity4 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[35].x + 82.0f, tr_circle[35].y - 94.5f), matIdentity4);
        matIdentity5 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[42].x + 70.5f, tr_circle[42].y + 96.0f), matIdentity5);
        matIdentity6 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[44].x + 70.5f, tr_circle[44].y + 96.0f), matIdentity6);
        matIdentity7 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[52].x - 120.5f, tr_circle[52].y - 68.5f), matIdentity7);
        matIdentity8 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[59].x + 90.0f, tr_circle[59].y + 70.0f), matIdentity8);

        esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(turret1.map + i));
        esat::Vec3 tmp2 = esat::Mat3TransformVec3(matIdentity2, *(turret1.map + i));
        esat::Vec3 tmp3 = esat::Mat3TransformVec3(matIdentity3, *(turret1.map + i));
        esat::Vec3 tmp4 = esat::Mat3TransformVec3(matIdentity4, *(turret1.map + i));
        esat::Vec3 tmp5 = esat::Mat3TransformVec3(matIdentity5, *(turret1.map + i));
        esat::Vec3 tmp6 = esat::Mat3TransformVec3(matIdentity6, *(turret1.map + i));
        esat::Vec3 tmp7 = esat::Mat3TransformVec3(matIdentity7, *(turret1.map + i));
        esat::Vec3 tmp8 = esat::Mat3TransformVec3(matIdentity8, *(turret1.map + i));

        tr_turret12[i-4] = {tmp.x, tmp.y};
        tr_turret22[i-4] = {tmp2.x, tmp2.y};
        tr_turret32[i-4] = {tmp3.x, tmp3.y};
        tr_turret42[i-4] = {tmp4.x, tmp4.y};
        tr_turret52[i-4] = {tmp5.x, tmp5.y};
        tr_turret62[i-4] = {tmp6.x, tmp6.y};
        tr_turret72[i-4] = {tmp7.x, tmp7.y};
        tr_turret82[i-4] = {tmp8.x, tmp8.y};
    }


    //Drawing Fuel
    for (int i = 0; i < 4; i++){
        // printf("Antes-> x[%f] y[%f]\n", (fuel1.map + i)->x, (fuel1.map + i)->y);
        esat::Mat3 matIdentity = esat::Mat3Identity();
        esat::Mat3 matIdentity2 = esat::Mat3Identity();
        esat::Mat3 matIdentity3 = esat::Mat3Identity();
        esat::Mat3 matIdentity4 = esat::Mat3Identity();

        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(fuel1.escalar, fuel1.escalar), matIdentity);
        matIdentity2 = esat::Mat3Multiply(esat::Mat3Scale(fuel1.escalar, fuel1.escalar), matIdentity2);
        matIdentity3 = esat::Mat3Multiply(esat::Mat3Scale(fuel1.escalar, fuel1.escalar), matIdentity3);
        matIdentity4 = esat::Mat3Multiply(esat::Mat3Scale(fuel1.escalar, fuel1.escalar), matIdentity4);

        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[24].x +5, tr_circle[24].y-12), matIdentity);
        matIdentity2 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[30].x +5, tr_circle[30].y-12), matIdentity2);
        matIdentity3 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[50].x -60, tr_circle[50].y-12), matIdentity3);
        matIdentity4 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[57].x -10, tr_circle[57].y-12), matIdentity4);

        esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(fuel1.map + i));
        esat::Vec3 tmp2 = esat::Mat3TransformVec3(matIdentity2, *(fuel1.map + i));
        esat::Vec3 tmp3 = esat::Mat3TransformVec3(matIdentity3, *(fuel1.map + i));
        esat::Vec3 tmp4 = esat::Mat3TransformVec3(matIdentity4, *(fuel1.map + i));
        tr_fuel[i] = {tmp.x, tmp.y};
        tr_fuel2[i] = {tmp2.x, tmp2.y};
        tr_fuel3[i] = {tmp3.x, tmp3.y};
        tr_fuel4[i] = {tmp4.x, tmp4.y};
        // printf("Fuel X-> %f Y->%f\n",tmp.x,tmp.y);
    }


    //Puntos para el puntero de las colisiones
    if(scalate){
        for (int i = 0; i < 91; i++){
            *(points_tmp_map1 + 2 * i) = tr_circle[i].x;
            *(points_tmp_map1 + 2 * i + 1) = tr_circle[i].y;
        }
        for (int i = 0; i < 4; i++){
            *(fuel1.points + i * 2) =tr_fuel[i].x;
            *(fuel1.points + i * 2 + 1) =tr_fuel[i].y;

            *(fuel2.points + i * 2) =tr_fuel2[i].x;
            *(fuel2.points + i * 2 + 1) =tr_fuel2[i].y;

            *(fuel3.points + i * 2) =tr_fuel3[i].x;
            *(fuel3.points + i * 2 + 1) =tr_fuel3[i].y;

            *(fuel4.points + i * 2) =tr_fuel4[i].x;
            *(fuel4.points + i * 2 + 1) =tr_fuel4[i].y;
        }
        
        for (int i = 0; i < 4; i++){
            //Turret1
            //Base
            *(turret1_points + i * 2) = tr_turret11[i].x;
            *(turret1_points + i * 2 + 1) = tr_turret11[i].y;
            //Head
            *(turret1_points + 4 + i * 2) = tr_turret12[i+4].x;
            *(turret1_points + 4 + i * 2 + 1) = tr_turret12[i+4].y;

            //Turret2
            //Base
            *(turret2_points + i * 2) = tr_turret21[i].x;
            *(turret2_points + i * 2 + 1) = tr_turret21[i].y;
            //Head
            *(turret2_points + 4 + i * 2) = tr_turret22[i+4].x;
            *(turret2_points + 4 + i * 2 + 1) = tr_turret22[i+4].y;

            //Turret3
            // //Base
            *(turret3_points + i * 2) = tr_turret31[i].x;
            *(turret3_points + i * 2 + 1) = tr_turret31[i].y;
            // //Head
            *(turret3_points + 4 + i * 2) = tr_turret32[i+4].x;
            *(turret3_points + 4 + i * 2 + 1) = tr_turret32[i+4].y;

            //Turret4
            // //Base
            *(turret4_points + i * 2) = tr_turret41[i].x;
            *(turret4_points + i * 2 + 1) = tr_turret41[i].y;
            // //Head
            *(turret4_points + 4 + i * 2) = tr_turret42[i+4].x;
            *(turret4_points + 4 + i * 2 + 1) = tr_turret42[i+4].y;
            
            //Turret5
            // //Base
            *(turret5_points + i * 2) = tr_turret51[i].x;
            *(turret5_points + i * 2 + 1) = tr_turret51[i].y;
            // //Head
            *(turret5_points + 4 + i * 2) = tr_turret52[i+4].x;
            *(turret5_points + 4 + i * 2 + 1) = tr_turret52[i+4].y;

            //Turret6
            // //Base
            *(turret6_points + i * 2) = tr_turret61[i].x;
            *(turret6_points + i * 2 + 1) = tr_turret61[i].y;
            // //Head
            *(turret6_points + 4 + i * 2) = tr_turret62[i+4].x;
            *(turret6_points + 4 + i * 2 + 1) = tr_turret62[i+4].y;
           
            //Turret7
            //Base
            *(turret7_points + i * 2) = tr_turret71[i].x;
            *(turret7_points + i * 2 + 1) = tr_turret71[i].y;
            //Head
            *(turret7_points + 4 + i * 2) = tr_turret72[i+4].x;
            *(turret7_points + 4 + i * 2 + 1) = tr_turret72[i+4].y;

            //Turret8
            //Base
            *(turret8_points + i * 2) = tr_turret81[i].x;
            *(turret8_points + i * 2 + 1) = tr_turret81[i].y;
            //Head
            *(turret8_points + 4 + i * 2) = tr_turret82[i+4].x;
            *(turret8_points + 4 + i * 2 + 1) = tr_turret82[i+4].y;
        }
    }
    
    esat::DrawSetStrokeColor(color.r, color.g, color.b);
    esat::DrawPath(&tr_circle[0].x,size);

    esat::DrawSetStrokeColor(Rojo.r, Rojo.g, Rojo.b);
    esat::DrawSetFillColor(0, 0, 0);
    if(turret1.vivo){
        esat::DrawPath(&tr_turret11[0].x, 4);
        esat::DrawSolidPath(&tr_turret12[0].x, 4);
    }

    if(turret2.vivo){
        esat::DrawPath(&tr_turret21[0].x, 4);
        esat::DrawSolidPath(&tr_turret22[0].x, 4);
    }
    if(turret3.vivo){
        esat::DrawPath(&tr_turret31[0].x, 4);
        esat::DrawSolidPath(&tr_turret32[0].x, 4);
    }
    if(turret4.vivo){
        esat::DrawPath(&tr_turret41[0].x, 4);
        esat::DrawSolidPath(&tr_turret42[0].x, 4);
    }
    if(turret5.vivo){
        esat::DrawPath(&tr_turret51[0].x, 4);
        esat::DrawSolidPath(&tr_turret52[0].x, 4);
    }
    if(turret6.vivo){
        esat::DrawPath(&tr_turret61[0].x, 4);
        esat::DrawSolidPath(&tr_turret62[0].x, 4);
    }
    
    if(turret7.vivo){
        esat::DrawPath(&tr_turret71[0].x, 4);
        esat::DrawSolidPath(&tr_turret72[0].x, 4);
    }

    if(turret8.vivo){
        esat::DrawPath(&tr_turret81[0].x, 4);
        esat::DrawSolidPath(&tr_turret82[0].x, 4);
    }

    esat::DrawSetStrokeColor(Azul.r, Azul.g, Azul.b);
    if(!fuel1.obtained)esat::DrawPath(&tr_fuel[0].x, 4);
    if(!fuel2.obtained)esat::DrawPath(&tr_fuel2[0].x, 4);
    if(!fuel3.obtained)esat::DrawPath(&tr_fuel3[0].x, 4);
    if(!fuel4.obtained)esat::DrawPath(&tr_fuel4[0].x, 4);
}

void DrawFigure(TMap *m, int size, bool scalate = true){
    // const int sizeConst = size;
    //  if(scalate)m->escalar += 5.0f;
    //escalar tiene que llegar a 731

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

    if(scalate){
        m->escalar+=5;
    }
    esat::Vec2 tr_circle[49];
     for (int i = 0; i < size; i++){
         // Scalar cada mat3
         esat::Mat3 matIdentity = esat::Mat3Identity();
        //  esat::Vec3 vecAux = {(m.map + i)->x, (m.map + i)->y, (m.map + i)->z};

        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(m->escalar, m->escalar), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(CENTROX, CENTROY), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(85.0f, 11.0f), matIdentity);
         esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(m->map+i) );
         tr_circle[i] = {tmp.x, tmp.y};
        
    }

    //Puntos para el puntero de las colisiones
    if(scalate){
        for (int i = 0; i < 48; i++){
            *(points_tmp_map2 + 2 * i) = tr_circle[i].x;
            *(points_tmp_map2 + 2 * i + 1) = tr_circle[i].y;
        }
    }
    esat::DrawSetStrokeColor(Verde.r, Verde.g, Verde.b);
    // esat::DrawSetFillColor(0,0,0);
    esat::DrawPath(&tr_circle[0].x,size);
}

void DrawFigure3(TMap *m, int size, bool scalate = true, TColor color = Verde){
    // const int sizeConst = size;
    //  if(scalate)m->escalar += 5.0f;
    //escalar tiene que llegar a 731
    
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
    
    // printf(" X-> %f Y-> %f\n", xPrueba,YPrueba);
    if(esat::IsKeyPressed('T'))m->escalar++;

    // printf("Escalar-> %f\n",m->escalar);
    if(scalate){
        m->escalar+=5;
    }
    esat::Vec2 tr_circle[74];
    for (int i = 0; i < size; i++){
         // Scalar cada mat3
         esat::Mat3 matIdentity = esat::Mat3Identity();
        //  esat::Vec3 vecAux = {(m.map + i)->x, (m.map + i)->y, (m.map + i)->z};

        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(m->escalar, m->escalar), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(CENTROX, CENTROY), matIdentity);
        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(85.0f, 11.0f), matIdentity);
         esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(m->map+i) );
         tr_circle[i] = {tmp.x, tmp.y};
        
    }

    //Puntos para el puntero de las colisiones
    if(scalate){
        for (int i = 0; i < 74; i++){
            *(points_tmp_map2 + 2 * i) = tr_circle[i].x;
            *(points_tmp_map2 + 2 * i + 1) = tr_circle[i].y;
        }
    }
    esat::DrawSetStrokeColor(color.r, color.g, color.b);
    // esat::DrawSetFillColor(0,0,0);
    esat::DrawPath(&tr_circle[0].x,size);

}

int bombFpsCounter = 0;

void DrawTimeLeft(){
    esat::DrawText(246.0f,397.0f,"ESCAPE TIME");
    
    // float tiempo = esat::Time();
    // tiempo /= 1000;
    // player.timeLeft = 29 - tiempo ;


    bombFpsCounter++;
    if(bombFpsCounter%fps == 0){
        player.timeLeft--;
    }

    char *aux;
    aux = IntToAscii(player.timeLeft, false);
    esat::DrawText(246.0f, 457.0f, aux);
    free(aux);

    esat::DrawText(318.0f,560.0f,"SHOOT REACTOR");
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
TMap map3Bomb;

void CreateMaps(){

    //Map1
    map1.map = nullptr;
    map1.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*91);
    map1.size = 91;
    //Fuel
    fuel1.map = nullptr;
    fuel1.map = (esat::Vec3 *)malloc(sizeof(esat::Vec3) * 4);
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

    //Turrets
    turret1.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*8);
    turret1.points = (float*) malloc(sizeof(float)*16);
    turret1.vivo = true;
    turret1.disparos = (TDisparo*) malloc(sizeof(TDisparo)*4);
    (turret1.disparos)->disparando = false;
    (turret1.disparos + 1)->disparando = false;
    (turret1.disparos + 2)->disparando = false;
    (turret1.disparos + 3)->disparando = false;


    (turret1.map+0)->x = 110.0f;(turret1.map+0)->y = 216.0f;(turret1.map+0)->z = 1.0f;
    (turret1.map+1)->x = 124.0f;(turret1.map+1)->y = 217.0f;(turret1.map+1)->z = 1.0f;
    (turret1.map+2)->x = 141.0f;(turret1.map+2)->y = 199.0f;(turret1.map+2)->z = 1.0f;
    (turret1.map+3)->x = 141.0f;(turret1.map+3)->y = 181.0f;(turret1.map+3)->z = 1.0f;
    (turret1.map+4)->x = 129.0f;(turret1.map+4)->y = 214.0f;(turret1.map+4)->z = 1.0f;
    (turret1.map+5)->x = 138.0f;(turret1.map+5)->y = 205.0f;(turret1.map+5)->z = 1.0f;
    (turret1.map+6)->x = 146.0f;(turret1.map+6)->y = 213.0f;(turret1.map+6)->z = 1.0f;
    (turret1.map+7)->x = 137.0f;(turret1.map+7)->y = 222.0f;(turret1.map+7)->z = 1.0f;

    NormalizeTurret(turret1, 8, 146.0f, 222.0f);

    turret2.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*8);
    turret2.points = (float*) malloc(sizeof(float)*16);
    turret2.vivo = true;
    turret2.disparos = (TDisparo*) malloc(sizeof(TDisparo)*4);
    (turret2.disparos)->disparando = false;
    (turret2.disparos + 1)->disparando = false;
    (turret2.disparos + 2)->disparando = false;
    (turret2.disparos + 3)->disparando = false;

    (turret2.map+0)->x = 110.0f;(turret2.map+0)->y = 216.0f;(turret2.map+0)->z = 1.0f;
    (turret2.map+1)->x = 124.0f;(turret2.map+1)->y = 217.0f;(turret2.map+1)->z = 1.0f;
    (turret2.map+2)->x = 141.0f;(turret2.map+2)->y = 199.0f;(turret2.map+2)->z = 1.0f;
    (turret2.map+3)->x = 141.0f;(turret2.map+3)->y = 181.0f;(turret2.map+3)->z = 1.0f;
    (turret2.map+4)->x = 129.0f;(turret2.map+4)->y = 214.0f;(turret2.map+4)->z = 1.0f;
    (turret2.map+5)->x = 138.0f;(turret2.map+5)->y = 205.0f;(turret2.map+5)->z = 1.0f;
    (turret2.map+6)->x = 146.0f;(turret2.map+6)->y = 213.0f;(turret2.map+6)->z = 1.0f;
    (turret2.map+7)->x = 137.0f;(turret2.map+7)->y = 222.0f;(turret2.map+7)->z = 1.0f;
    NormalizeTurret(turret2, 8, 146.0f, 222.0f);

    turret3.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*8);
    turret3.points = (float*) malloc(sizeof(float)*16);
    turret3.vivo = true;
    turret3.disparos = (TDisparo*) malloc(sizeof(TDisparo)*4);
    (turret3.disparos)->disparando = false;
    (turret3.disparos + 1)->disparando = false;
    (turret3.disparos + 2)->disparando = false;
    (turret3.disparos + 3)->disparando = false;

    (turret3.map+0)->x = 110.0f;(turret3.map+0)->y = 216.0f;(turret3.map+0)->z = 1.0f;
    (turret3.map+1)->x = 124.0f;(turret3.map+1)->y = 217.0f;(turret3.map+1)->z = 1.0f;
    (turret3.map+2)->x = 141.0f;(turret3.map+2)->y = 199.0f;(turret3.map+2)->z = 1.0f;
    (turret3.map+3)->x = 141.0f;(turret3.map+3)->y = 181.0f;(turret3.map+3)->z = 1.0f;
    (turret3.map+4)->x = 129.0f;(turret3.map+4)->y = 214.0f;(turret3.map+4)->z = 1.0f;
    (turret3.map+5)->x = 138.0f;(turret3.map+5)->y = 205.0f;(turret3.map+5)->z = 1.0f;
    (turret3.map+6)->x = 146.0f;(turret3.map+6)->y = 213.0f;(turret3.map+6)->z = 1.0f;
    (turret3.map+7)->x = 137.0f;(turret3.map+7)->y = 222.0f;(turret3.map+7)->z = 1.0f;
    NormalizeTurret(turret3, 8, 146.0f, 222.0f);

    turret4.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*8);
    turret4.points = (float*) malloc(sizeof(float)*16);
    turret4.vivo = true;
    turret4.disparos = (TDisparo*) malloc(sizeof(TDisparo)*4);
    (turret4.disparos)->disparando = false;
    (turret4.disparos + 1)->disparando = false;
    (turret4.disparos + 2)->disparando = false;
    (turret4.disparos + 3)->disparando = false;

    (turret4.map+0)->x = 110.0f;(turret4.map+0)->y = 216.0f;(turret4.map+0)->z = 1.0f;
    (turret4.map+1)->x = 124.0f;(turret4.map+1)->y = 217.0f;(turret4.map+1)->z = 1.0f;
    (turret4.map+2)->x = 141.0f;(turret4.map+2)->y = 199.0f;(turret4.map+2)->z = 1.0f;
    (turret4.map+3)->x = 141.0f;(turret4.map+3)->y = 181.0f;(turret4.map+3)->z = 1.0f;
    (turret4.map+4)->x = 129.0f;(turret4.map+4)->y = 214.0f;(turret4.map+4)->z = 1.0f;
    (turret4.map+5)->x = 138.0f;(turret4.map+5)->y = 205.0f;(turret4.map+5)->z = 1.0f;
    (turret4.map+6)->x = 146.0f;(turret4.map+6)->y = 213.0f;(turret4.map+6)->z = 1.0f;
    (turret4.map+7)->x = 137.0f;(turret4.map+7)->y = 222.0f;(turret4.map+7)->z = 1.0f;
    NormalizeTurret(turret4, 8, 146.0f, 222.0f);

    turret5.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*8);
    turret5.points = (float*) malloc(sizeof(float)*16);
    turret5.vivo = true;
    turret5.disparos = (TDisparo*) malloc(sizeof(TDisparo)*4);
    (turret5.disparos)->disparando = false;
    (turret5.disparos + 1)->disparando = false;
    (turret5.disparos + 2)->disparando = false;
    (turret5.disparos + 3)->disparando = false;

    (turret5.map+0)->x = 110.0f;(turret5.map+0)->y = 216.0f;(turret5.map+0)->z = 1.0f;
    (turret5.map+1)->x = 124.0f;(turret5.map+1)->y = 217.0f;(turret5.map+1)->z = 1.0f;
    (turret5.map+2)->x = 141.0f;(turret5.map+2)->y = 199.0f;(turret5.map+2)->z = 1.0f;
    (turret5.map+3)->x = 141.0f;(turret5.map+3)->y = 181.0f;(turret5.map+3)->z = 1.0f;
    (turret5.map+4)->x = 129.0f;(turret5.map+4)->y = 214.0f;(turret5.map+4)->z = 1.0f;
    (turret5.map+5)->x = 138.0f;(turret5.map+5)->y = 205.0f;(turret5.map+5)->z = 1.0f;
    (turret5.map+6)->x = 146.0f;(turret5.map+6)->y = 213.0f;(turret5.map+6)->z = 1.0f;
    (turret5.map+7)->x = 137.0f;(turret5.map+7)->y = 222.0f;(turret5.map+7)->z = 1.0f;
    NormalizeTurret(turret5, 8, 146.0f, 222.0f);

    turret6.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*8);
    turret6.points = (float*) malloc(sizeof(float)*16);
    turret6.vivo = true;
    turret6.disparos = (TDisparo*) malloc(sizeof(TDisparo)*4);
    (turret6.disparos)->disparando = false;
    (turret6.disparos + 1)->disparando = false;
    (turret6.disparos + 2)->disparando = false;
    (turret6.disparos + 3)->disparando = false;

    (turret6.map+0)->x = 110.0f;(turret6.map+0)->y = 216.0f;(turret6.map+0)->z = 1.0f;
    (turret6.map+1)->x = 124.0f;(turret6.map+1)->y = 217.0f;(turret6.map+1)->z = 1.0f;
    (turret6.map+2)->x = 141.0f;(turret6.map+2)->y = 199.0f;(turret6.map+2)->z = 1.0f;
    (turret6.map+3)->x = 141.0f;(turret6.map+3)->y = 181.0f;(turret6.map+3)->z = 1.0f;
    (turret6.map+4)->x = 129.0f;(turret6.map+4)->y = 214.0f;(turret6.map+4)->z = 1.0f;
    (turret6.map+5)->x = 138.0f;(turret6.map+5)->y = 205.0f;(turret6.map+5)->z = 1.0f;
    (turret6.map+6)->x = 146.0f;(turret6.map+6)->y = 213.0f;(turret6.map+6)->z = 1.0f;
    (turret6.map+7)->x = 137.0f;(turret6.map+7)->y = 222.0f;(turret6.map+7)->z = 1.0f;
    NormalizeTurret(turret6, 8, 146.0f, 222.0f);

    turret7.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*8);
    turret7.points = (float*) malloc(sizeof(float)*16);
    turret7.vivo = true;
    turret7.disparos = (TDisparo*) malloc(sizeof(TDisparo)*4);
    (turret7.disparos)->disparando = false;
    (turret7.disparos + 1)->disparando = false;
    (turret7.disparos + 2)->disparando = false;
    (turret7.disparos + 3)->disparando = false;

    (turret7.map+0)->x = 110.0f;(turret7.map+0)->y = 216.0f;(turret7.map+0)->z = 1.0f;
    (turret7.map+1)->x = 124.0f;(turret7.map+1)->y = 217.0f;(turret7.map+1)->z = 1.0f;
    (turret7.map+2)->x = 141.0f;(turret7.map+2)->y = 199.0f;(turret7.map+2)->z = 1.0f;
    (turret7.map+3)->x = 141.0f;(turret7.map+3)->y = 181.0f;(turret7.map+3)->z = 1.0f;
    (turret7.map+4)->x = 129.0f;(turret7.map+4)->y = 214.0f;(turret7.map+4)->z = 1.0f;
    (turret7.map+5)->x = 138.0f;(turret7.map+5)->y = 205.0f;(turret7.map+5)->z = 1.0f;
    (turret7.map+6)->x = 146.0f;(turret7.map+6)->y = 213.0f;(turret7.map+6)->z = 1.0f;
    (turret7.map+7)->x = 137.0f;(turret7.map+7)->y = 222.0f;(turret7.map+7)->z = 1.0f;
    NormalizeTurret(turret7, 8, 146.0f, 222.0f);
    
    turret8.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*8);
    turret8.points = (float*) malloc(sizeof(float)*16);
    turret8.vivo = true;
    turret8.disparos = (TDisparo*) malloc(sizeof(TDisparo)*4);
    (turret8.disparos)->disparando = false;
    (turret8.disparos + 1)->disparando = false;
    (turret8.disparos + 2)->disparando = false;
    (turret8.disparos + 3)->disparando = false;

    (turret8.map+0)->x = 110.0f;(turret8.map+0)->y = 216.0f;(turret8.map+0)->z = 1.0f;
    (turret8.map+1)->x = 124.0f;(turret8.map+1)->y = 217.0f;(turret8.map+1)->z = 1.0f;
    (turret8.map+2)->x = 141.0f;(turret8.map+2)->y = 199.0f;(turret8.map+2)->z = 1.0f;
    (turret8.map+3)->x = 141.0f;(turret8.map+3)->y = 181.0f;(turret8.map+3)->z = 1.0f;
    (turret8.map+4)->x = 129.0f;(turret8.map+4)->y = 214.0f;(turret8.map+4)->z = 1.0f;
    (turret8.map+5)->x = 138.0f;(turret8.map+5)->y = 205.0f;(turret8.map+5)->z = 1.0f;
    (turret8.map+6)->x = 146.0f;(turret8.map+6)->y = 213.0f;(turret8.map+6)->z = 1.0f;
    (turret8.map+7)->x = 137.0f;(turret8.map+7)->y = 222.0f;(turret8.map+7)->z = 1.0f;
    NormalizeTurret(turret8, 8, 146.0f, 222.0f);

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
    map3.map = (esat::Vec3 *)malloc(sizeof(esat::Vec3) * 74);
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
    map3Bomb.map = (esat::Vec3 *)malloc(sizeof(esat::Vec3) * 11);
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
}

void NormalizeMap(TMap mapa,float lenght,float sizeX, float sizeY){
    for (int i = 0; i < lenght; i++){
        (mapa.map + i)->x -= CENTROX;
        (mapa.map + i)->y -= CENTROY;
        (mapa.map + i)->x /= sizeX;
        (mapa.map + i)->y /= sizeY;
    }
    
}
//**************** End ****************
