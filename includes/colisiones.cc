

int aux = 0;
//TODO check colision disparo con el borde del mapa cuando he hecho scroll
//*Colision del jugador con el mapa
void CheckMapColision(float *points, int size){
    // printf("uep\n");
    if(esat::IsKeyDown('Z'))aux++;
    Createcircle(*(points + (aux*2)), *(points + (aux*2 + 1)), 5);
    printf("Aux-> %d\n",aux);
    for (int i = 0; i < (size-1); i++){
        // printf("uep %d\n",i);
        Createcircle(*(points + (i * 2)), *(points + (i * 2 + 1)), 5,Rojo);

        // int i = aux;
        // if(esat::IsKeyPressed('J')){
        //     aux++;
        //     if(aux>36)aux=0;
        // }
        // esat::DrawLine(player.x, player.y, *(points + (i * 2)), *(points + ((i * 2) + 1)));
        // esat::DrawLine(player.x, player.y, *(points + ((i * 2) + 2)), *(points + ((i * 2) + 3)));
        // esat::DrawSetStrokeColor(Rojo.r,Rojo.g,Rojo.b);
        // esat::DrawLine(*(points + i * 2), *(points + ((i * 2) + 1)), *(points + ((i * 2) + 2)), *(points + ((i * 2) + 3)));

        //Vectores con player x/y
        xemath::Vector2 vec1 = {*(points + (i * 2))-player.x,*(points + ((i * 2) + 1))-player.y};
        xemath::Vector2 vec2 = {*(points + ((i * 2) + 2))-player.x,*(points + ((i * 2) + 3))-player.y};

        //Vectores con player x/y + vectorDirector
        xemath::Vector2 vec3 = {*(points + (i * 2))-(player.x + player.vecDirector.x),*(points + ((i * 2) + 1))-(player.y + player.vecDirector.y)};
        xemath::Vector2 vec4 = {*(points + ((i * 2) + 2))-(player.x + player.vecDirector.x),*(points + ((i * 2) + 3))-(player.y + player.vecDirector.y)};
        xemath::Vector2 vecMapa = {*(points + i * 2)-*(points + i * 2 + 2),*(points + i * 2 + 1)-*(points + i * 2 + 3)};
        //El modulo del vector2 que une los dos puntos del mapa, habrá colision cuando la suma del modulo 
        //de los dos vectores que unen la nave sea < que el modulo de los vectores que unen el mapa 
        float modulo1 = xemath::Vec2Modulo(vec1);
        float modulo2 = xemath::Vec2Modulo(vec2);

        float modulo3 = xemath::Vec2Modulo(vec3);
        float modulo4 = xemath::Vec2Modulo(vec4);

        float moduloMapa = xemath::Vec2Modulo(vecMapa);

        float moduloSum = modulo1 + modulo2;
        float moduloSum2 = modulo3 + modulo4;

        // esat::DrawLine((player.x + player.vecDirector.x),(player.y + player.vecDirector.y),*(pointsNormalized + (i * 2)), *(pointsNormalized + ((i * 2) + 1)) );
        // esat::DrawLine((player.x + player.vecDirector.x),(player.y + player.vecDirector.y),*(pointsNormalized + ((i * 2) + 2)), *(pointsNormalized + ((i * 2) + 3)) );
        if(!debug){
            if(moduloSum < moduloMapa+0.1 || moduloSum2 < moduloMapa+0.1 && !scalating){
                printf("COLISION\n");
                DiePlayer();
                
            }
        }


    }
    

}

bool CheckShootColision(float *points, int size, bool turret = false,bool bomb = false){
    bool turretDead = false;
    for (int i = 0; i < size; i++){
        // Createcircle(*(points + i * 2), *(points + i * 2 + 1),5,Rosa);
        for (int j = 0; j < 4; j++){
            // Createcircle(*((player.disparos + j * 2)->x), *((player.disparos + j * 2 + 1)->y),5,Verde);
            if ((player.disparos + j)->disparando){
                xemath::Vector2 vec1 = {*(points + (i * 2)) - (player.disparos + j)->x, *(points + ((i * 2) + 1)) - (player.disparos + j)->y};
                xemath::Vector2 vec2 = {*(points + ((i * 2) + 2)) - (player.disparos + j)->x, *(points + ((i * 2) + 3)) - (player.disparos + j)->y};
                xemath::Vector2 vecMapa = {*(points + i * 2) - *(points + i * 2 + 2), *(points + i * 2 + 1) - *(points + i * 2 + 3)};
                float modulo1 = xemath::Vec2Modulo(vec1);
                float modulo2 = xemath::Vec2Modulo(vec2);
                float modulo3 = xemath::Vec2Modulo(vecMapa);
                float moduloSum = modulo1 + modulo2;
                

                if (moduloSum < modulo3 + 1){


                    printf("Colision mapa %d disparo en X->%f Y->%f\n",player.nivel, (player.disparos + j)->x, (player.disparos + j)->y);
                    if(player.nivel == 1 && (player.disparos + j)->x > 408.0f && (player.disparos + j)->x < 481.0f){
                        //Colision con un bug
                        printf("------BUG-------\n");
                    }else{
                        (player.disparos + j)->disparando = false;
                    }

                    (player.disparos + j)->disparando = false;

                    if(turret){
                        printf("Colision con torreta\n");
                        player.score+=100;
                        turretDead = true;
                    }
                    if(bomb){
                        printf("COLISION BOMBA\n");
                        bombShooted = true;
                    }
                }
            } // End if
            if(player.nivel == 99){
                //Check colision with enemies
            }
        }// End j for
    } // End i for
    return turretDead;
}


void TurretShootcolision(TDisparo *disparo, int size){
    //Disparos de una torreta y el maximo de disparos que pueden haber

    for (int i = 0; i < size; i++){
        
        if((disparo+i)->disparando){
            // xemath::Vector2 distancia = {player.x - (disparo+i)->x, player.y - (disparo+i)->y};
            xemath::Vector2 distancia = {player.x - (float)esat::MousePositionX(), player.y - (float)esat::MousePositionY()};
            float modulo = xemath::Vec2Modulo(distancia);

            if(modulo <= 15){
                printf("-----MUERTO-----\n");
            }
        }
    }
}