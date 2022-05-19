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
float *points = (float *)calloc(0, sizeof(float) * 20);
float *points1 = (float *)calloc(0, sizeof(float) * 20);
float *points2 = (float *)calloc(0, sizeof(float) * 20);
float *points3 = (float *)calloc(0, sizeof(float) * 20);
float *points4 = (float *)calloc(0, sizeof(float) * 20);

Persona *users = (Persona*) malloc(sizeof(Persona)*MAX_USERS_LOADED);

void InitVidasPoints(){
    printf("Setting points...\n");

    *(points+0)=215.0f;
    *(points+1)=23.0f;
    *(points+2)=203.0f;
    *(points+3)=45.0f;
    *(points+4)=206.0f;
    *(points+5)=55.0f;
    *(points+6)=211.0f;
    *(points+7)=55.0f;
    *(points+8)=215.0f;
    *(points+9)=48.0f;
    *(points+10)=218.0f;
    *(points+11)=54.0f;
    *(points+12)=222.0f;
    *(points+13)=54.0f;
    *(points+14)=227.0f;
    *(points+15)=45.0f;
    // ----------
    *(points1+0)=195.0f;
    *(points1+1)=23.0f;
    *(points1+2)=183.0f;
    *(points1+3)=45.0f;
    *(points1+4)=186.0f;
    *(points1+5)=55.0f;
    *(points1+6)=191.0f;
    *(points1+7)=55.0f;
    *(points1+8)=195.0f;
    *(points1+9)=48.0f;
    *(points1+10)=198.0f;
    *(points1+11)=54.0f;
    *(points1+12)=202.0f;
    *(points1+13)=54.0f;
    *(points1+14)=207.0f;
    *(points1+15)=45.0f;
    // ----------
    *(points2+0)=175.0f;
    *(points2+1)=23.0f;
    *(points2+2)=163.0f;
    *(points2+3)=45.0f;
    *(points2+4)=166.0f;
    *(points2+5)=55.0f;
    *(points2+6)=171.0f;
    *(points2+7)=55.0f;
    *(points2+8)=175.0f;
    *(points2+9)=48.0f;
    *(points2+10)=178.0f;
    *(points2+11)=54.0f;
    *(points2+12)=182.0f;
    *(points2+13)=54.0f;
    *(points2+14)=187.0f;
    *(points2+15)=45.0f;
    // ----------
    *(points3+0)=155.0f;
    *(points3+1)=23.0f;
    *(points3+2)=143.0f;
    *(points3+3)=45.0f;
    *(points3+4)=146.0f;
    *(points3+5)=55.0f;
    *(points3+6)=151.0f;
    *(points3+7)=55.0f;
    *(points3+8)=155.0f;
    *(points3+9)=48.0f;
    *(points3+10)=158.0f;
    *(points3+11)=54.0f;
    *(points3+12)=162.0f;
    *(points3+13)=54.0f;
    *(points3+14)=167.0f;
    *(points3+15)=45.0f;
    // ----------
    *(points4+0)=135.0f;
    *(points4+1)=23.0f;
    *(points4+2)=123.0f;
    *(points4+3)=45.0f;
    *(points4+4)=126.0f;
    *(points4+5)=55.0f;
    *(points4+6)=131.0f;
    *(points4+7)=55.0f;
    *(points4+8)=135.0f;
    *(points4+9)=48.0f;
    *(points4+10)=138.0f;
    *(points4+11)=54.0f;
    *(points4+12)=142.0f;
    *(points4+13)=54.0f;
    *(points4+14)=147.0f;
    *(points4+15)=45.0f;
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
        // printf("Vidas->%d\n",player.vidas);

        InitVidasPoints();

         switch (player.vidas){
         case 1:
             esat::DrawSolidPath(points,8);
         break;
         case 2:
             esat::DrawSolidPath(points,8);
             esat::DrawSolidPath(points1,8);
         break;
         case 3:
             esat::DrawSolidPath(points,8);
             esat::DrawSolidPath(points1,8);
             esat::DrawSolidPath(points2,8);
         break;
         case 4:
             esat::DrawSolidPath(points,8);
             esat::DrawSolidPath(points1,8);
             esat::DrawSolidPath(points2,8);
             esat::DrawSolidPath(points3,8);
         break;
         case 5:
             esat::DrawSolidPath(points,8);
             esat::DrawSolidPath(points1,8);
             esat::DrawSolidPath(points2,8);
             esat::DrawSolidPath(points3,8);
             esat::DrawSolidPath(points4,8);
         break;

         default:
             break;
         }


        // free(points);
        // free(points1);
        // free(points2);
        // free(points3);
        // free(points4);
    
}

void Login(){
    printf("Cargando usuarios\n");
    int size = LoadToMemory(users);
    printf("Usuarios totales->%d \n",size);
    if(size>0)printf("Usuarios cargados\n");

    for (int i = 0; i < size; i++){
        //Buscamos la persona con ese nombre
        printf("Comparando %s con %s\n",(users + i)->nombre,userName);
        // const char[20] = *(users + i)->nombre;
        if (strcmp(userName,(users + i)->nombre) == 0){
            //Usuario encontrado
            printf("Comparando %s con %s\n", (users + i)->password, userPasswd);

            if(strcmp(userPasswd,(users + i)->password) == 0){
                //Usuario y contraseña correctos
                logued = true;
            }else{
                printf("Contraseña incorrecta\n");
            }
        }
    }
    

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

    // printf("%s\n",userName);
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
    char *numberToChar = (char*) calloc('\0',sizeof(char)*30);
    char *aux = (char*) calloc('\0',sizeof(char)*30);
    // *numberToChar = 'C';
    // *(numberToChar+1) = 'R';
    // *(numberToChar+2) = 'E';
    // *(numberToChar+3) = 'D';
    // *(numberToChar+4) = 'I';
    // *(numberToChar+5) = 'T';
    // *(numberToChar+6) = 'S';
    // *(numberToChar+7) = ' ';
    // if(credits<100 && credits>=10){
    //     *(numberToChar+8) = '0';
    // }else if(credits<10){
    //     *(numberToChar+8) = '0';
    //     *(numberToChar+9) = '0';
    // }
    // itoa(credits,aux,10);
    // strcat(numberToChar,aux);
    esat::DrawText(400,280,numberToChar);
    free(aux);
    free(numberToChar);




    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Space)){
        credits++;
        printf("sumando");
    }
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Enter)){
        interfaz = false;
    }

}

void InterfaceActions(){
	esat::DrawSetTextSize(38);
    if(!logued && !debug){
        LoginInputs();
    }else{
        logued = true;
        // DrawFuel();
        // DrawVidas();

        if(intro)Intro();
        if(!intro && interfaz)Interface();

        if(player.vidas <= 0){
            intro = true;
            interfaz = true;
            player.vidas = 5;
        }
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

    free(points);
    free(points1);
    free(points2);
    free(points3);
    free(points4);
    // free(Fuel1New);
}