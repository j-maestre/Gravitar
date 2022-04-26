// TODO normalizar los puntos para poder escalarlos
// const int map2Size = 48;
float xPrueba = 0.0f;
float YPrueba = 0.0f;



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
    
    // printf(" X-> %f Y-> %f\n", xPrueba,YPrueba);
    if(esat::IsKeyPressed('T'))m->escalar++;

    // printf("Escalar-> %f\n",m->escalar);
    if(scalate){
        m->escalar+=5;
    }
    esat::Vec2 tr_circle[49];
     for (int i = 0; i < size; i++){
         // Scalar cada mat3
         esat::Mat3 matIdentity = esat::Mat3Identity();
        //  esat::Vec3 vecAux = {(m.map + i)->x, (m.map + i)->y, (m.map + i)->z};

         matIdentity = esat::Mat3Multiply(esat::Mat3Scale(m->escalar, m->escalar), matIdentity);
        //  matIdentity = esat::Mat3Multiply(esat::Mat3Translate(CENTROX, CENTROY), matIdentity);
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

void DrawFigure3(TMap *m, int size, bool scalate = true){
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
        //  matIdentity = esat::Mat3Multiply(esat::Mat3Translate(CENTROX, CENTROY), matIdentity);
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
    esat::DrawSetStrokeColor(Verde.r, Verde.g, Verde.b);
    // esat::DrawSetFillColor(0,0,0);
    esat::DrawPath(&tr_circle[0].x,size);
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
TMap map2;
TMap map3;
void CreateMaps(){
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

    
}

void NormalizeMap(TMap mapa,float lenght,float sizeX, float sizeY){
    for (int i = 0; i < lenght; i++){
        (mapa.map + i)->x /= sizeX;
        (mapa.map + i)->y /= sizeY;
    }
    
}
//**************** End ****************
