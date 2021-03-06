bool introLogo = false;

bool logued = false;

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
const int MAX_USERS_LOADED = 50;
float *pointsLives = (float*) malloc(sizeof(float) * 20);
float *pointsLives1 = (float*) malloc(sizeof(float) * 20);
float *pointsLives2 = (float*) malloc(sizeof(float) * 20);
float *pointsLives3 = (float*) malloc(sizeof(float) * 20);
float *pointsLives4 = (float*) malloc(sizeof(float) * 20);

Persona *users = (Persona*) malloc(sizeof(Persona)*MAX_USERS_LOADED);
int sizePersonas = 0;
int indexLogued = -1;
FILE *fichero;

char *puesto = (char*) calloc('\0',sizeof(char)*4);
char *nombre = (char*) calloc('\0',sizeof(char)*4);
char *puntuacion = (char*) calloc('\0',sizeof(char)*10);

int scalateLogoFramesCount = 1;

void OrdenarUsers(){
    //Bubble short
    for (int j = 0; j < sizePersonas; j++){
        for (int i = 0; i < sizePersonas; i++){
            if((users+i+1)->puntuacion > (users+i)->puntuacion){
                Persona aux = *(users+i); 
                *(users+i) = *(users+i+1);
                *(users+i+1) = aux;
            }
        }
    }
}

void InitVidasPoints(){

    *(pointsLives+0)=175.0f;
    *(pointsLives+1)=23.0f;
    *(pointsLives+2)=163.0f;
    *(pointsLives+3)=45.0f;
    *(pointsLives+4)=166.0f;
    *(pointsLives+5)=55.0f;
    *(pointsLives+6)=171.0f;
    *(pointsLives+7)=55.0f;
    *(pointsLives+8)=175.0f;
    *(pointsLives+9)=48.0f;
    *(pointsLives+10)=178.0f;
    *(pointsLives+11)=54.0f;
    *(pointsLives+12)=182.0f;
    *(pointsLives+13)=54.0f;
    *(pointsLives+14)=187.0f;
    *(pointsLives+15)=45.0f;
    // ----------
    *(pointsLives1+0)=155.0f;
    *(pointsLives1+1)=23.0f;
    *(pointsLives1+2)=143.0f;
    *(pointsLives1+3)=45.0f;
    *(pointsLives1+4)=146.0f;
    *(pointsLives1+5)=55.0f;
    *(pointsLives1+6)=151.0f;
    *(pointsLives1+7)=55.0f;
    *(pointsLives1+8)=155.0f;
    *(pointsLives1+9)=48.0f;
    *(pointsLives1+10)=158.0f;
    *(pointsLives1+11)=54.0f;
    *(pointsLives1+12)=162.0f;
    *(pointsLives1+13)=54.0f;
    *(pointsLives1+14)=167.0f;
    *(pointsLives1+15)=45.0f;
    // ----------
    *(pointsLives2+0)=135.0f;
    *(pointsLives2+1)=23.0f;
    *(pointsLives2+2)=123.0f;
    *(pointsLives2+3)=45.0f;
    *(pointsLives2+4)=126.0f;
    *(pointsLives2+5)=55.0f;
    *(pointsLives2+6)=131.0f;
    *(pointsLives2+7)=55.0f;
    *(pointsLives2+8)=135.0f;
    *(pointsLives2+9)=48.0f;
    *(pointsLives2+10)=138.0f;
    *(pointsLives2+11)=54.0f;
    *(pointsLives2+12)=142.0f;
    *(pointsLives2+13)=54.0f;
    *(pointsLives2+14)=147.0f;
    *(pointsLives2+15)=45.0f;
    // ----------
    *(pointsLives3+0)=115.0f;
    *(pointsLives3+1)=23.0f;
    *(pointsLives3+2)=103.0f;
    *(pointsLives3+3)=45.0f;
    *(pointsLives3+4)=106.0f;
    *(pointsLives3+5)=55.0f;
    *(pointsLives3+6)=111.0f;
    *(pointsLives3+7)=55.0f;
    *(pointsLives3+8)=115.0f;
    *(pointsLives3+9)=48.0f;
    *(pointsLives3+10)=118.0f;
    *(pointsLives3+11)=54.0f;
    *(pointsLives3+12)=122.0f;
    *(pointsLives3+13)=54.0f;
    *(pointsLives3+14)=127.0f;
    *(pointsLives3+15)=45.0f;
    // ----------
    *(pointsLives4+0)=95.0f;
    *(pointsLives4+1)=23.0f;
    *(pointsLives4+2)=83.0f;
    *(pointsLives4+3)=45.0f;
    *(pointsLives4+4)=86.0f;
    *(pointsLives4+5)=55.0f;
    *(pointsLives4+6)=91.0f;
    *(pointsLives4+7)=55.0f;
    *(pointsLives4+8)=95.0f;
    *(pointsLives4+9)=48.0f;
    *(pointsLives4+10)=98.0f;
    *(pointsLives4+11)=54.0f;
    *(pointsLives4+12)=102.0f;
    *(pointsLives4+13)=54.0f;
    *(pointsLives4+14)=107.0f;
    *(pointsLives4+15)=45.0f;
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
    esat::DrawText(200,90,aux);

    //Print fuel&score text
    esat::DrawSetFillColor(AzulText.r,AzulText.g,AzulText.b);
    esat::DrawText(500,50,"SCORE");
    esat::DrawText(500,90,"FUEL");
    free(aux);
}

