char* IntToAscii(int number){
    char *numberToChar = (char*) calloc(7,sizeof(char));
    char *aux = (char*) calloc(7,sizeof(char));
    itoa(number,aux,10);
    //Añadimos los 0 correspondientes segun la puntuacion
    if(number>=10000){
        *numberToChar = '0';
    }else if(number>=1000){
        *numberToChar = '0';
        *(numberToChar+1) = '0';
    }else if(number>=100){
        *numberToChar = '0';
        *(numberToChar+1) = '0';
        *(numberToChar+2) = '0';
    }else if(number>=10){
        *numberToChar = '0';
        *(numberToChar+1) = '0';
        *(numberToChar+2) = '0';
        *(numberToChar+3) = '0';
    }else{
        *numberToChar = '0';
        *(numberToChar+1) = '0';
        *(numberToChar+2) = '0';
        *(numberToChar+3) = '0';
        *(numberToChar+4) = '0';
    }

    strcat(numberToChar,aux);
    free(aux);
    return numberToChar;
    free(numberToChar);
}

void DrawFuel(){
    //Print score
    char *aux;
    aux = IntToAscii(player.score);
    esat::DrawSetFillColor(VerdeScore.r,VerdeScore.g,VerdeScore.b);
    esat::DrawText(200,50,aux);

    //Print fuel
    esat::DrawSetFillColor(VerdeFuel.r,VerdeFuel.g,VerdeFuel.b);
    aux = IntToAscii(player.fuel);
    esat::DrawText(200,70,aux);

    //Print fuel&score text
    esat::DrawSetFillColor(AzulText.r,AzulText.g,AzulText.b);
    esat::DrawText(500,50,"SCORE");
    esat::DrawText(500,70,"FUEL");


    free(aux);



}



void InterfaceActions(){
	esat::DrawSetTextSize(20);
    DrawFuel();
}