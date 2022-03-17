// int aux = 0;

void CheckMapColision(){
    for (int i = 0; i < 36; i++){

        // int i = aux;
        // if(esat::IsKeyPressed('J')){
        //     aux++;
        //     if(aux>36)aux=0;
        // }
        // esat::DrawLine(player.x,player.y, *(pointsNormalized + (i * 2)), *(pointsNormalized + ((i * 2) + 1)));
        // esat::DrawLine(player.x,player.y,*(pointsNormalized + ((i * 2) + 2)),*(pointsNormalized + ((i * 2) + 3)));
        // esat::DrawSetStrokeColor(Rojo.r,Rojo.g,Rojo.b);
        // esat::DrawLine(*(pointsNormalized + i * 2),*(pointsNormalized + ((i * 2) + 1)),*(pointsNormalized + ((i * 2) + 2)),*(pointsNormalized + ((i * 2) + 3)));
        
        //Vectores con player x/y
        xemath::Vector2 vec1 = {*(pointsNormalized + (i * 2))-player.x,*(pointsNormalized + ((i * 2) + 1))-player.y};
        xemath::Vector2 vec2 = {*(pointsNormalized + ((i * 2) + 2))-player.x,*(pointsNormalized + ((i * 2) + 3))-player.y};

        //Vectores con player x/y + vectorDirector
        xemath::Vector2 vec3 = {*(pointsNormalized + (i * 2))-(player.x + player.vecDirector.x),*(pointsNormalized + ((i * 2) + 1))-(player.y + player.vecDirector.y)};
        xemath::Vector2 vec4 = {*(pointsNormalized + ((i * 2) + 2))-(player.x + player.vecDirector.x),*(pointsNormalized + ((i * 2) + 3))-(player.y + player.vecDirector.y)};
        xemath::Vector2 vecMapa = {*(pointsNormalized + i * 2)-*(pointsNormalized + i * 2 + 2),*(pointsNormalized + i * 2 + 1)-*(pointsNormalized + i * 2 + 3)};
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

        if(moduloSum < moduloMapa+0.1 || moduloSum2 < moduloMapa+0.1 && !scalating){
            printf("NAVE\n");
            player.vidas--;
            player.vecDirector.x = 0.0f;
            player.vecDirector.y = -15.0f;
            player.aceleration.x = 0.0f;
            player.aceleration.y = 0.0f;
            player.velocity.x = 0.0f;
            player.velocity.y = 0.0f;
            player.x = CENTROX;
            player.y = CENTROY;
        }


    }
    

}

void CheckShootColision(){
    for (int i = 0; i < 38; i++){
    
        for (int j = 0; j < 4; j++){
            if((player.disparos+j)->disparando){
                xemath::Vector2 vec1 = {*(pointsNormalized + (i * 2))-(player.disparos+j)->x,*(pointsNormalized + ((i * 2) + 1))-(player.disparos+j)->y};
                xemath::Vector2 vec2 = {*(pointsNormalized + ((i * 2) + 2))-(player.disparos+j)->x,*(pointsNormalized + ((i * 2) + 3))-(player.disparos+j)->y};
                xemath::Vector2 vecMapa = {*(pointsNormalized + i * 2)-*(pointsNormalized + i * 2 + 2),*(pointsNormalized + i * 2 + 1)-*(pointsNormalized + i * 2 + 3)};
                float modulo1 = xemath::Vec2Modulo(vec1);
                float modulo2 = xemath::Vec2Modulo(vec2);
                float modulo3 = xemath::Vec2Modulo(vecMapa);
                float moduloSum = modulo1 + modulo2;

                if(moduloSum < modulo3 + 1){
                    (player.disparos+j)->disparando = false;
                }
            }//End if
        }//End j for
    
    }//End i for

}