void DrawVidas(){
    
        esat::DrawSetStrokeColor(0,0,255);
        esat::DrawSetFillColor(0,0,0,0);

         switch (player.vidas){
         case 1:
             esat::DrawSolidPath(pointsLives,8);
         break;
         case 2:
             esat::DrawSolidPath(pointsLives,8);
             esat::DrawSolidPath(pointsLives1,8);
         break;
         case 3:
             esat::DrawSolidPath(pointsLives,8);
             esat::DrawSolidPath(pointsLives1,8);
             esat::DrawSolidPath(pointsLives2,8);
         break;
         case 4:
             esat::DrawSolidPath(pointsLives,8);
             esat::DrawSolidPath(pointsLives1,8);
             esat::DrawSolidPath(pointsLives2,8);
             esat::DrawSolidPath(pointsLives3,8);
         break;
         case 5:
            esat::DrawSolidPath(pointsLives,8);
            esat::DrawSolidPath(pointsLives1,8);
            esat::DrawSolidPath(pointsLives2,8);
            esat::DrawSolidPath(pointsLives3,8);
            esat::DrawSolidPath(pointsLives4,8);
         break;

         default:
             break;
         }
    
}

void Login(){
    sizePersonas = LoadToMemory(users);
    if(sizePersonas>0)printf("Usuarios cargados\n");

    for (int i = 0; i < sizePersonas; i++){
        //Buscamos la persona con ese nombre
        // printf("Comparando %s con %s\n",(users + i)->nombre,userName);
        // const char[20] = *(users + i)->nombre;
        if (strcmp(userName,(users + i)->nombre) == 0){
            //Usuario encontrado
            // printf("Comparando %s con %s\n", (users + i)->password, userPasswd);

            if(strcmp(userPasswd,(users + i)->password) == 0){
                //Usuario y contrase??a correctos
                logued = true;
                credits = (users+i)->creditos;
                indexLogued = i;
                OrdenarUsers();
                // printf("Creditos del user logueado-> %d\n",(users+i)->creditos);
            }else{
                // printf("Contrase??a incorrecta\n");
            }
        }
    }
    

}

