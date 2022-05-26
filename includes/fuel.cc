esat::Vec2 tr_fuel[4];
esat::Vec2 tr_fuel2[4];
esat::Vec2 tr_fuel3[4];
esat::Vec2 tr_fuel4[4];

//Map1
TFuelMat fuel1;
TFuelMat fuel2;
TFuelMat fuel3;
TFuelMat fuel4;

//Map2
TFuelMat fuel5;
TFuelMat fuel6;
TFuelMat fuel7;
TFuelMat fuel8;

int temporalINTfuel = 0;
float temporalFloatturret = 0.0f;

void DrawFuelMap1(bool scalating, esat::Vec2 tr_circle[]){

    //El escalar de fuel tiene que llegar a 30
    if(fuel1.escalar<30)fuel1.escalar+=0.3f;
    if(fuel2.escalar<30)fuel2.escalar+=0.3f;
    if(fuel3.escalar<30)fuel3.escalar+=0.3f;
    if(fuel4.escalar<30)fuel4.escalar+=0.3f;

    //Drawing Fuel
    for (int i = 0; i < 4; i++){
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
    }


    if(scalating){
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
    }

    esat::DrawSetStrokeColor(Azul.r, Azul.g, Azul.b);
    if(!fuel1.obtained)esat::DrawPath(&tr_fuel[0].x, 4);
    if(!fuel2.obtained)esat::DrawPath(&tr_fuel2[0].x, 4);
    if(!fuel3.obtained)esat::DrawPath(&tr_fuel3[0].x, 4);
    if(!fuel4.obtained)esat::DrawPath(&tr_fuel4[0].x, 4);
}
void DrawFuelMap2(bool scalating, esat::Vec2 tr_circle[]){

    if(esat::IsKeyDown('P'))temporalINTfuel++;
    if(esat::IsKeyDown('O'))temporalINTfuel--;
    if(esat::IsKeyPressed('P'))temporalFloatturret += 0.5f;
    if(esat::IsKeyPressed('O'))temporalFloatturret -= 0.5f;

    //El escalar de fuel tiene que llegar a 30
    if(fuel5.escalar<30)fuel5.escalar+=0.3f;
    if(fuel6.escalar<30)fuel6.escalar+=0.3f;
    if(fuel7.escalar<30)fuel7.escalar+=0.3f;
    if(fuel8.escalar<30)fuel8.escalar+=0.3f;

    //Drawing Fuel
    for (int i = 0; i < 4; i++){
        esat::Mat3 matIdentity = esat::Mat3Identity();
        esat::Mat3 matIdentity2 = esat::Mat3Identity();
        esat::Mat3 matIdentity3 = esat::Mat3Identity();
        esat::Mat3 matIdentity4 = esat::Mat3Identity();

        matIdentity = esat::Mat3Multiply(esat::Mat3Scale(fuel5.escalar, fuel5.escalar), matIdentity);
        matIdentity2 = esat::Mat3Multiply(esat::Mat3Scale(fuel5.escalar, fuel5.escalar), matIdentity2);
        matIdentity3 = esat::Mat3Multiply(esat::Mat3Scale(fuel5.escalar, fuel5.escalar), matIdentity3);
        matIdentity4 = esat::Mat3Multiply(esat::Mat3Scale(fuel5.escalar, fuel5.escalar), matIdentity4);

        
        matIdentity2 = esat::Mat3Multiply(esat::Mat3Rotate(180.0f * (3.1415f/180.0f)),matIdentity2);
        matIdentity3 = esat::Mat3Multiply(esat::Mat3Rotate(180.0f * (3.1415f/180.0f)),matIdentity3);


        matIdentity = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[0].x + 5.0f, tr_circle[0].y - 12.0f), matIdentity);
        matIdentity2 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[12].x + 47.0f, tr_circle[12].y + 15.0f), matIdentity2);
        matIdentity3 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[26].x + 53.0f, tr_circle[26].y + 14.5f), matIdentity3);
        matIdentity4 = esat::Mat3Multiply(esat::Mat3Translate(tr_circle[41].x + 16.5f, tr_circle[41].y + - 17.0f), matIdentity4);

        esat::Vec3 tmp = esat::Mat3TransformVec3(matIdentity, *(fuel1.map + i));
        esat::Vec3 tmp2 = esat::Mat3TransformVec3(matIdentity2, *(fuel1.map + i));
        esat::Vec3 tmp3 = esat::Mat3TransformVec3(matIdentity3, *(fuel1.map + i));
        esat::Vec3 tmp4 = esat::Mat3TransformVec3(matIdentity4, *(fuel1.map + i));
        tr_fuel[i] = {tmp.x, tmp.y};
        tr_fuel2[i] = {tmp2.x, tmp2.y};
        tr_fuel3[i] = {tmp3.x, tmp3.y};
        tr_fuel4[i] = {tmp4.x, tmp4.y};
    }


    if(scalating){
        for (int i = 0; i < 4; i++){
            *(fuel5.points + i * 2) =tr_fuel[i].x;
            *(fuel5.points + i * 2 + 1) =tr_fuel[i].y;

            *(fuel6.points + i * 2) =tr_fuel2[i].x;
            *(fuel6.points + i * 2 + 1) =tr_fuel2[i].y;

            *(fuel7.points + i * 2) =tr_fuel3[i].x;
            *(fuel7.points + i * 2 + 1) =tr_fuel3[i].y;

            *(fuel8.points + i * 2) =tr_fuel4[i].x;
            *(fuel8.points + i * 2 + 1) =tr_fuel4[i].y;
        }
    }

    esat::DrawSetStrokeColor(Azul.r, Azul.g, Azul.b);
    if(!fuel5.obtained)esat::DrawPath(&tr_fuel[0].x, 4);
    if(!fuel6.obtained)esat::DrawPath(&tr_fuel2[0].x, 4);
    if(!fuel7.obtained)esat::DrawPath(&tr_fuel3[0].x, 4);
    if(!fuel8.obtained)esat::DrawPath(&tr_fuel4[0].x, 4);
}