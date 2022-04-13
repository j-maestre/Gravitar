// TODO te has quedado por aqui, tienes que pintar la figura de la matriz, circle[] es ahora la matriz de los puntos del mapa,
//TODO  es un puntero en vez de un array. Llamar a DrawFigure en geometries.cc

void DrawFigure(esat::Mat3 m){
    esat::Vec2 tr_circle[10];
    for (int i = 0; i < kNPoints; i++){
        esat::Vec3 tmp = esat::Mat3TransformVec3(m,circle[i]);
        tr_circle[i] = { tmp.x, tmp.y };
    }
    esat::DrawSetStrokeColor(255,255,255);
    esat::DrawSetFillColor(0,0,0);
    esat::DrawSolidPath(&tr_circle[0].x,kNPoints);
}

esat::Mat3 UpdateBaseFigure(TMap mapa){
    //Con esto escalo y traslado al centro
    mapa.escalar +=0.02f;
    esat::Mat3 m = esat::Mat3Identity();
    m = esat::Mat3Multiply(esat::Mat3Scale(mapa.escalar,mapa.escalar),m);
    // m = esat::Mat3Multiply(esat::Mat3Rotate(g_angle),m);
    m = esat::Mat3Multiply(esat::Mat3Translate(CENTROX,CENTROY),m);
    // m = esat::Mat3Multiply(esat::Mat3Translate((float) esat::MousePositionX(),(float) esat::MousePositionY()),m);
    return m;
}

//**************** Map2 points **************** 
    TMap map2;
void CreateMap2(){
    map2.map = nullptr;
    map2.map = (esat::Vec3*) malloc(sizeof(esat::Vec3)*48);
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
    (map2.map+22)->x = 797.0f;(map2.map+22)->y = 580.0f;(map2.map+21)->z = 1.0f;
    (map2.map+23)->x = 759.0f;(map2.map+23)->y = 540.0f;(map2.map+21)->z = 1.0f;
    (map2.map+24)->x = 797.0f;(map2.map+24)->y = 487.0f;(map2.map+22)->z = 1.0f;
    (map2.map+25)->x = 773.0f;(map2.map+25)->y = 461.0f;(map2.map+23)->z = 1.0f;
    (map2.map+26)->x = 797.0f;(map2.map+26)->y = 433.0f;(map2.map+24)->z = 1.0f;
    (map2.map+27)->x = 867.0f;(map2.map+27)->y = 433.0f;(map2.map+25)->z = 1.0f;
    (map2.map+28)->x = 892.0f;(map2.map+28)->y = 407.0f;(map2.map+26)->z = 1.0f;
    (map2.map+29)->x = 845.0f;(map2.map+29)->y = 354.0f;(map2.map+27)->z = 1.0f;
    (map2.map+30)->x = 833.0f;(map2.map+30)->y = 354.0f;(map2.map+28)->z = 1.0f;
    (map2.map+31)->x = 772.0f;(map2.map+31)->y = 286.0f;(map2.map+29)->z = 1.0f;
    (map2.map+32)->x = 796.0f;(map2.map+32)->y = 259.0f;(map2.map+30)->z = 1.0f;
    (map2.map+33)->x = 736.0f;(map2.map+33)->y = 260.0f;(map2.map+31)->z = 1.0f;
    (map2.map+34)->x = 701.0f;(map2.map+34)->y = 219.0f;(map2.map+32)->z = 1.0f;
    (map2.map+35)->x = 664.0f;(map2.map+35)->y = 219.0f;(map2.map+33)->z = 1.0f;
    (map2.map+36)->x = 605.0f;(map2.map+36)->y = 57.0f;(map2.map+34)->z = 1.0f;
    (map2.map+37)->x = 510.0f;(map2.map+37)->y = 110.0f;(map2.map+35)->z = 1.0f;
    (map2.map+38)->x = 544.0f;(map2.map+38)->y = 111.0f;(map2.map+36)->z = 1.0f;
    (map2.map+39)->x = 592.0f;(map2.map+39)->y = 164.0f;(map2.map+37)->z = 1.0f;
    (map2.map+40)->x = 546.0f;(map2.map+40)->y = 218.0f;(map2.map+38)->z = 1.0f;
    (map2.map+41)->x = 461.0f;(map2.map+41)->y = 219.0f;(map2.map+39)->z = 1.0f;
    (map2.map+42)->x = 376.0f;(map2.map+42)->y = 204.0f;(map2.map+40)->z = 1.0f;
    (map2.map+43)->x = 413.0f;(map2.map+43)->y = 245.0f;(map2.map+41)->z = 1.0f;
    (map2.map+44)->x = 366.0f;(map2.map+44)->y = 245.0f;(map2.map+42)->z = 1.0f;
    (map2.map+45)->x = 318.0f;(map2.map+45)->y = 300.0f;(map2.map+43)->z = 1.0f;
    (map2.map+46)->x = 293.0f;(map2.map+46)->y = 300.0f;(map2.map+44)->z = 1.0f;
    (map2.map+47)->x = 198.0f;(map2.map+47)->y = 407.0f;(map2.map+45)->z = 1.0f;
    (map2.map+48)->x = 127.0f;(map2.map+48)->y = 407.0f;(map2.map+46)->z = 1.0f;
}

//**************** End ****************