void AddCredits(){
    //En el bloque de personas, modifico los creditos de la persona logueada
    (users+indexLogued)->creditos = credits;

    //Una vez modificados, solo tengo que volvar todos los usuarios en el fichero binario auxiliar (por si acaso hay algun fallo a mitad, no borrar todos los usuarios)
    fichero = fopen("./includes/usuariosAux.dat", "wb");

    for (int i = 0; i < sizePersonas; i++){
        fwrite((users+i),sizeof(Persona),1,fichero);
    }

    //Una vez ya tengo todos los usuarios en el nuevo fichero, me cargo el anterior y renombro el auxiliar
    remove("./includes/usuarios.dat");
    fclose(fichero);
    rename("./includes/usuariosAux.dat","./includes/usuarios.dat");


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
        if(esat::IsSpecialKeyDown(esat::kSpecialKey_Backspace)){
            if(sizeName>0){
                *(userName+strlen(userName)-1) = '\0';
                sizeName--;
            }
        }
        if(letra!=0){
            //He escrito algo
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
        if(esat::IsSpecialKeyDown(esat::kSpecialKey_Backspace)){
            if(sizePasswd>0){
                *(userPasswd+strlen(userPasswd)-1) = '\0';
                sizePasswd--;
            }else{
                inputName = true;
                inputPasswd = false;
            }
        }
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

    // printf("%s\n",userName);
    esat::DrawSetTextSize(20);
    esat::DrawSetFillColor(0,255,0);
    // esat::DrawSetFillColor(0,0,0);
    esat::DrawText(430,260,userName);
    esat::DrawText(430,390,userPasswd);
    // esat::DrawSetFillColor(0,0,0);
}

void NormalizeLogo(){
    NormalizeLogoMat(logoG,logoG.size,301,210);
    NormalizeLogoMat(logoR,logoR.size,368,199);
    NormalizeLogoMat(logoA,logoA.size,451,189);
    NormalizeLogoMat(logoV,logoV.size,510,182);
    NormalizeLogoMat(logoI,logoI.size,541,189);
    NormalizeLogoMat(logoT,logoT.size,607,198);
    NormalizeLogoMat(logoA2,logoA2.size,706,201);
    NormalizeLogoMat(logoR2,logoR2.size,813,215);
}

void IntroLogo(){

    if(scalateLogoFramesCount <= 100){
        // printf("mmmm %d\n",scalateLogoFramesCount);
        DrawLogo(&logoG,logoG.size,true);
        DrawLogo(&logoR,logoR.size,true,7,8);
        DrawLogo(&logoA,logoA.size,true);
        DrawLogo(&logoV,logoV.size,true);
        DrawLogo(&logoI,logoI.size,true);
        DrawLogo(&logoT,logoT.size,true);
        DrawLogo(&logoA2,logoA2.size,true);
        DrawLogo(&logoR2,logoR2.size,true);
        scalateLogoFramesCount++;
        // if(scalateMatFramesCount>=90)scalating = false;
    }else{
        DrawLogo(&logoG,logoG.size,false);
        DrawLogo(&logoR,logoR.size,false,7,8);
        DrawLogo(&logoA,logoA.size,false,7,8);
        DrawLogo(&logoV,logoV.size,false);
        DrawLogo(&logoI,logoI.size,false);
        DrawLogo(&logoT,logoT.size,false);
        DrawLogo(&logoA2,logoA2.size,false,7,8);
        DrawLogo(&logoR2,logoR2.size,false,7,8);

        esat::DrawSetStrokeColor(Rojo.r, Rojo.g, Rojo.b);
        esat::DrawSetFillColor(Rojo.r, Rojo.g, Rojo.b);
        esat::DrawText(CENTROX-220,CENTROY+100,"PRESS ENTER TO PLAY");
    }


    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Enter)){
        introLogo = true;
    }

}

