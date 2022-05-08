int shootTurretFramesCont = 0;
int nextShootTurretTime = 2;

// Map1 turrets
TTurret turret1;
TTurret turret2;
TTurret turret3;
TTurret turret4;
TTurret turret5;
TTurret turret6;
TTurret turret7;
TTurret turret8;
float *turret1_points = (float *)malloc(sizeof(float) * 8);
float *turret2_points = (float *)malloc(sizeof(float) * 8);
float *turret3_points = (float *)malloc(sizeof(float) * 8);
float *turret4_points = (float *)malloc(sizeof(float) * 8);
float *turret5_points = (float *)malloc(sizeof(float) * 8);
float *turret6_points = (float *)malloc(sizeof(float) * 8);
float *turret7_points = (float *)malloc(sizeof(float) * 8);
float *turret8_points = (float *)malloc(sizeof(float) * 8);

void ShotTurret(TTurret *turret, float *points, int index = 0){
    float x = *(points + 4);
    float y = *(points + 5);
    // printf("Disparo desde X-> %f Y-> %f\n",x,y);
    xemath::Vector2 vecDirector = {player.x -x, player.y - y};
    float modulo = xemath::Vec2Modulo(vecDirector);
    // if(index == 1)printf("Modulo1 -> %f\n",modulo);
    if(modulo<=155.0f){

        vecDirector = xemath::Vec2Normalize(vecDirector);

        if(turret->shootTurretFramesCont%(turret->nextShootTurretTime * fps) == 0){
            //Sorteamos cuando saldrá el proximo disparo
            turret->nextShootTurretTime = 1 + rand() % SHOOT_FRECUENCY;
            printf("Next shot-> %d\n", turret->nextShootTurretTime);
            Disparo(turret->disparos, x, y, vecDirector, Rojo, true);
        }
        // printf("Turret Disparo\n");
        Disparo(turret->disparos, x, y, vecDirector, Rojo, false);

        turret->shootTurretFramesCont++;
    }
}

void DrawTurretsMap1(bool scalating, esat::Vec2 tr_circle[]){
    // Turret1
    esat::Vec2 tr_turret11[4];
    esat::Vec2 tr_turret12[4];

    // Turret2
    esat::Vec2 tr_turret21[4];
    esat::Vec2 tr_turret22[4];

    // Turret3
    esat::Vec2 tr_turret31[4];
    esat::Vec2 tr_turret32[4];

    // Turret4
    esat::Vec2 tr_turret41[4];
    esat::Vec2 tr_turret42[4];

    // Turret5
    esat::Vec2 tr_turret51[4];
    esat::Vec2 tr_turret52[4];

    // Turret6
    esat::Vec2 tr_turret61[4];
    esat::Vec2 tr_turret62[4];

    // Turret7
    esat::Vec2 tr_turret71[4];
    esat::Vec2 tr_turret72[4];

    // Turret8
    esat::Vec2 tr_turret81[4];
    esat::Vec2 tr_turret82[4];

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

    esat::DrawSetStrokeColor(Rojo.r, Rojo.g, Rojo.b);
    esat::DrawSetFillColor(0, 0, 0);
    if (turret1.vivo)
    {
        esat::DrawPath(&tr_turret11[0].x, 4);
        esat::DrawSolidPath(&tr_turret12[0].x, 4);
    }

    if (turret2.vivo)
    {
        esat::DrawPath(&tr_turret21[0].x, 4);
        esat::DrawSolidPath(&tr_turret22[0].x, 4);
    }
    if (turret3.vivo)
    {
        esat::DrawPath(&tr_turret31[0].x, 4);
        esat::DrawSolidPath(&tr_turret32[0].x, 4);
    }
    if (turret4.vivo)
    {
        esat::DrawPath(&tr_turret41[0].x, 4);
        esat::DrawSolidPath(&tr_turret42[0].x, 4);
    }
    if (turret5.vivo)
    {
        esat::DrawPath(&tr_turret51[0].x, 4);
        esat::DrawSolidPath(&tr_turret52[0].x, 4);
    }
    if (turret6.vivo)
    {
        esat::DrawPath(&tr_turret61[0].x, 4);
        esat::DrawSolidPath(&tr_turret62[0].x, 4);
    }

    if (turret7.vivo)
    {
        esat::DrawPath(&tr_turret71[0].x, 4);
        esat::DrawSolidPath(&tr_turret72[0].x, 4);
    }

    if (turret8.vivo)
    {
        esat::DrawPath(&tr_turret81[0].x, 4);
        esat::DrawSolidPath(&tr_turret82[0].x, 4);
    }

    if(scalating){


        for(int i = 0; i < 4; i++){
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
}