bool login = false;

bool inputName = true;
bool inputPasswd = false;

bool showName = true;
bool showPasswd = true;

int inputNameFramesCount = 1;
int inputPasswdFramesCount = 1;

char *userName = (char*) calloc('\0',sizeof(char)*20);
int sizeName = 0;
char *userPasswd = (char*) calloc('\0',sizeof(char)*20);
int sizePasswd = 0;

const int MAX_SIZE = 17;

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

void Login(){

}

void CheckInputSelector(){

    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Enter)){
        if(inputName){
            //Ya ha puesto el nombre, ahora hay que poner la passwd
            inputName = false;
            inputPasswd = true;
        }else if(inputPasswd){
            //Ya ha puesto el name y la passwd, hay que hacer login
            Login();
        }
    }
}

void LoginInputs(){
    CheckInputSelector();
    esat::DrawSetStrokeColor(255, 255, 255);
    esat::DrawText(420, 200, "Nombre");
    float *recuadro = (float*) malloc(sizeof(float)*8);
    *(recuadro) = 420.0f;
    *(recuadro + 1) = 230.0f;

    *(recuadro + 2) = 600.0f;
    *(recuadro + 3) = 230.0f;
    
    *(recuadro + 4) = 600.0f;
    *(recuadro + 5) = 270.0f;

    *(recuadro + 6) = 420.0f;
    *(recuadro + 7) = 270.0f;

    esat::DrawSetStrokeColor(Amarillo.r, Amarillo.g, Amarillo.b);
    esat::DrawSetFillColor(50, 50, 50);
    esat::DrawSolidPath(recuadro,4);


    esat::DrawSetStrokeColor(255, 255, 255);
    esat::DrawText(420, 330, "Password");
    *(recuadro + 1) = 360.0f;
    *(recuadro + 3) = 360.0f;
    *(recuadro + 5) = 400.0f;
    *(recuadro + 7) = 400.0f;

    esat::DrawSetStrokeColor(Amarillo.r, Amarillo.g, Amarillo.b);
    esat::DrawSetFillColor(50, 50, 50);
    esat::DrawSolidPath(recuadro, 4);
    free(recuadro);

    //Check inputs 
    if(inputName){
        //Style
        inputNameFramesCount++;
        if(inputNameFramesCount%(fps/2)==0){
            showName = !showName;
        }
        if(showName)esat::DrawLine(430+sizeName*10,260,430+sizeName*10,240);

        //Name
        char letra = esat::GetNextPressedKey();
        if(letra!=0){
            //He escrito algo
            // printf("%c",letra);
            if(sizeName<MAX_SIZE){
                *(userName+sizeName) = letra;
                sizeName++;
            }
            esat::ResetBufferdKeyInput();
        }
    }else if(inputPasswd){
        inputPasswdFramesCount++;
        if(inputPasswdFramesCount%(fps/2)==0){
            showPasswd = !showPasswd;
        }
        if(showPasswd)esat::DrawLine(430+sizePasswd*10,370,430+sizePasswd*10,390);
        //Name
        char letra = esat::GetNextPressedKey();
        if(letra!=0){
            //He escrito algo
            // printf("%c",letra);
            if(sizePasswd<MAX_SIZE){
                *(userPasswd+sizePasswd) = letra;
                sizePasswd++;
            }
            esat::ResetBufferdKeyInput();
        }
    }

    printf("%s\n",userName);
    esat::DrawSetTextSize(20);
    esat::DrawSetFillColor(0,255,0);
    // esat::DrawSetFillColor(0,0,0);
    esat::DrawText(430,260,userName);
    esat::DrawText(430,390,userPasswd);
    // esat::DrawSetFillColor(0,0,0);
}

void Intro(){
    esat::DrawSetFillColor(AzulText.r, AzulText.g, AzulText.b);
    esat::DrawText(420,200,"GAME OVER");
    esat::DrawText(410,240,"INSERT COIN");
    esat::DrawText(400,280,"1 COIN 1 PLAY");
    //Mostrar 10 mejores
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
    if(!login){
        LoginInputs();
    }else{
        DrawFuel();
        DrawVidas();
        if(intro)Intro();
        if(!intro && interfaz)Interface();
    }
}

void FreePointers(){
    
    free(map2.map);
    free(points_tmp_map1);
    free(points_tmp_map2);
    free(points_tmp_map3);
    free(enemi1.disparos);
    free(map1.map);
    free(fuel1.points);
    free(fuel2.points);
    free(fuel3.points);
    free(fuel4.points);

    free(turret1_points);
    free(turret2_points);
    free(turret3_points);
    free(turret4_points);
    free(turret5_points);
    free(turret6_points);
    free(turret7_points);
    free(turret8_points);

    free(turret1.disparos);
    free(turret2.disparos);
    free(turret3.disparos);
    free(turret4.disparos);
    free(turret5.disparos);
    free(turret6.disparos);
    free(turret7.disparos);
    free(turret8.disparos);

    free(turret2.points);
    free(turret3.points);
    free(turret4.points);
    free(turret5.points);
    free(turret6.points);
    free(turret7.points);
    free(turret8.points);
    // free(Fuel1New);
}