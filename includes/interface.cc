

void DrawFuel(){
    //Print score
    char *aux;
    aux = IntToAscii(player.score);
    esat::DrawSetFillColor(VerdeScore.r,VerdeScore.g,VerdeScore.b);
    esat::DrawText(200,50,aux);

    //Print fuel
    esat::DrawSetFillColor(VerdeFuel.r,VerdeFuel.g,VerdeFuel.b);
    aux = IntToAscii(player.fuel);
    esat::DrawText(200,90,aux);

    //Print fuel&score text
    esat::DrawSetFillColor(AzulText.r,AzulText.g,AzulText.b);
    esat::DrawText(500,50,"SCORE");
    esat::DrawText(500,90,"FUEL");
    free(aux);
}

void DrawVidas(){
    
}

void Intro(){
    esat::DrawText(420,200,"GAME OVER");
    esat::DrawText(410,240,"INSERT COIN");
    esat::DrawText(400,280,"1 COIN 1 PLAY");
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
        intro = false;
        InitEnemies();
    }
}

void Interface(){
    esat::DrawText(420,200,"GAME OVER");
    esat::DrawText(410,240,"PRESS ENTER");
    char *numberToChar = (char*) calloc(11,sizeof(char));
    char *aux = (char*) calloc(3,sizeof(char));
    *numberToChar = 'C';
    *(numberToChar+1) = 'R';
    *(numberToChar+2) = 'E';
    *(numberToChar+3) = 'D';
    *(numberToChar+4) = 'I';
    *(numberToChar+5) = 'T';
    *(numberToChar+6) = 'S';
    *(numberToChar+7) = ' ';
    if(credits<100 && credits>=10){
        *(numberToChar+8) = '0';
    }else if(credits<10){
        *(numberToChar+8) = '0';
        *(numberToChar+9) = '0';
    }
    itoa(credits,aux,10);
    strcat(numberToChar,aux);
    esat::DrawText(400,280,numberToChar);
    free(aux);
    free(numberToChar);




    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Space))credits++;
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Enter)){
        interfaz = false;
    }

}

void InterfaceActions(){
	esat::DrawSetTextSize(38);
    DrawFuel();
    DrawVidas();
    if(intro)Intro();
    if(!intro && interfaz)Interface();
}

void FreePointers(){
    free(pointsNormalized);
    free(points4Normalized);
    free(pointsFuel1Normalized);
    free(pointsFuel2Normalized);
    free(pointsFuel3Normalized);
    free(pointsFuel4Normalized);
    free(Fuel1);
    free(Fuel2);
    free(Fuel3);
    free(Fuel4);
    free(pointsMap1pun);
    free(pointsMap4pun);
    free(points2Map4Original);
    free(points2Map4pun);
    free(points24Normalized);
    free(points3Map4Original);
    free(points3Map4pun);
    free(points34Normalized);
    free(points4Map4Original);
    free(points4Map4pun);
    free(points44Normalized);
    free(map2.map);
    free(points_tmp_map2);
    free(points_tmp_map3);
    free(enemi1.disparos);
    // free(Fuel1New);
}