void Intro(){
    esat::DrawSetFillColor(AzulText.r, AzulText.g, AzulText.b);
    esat::DrawText(420,200,"GAME OVER");
    esat::DrawText(410,240,"INSERT COIN");
    esat::DrawText(400,280,"1 COIN 1 PLAY");
    //Mostrar 10 mejores

    for (int i = 0; i < 10; i++){
        // printf("%d?? Nombre->%s Puntuacion->%d\n",i,(users+i)->nombre,(users+i)->puntuacion);
        
        
        puesto = itoa(i+1,puesto,10);
        *nombre = *(users+i)->nombre;
        *(nombre+1) = *((users+i)->nombre+1);
        *(nombre+2) = *((users+i)->nombre+2);
        puntuacion = itoa((users+i)->puntuacion,puntuacion,10);

        esat::DrawSetFillColor(Rojo.r, Rojo.g, Rojo.b);
        esat::DrawText(400,380+(i*40),puesto);
        esat::DrawText(450,380+(i*40),nombre);

        esat::DrawSetFillColor(Azul.r, Azul.g, Azul.b);
        esat::DrawText(520,380+(i*40),puntuacion);

    }

    
    
    
    
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
        intro = false;
        InitEnemies();
    }
}

void Interface(){
    esat::DrawSetFillColor(AzulText.r, AzulText.g, AzulText.b);
    esat::DrawText(420,200,"GAME OVER");
    esat::DrawText(410,240,"PRESS ENTER");
    char *numberToCharCredits = (char*) malloc(sizeof(char)*30);
    char *aux = (char*) calloc('\0',sizeof(char)*5);
    *numberToCharCredits = 'C';
    *(numberToCharCredits+1) = 'R';
    *(numberToCharCredits+2) = 'E';
    *(numberToCharCredits+3) = 'D';
    *(numberToCharCredits+4) = 'I';
    *(numberToCharCredits+5) = 'T';
    *(numberToCharCredits+6) = 'S';
    *(numberToCharCredits+7) = ' ';
    *(numberToCharCredits+8) = '\0';
    // if(credits<100 && credits>=10){
    //     *(numberToCharCredits+8) = '0';
    // }else if(credits<10){
    //     *(numberToCharCredits+8) = '0';
    //     *(numberToCharCredits+9) = '0';
    // }
    itoa(credits,aux,10);
    strcat(numberToCharCredits,aux);
    esat::DrawText(400,280,numberToCharCredits);
    free(aux);
    free(numberToCharCredits);




    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
        credits++;
    }
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Enter)){
        AddCredits();
        interfaz = false;
        player.score = 0;

    }

}

void InterfaceActions(){
	esat::DrawSetTextSize(38);
    if(!introLogo){
        IntroLogo();
    }else if(!logued && !debug){
        LoginInputs();
    }else{
        logued = true;
        DrawFuel();
        DrawVidas();

        if(intro)Intro();
        if(!intro && interfaz)Interface();

        if(player.vidas <= 0){
            InitPlayer();
	        CreateMaps();
	        InitVidasPoints();
            ReturnMenu();
            map1Complete = false;
            map2Complete = false;
            map5Complete = false;
            credits--;
            player.nivel = 0;
            player.fuel = 10000;
            intro = true;
            interfaz = true;
            player.vidas = 5;
            figure1pointsCheck = false;
            figure2pointsCheck = false;
            figure3BombapointsCheck = false;
            figure3pointsCheck = false;
            Login();
            if(indexLogued>=0){
                if( player.score > (users+indexLogued)->puntuacion){
                    // printf("Nueva puntuacion maxima de %s, antes->%d ahora->%d\n",(users+indexLogued)->nombre,(users+indexLogued)->puntuacion,player.score);
                    (users+indexLogued)->puntuacion = player.score;
                }
            }

            AddCredits();
            Login();
            OrdenarUsers();
        }
    }
}

void FreePointers(){
    
    free(map2.map);
    free(points_tmp_map1);
    free(points_tmp_map2);
    free(points_tmp_map3);
    free(points_tmp_map2_bomb);
    free(points_tmp_map4);
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

    free(pointsLives);
    free(pointsLives1);
    free(pointsLives2);
    free(pointsLives3);
    free(pointsLives4);

    free(puesto);
    free(nombre);
    free(puntuacion);
    // free(Fuel1New);
}