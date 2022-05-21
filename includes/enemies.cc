int shootFramesCont = 0;
int nextShootTime = 4;

void InitEnemies(){
    enemi1.disparos = (TDisparo *)malloc(sizeof(TDisparo) * 4);
    (enemi1.disparos)->disparando = false;
    (enemi1.disparos + 1)->disparando = false;
    (enemi1.disparos + 2)->disparando = false;
    (enemi1.disparos + 3)->disparando = false;
    enemi1.x = 100.0f;
    enemi1.y = 350.0f;

    enemi1.canMove = false;
    enemi1.secondsToMove = 2;
    enemi1.secondsToMoveCount = 1;

    // for (int i = 0; i < 4; i++){

        // printf("Disparo del enemigo %d->%d\n", i, (enemi1.disparos + i)->disparando);
    // }
    
}

void DrawEnemy1(TEnemy *enemi){
    enemi->vecDirector = xemath::ScalateVec2(enemi->vecDirector,5);

    //Vector de la linea central
    xemath::Vector2 aux = {(enemi->x + enemi->vecDirector.x) - enemi->x, (enemi->y + enemi->vecDirector.y) - enemi->y};

    // Rotamos el vector
    xemath::Vector2 izquierda = xemath::RotateVec2(aux, -60.0f);
    xemath::Vector2 derecha = xemath::RotateVec2(aux, 60.0f);

    xemath::Vector2 izquierda2 = xemath::ScalateVec2(izquierda,8);
    xemath::Vector2 derecha2 = xemath::ScalateVec2(derecha,8);
    izquierda = xemath::ScalateVec2(izquierda,15);
    derecha = xemath::ScalateVec2(derecha,15);

    izquierda2 = xemath::RotateVec2(izquierda2,-80);
    derecha2 = xemath::RotateVec2(derecha2,80);

    //Central
    // esat::DrawLine(enemi->x, enemi->y, enemi->x + enemi->vecDirector.x, enemi->y + enemi->vecDirector.y);

    esat::DrawSetStrokeColor(255,50, 0);
    //Izquierda
    esat::DrawLine(enemi->x + enemi->vecDirector.x, enemi->y + enemi->vecDirector.y, (enemi->x + enemi->vecDirector.x) + izquierda.x, (enemi->y + enemi->vecDirector.y) + izquierda.y);
    esat::DrawLine((enemi->x + enemi->vecDirector.x) + izquierda.x,
    (enemi->y + enemi->vecDirector.y) + izquierda.y, 
    ((enemi->x + enemi->vecDirector.x) + izquierda.x) + izquierda2.x, 
    ((enemi->y + enemi->vecDirector.y) + izquierda.y) + izquierda2.y);

    esat::DrawLine(((enemi->x + enemi->vecDirector.x) + izquierda.x) + izquierda2.x,
                   ((enemi->y + enemi->vecDirector.y) + izquierda.y) + izquierda2.y,
                   enemi->x,
                   enemi->y);

    //Derecha
    esat::DrawLine(enemi->x + enemi->vecDirector.x, enemi->y + enemi->vecDirector.y, (enemi->x + enemi->vecDirector.x) + derecha.x, (enemi->y + enemi->vecDirector.y) + derecha.y);
    esat::DrawLine((enemi->x + enemi->vecDirector.x) + derecha.x,
                   (enemi->y + enemi->vecDirector.y) + derecha.y,
                   ((enemi->x + enemi->vecDirector.x) + derecha.x) + derecha2.x,
                   ((enemi->y + enemi->vecDirector.y) + derecha.y) + derecha2.y);
    esat::DrawLine(((enemi->x + enemi->vecDirector.x) + derecha.x) + derecha2.x,
                   ((enemi->y + enemi->vecDirector.y) + derecha.y) + derecha2.y,
                   enemi->x,
                   enemi->y);

    //Triangulillo
    esat::DrawSetStrokeColor(Amarillo.r, Amarillo.g, Amarillo.b);

    // Abajo
    xemath::Vector2 abajo = xemath::ScalateVec2(aux,7); 
    abajo = xemath::RotateVec2(abajo, 90.0f);
    esat::DrawLine((enemi->x + enemi->vecDirector.x),
                   (enemi->y + enemi->vecDirector.y),
                   (enemi->x + enemi->vecDirector.x) + abajo.x,
                   (enemi->y + enemi->vecDirector.y) + abajo.y);

    xemath::Vector2 abajo2 = xemath::RotateVec2(abajo, 180.0f);
    esat::DrawLine((enemi->x + enemi->vecDirector.x),
                   (enemi->y + enemi->vecDirector.y),
                   (enemi->x + enemi->vecDirector.x) + abajo2.x,
                   (enemi->y + enemi->vecDirector.y) + abajo2.y);

    //Arriba
    xemath::Vector2 punta = xemath::ScalateVec2(enemi->vecDirector,15);
    punta = xemath::RotateVec2(punta,-30);

    //Izquierda
    esat::DrawLine((enemi->x + enemi->vecDirector.x) + abajo.x,
                   (enemi->y + enemi->vecDirector.y) + abajo.y,
                   (enemi->x + enemi->vecDirector.x) + abajo.x + punta.x,
                   (enemi->y + enemi->vecDirector.y) + abajo.y + punta.y );

    //Derecha
    punta = xemath::RotateVec2(punta, 55);
    esat::DrawLine((enemi->x + enemi->vecDirector.x) + abajo2.x,
                   (enemi->y + enemi->vecDirector.y) + abajo2.y,
                   (enemi->x + enemi->vecDirector.x) + abajo2.x + punta.x,
                   (enemi->y + enemi->vecDirector.y) + abajo2.y + punta.y);
}

void DrawEnemy2(TEnemy *enemi){
    enemi->vecDirector = xemath::ScalateVec2(enemi->vecDirector,5);
    esat::DrawSetStrokeColor(255,50, 0);

    //Vector de la linea central
    xemath::Vector2 aux = {(enemi->x + enemi->vecDirector.x) - enemi->x, (enemi->y + enemi->vecDirector.y) - enemi->y};

    // Rotamos el vector
    xemath::Vector2 izquierda = xemath::RotateVec2(aux, -60.0f);
    xemath::Vector2 derecha = xemath::RotateVec2(aux, 60.0f);

    xemath::Vector2 izquierda2 = xemath::ScalateVec2(izquierda,8);
    xemath::Vector2 derecha2 = xemath::ScalateVec2(derecha,8);
    izquierda = xemath::ScalateVec2(izquierda,15);
    derecha = xemath::ScalateVec2(derecha,15);

    izquierda2 = xemath::RotateVec2(izquierda2,-80);
    derecha2 = xemath::RotateVec2(derecha2,80);

    //Central
    // esat::DrawLine(enemi->x, enemi->y, enemi->x + enemi->vecDirector.x, enemi->y + enemi->vecDirector.y);

    //Izquierda
    esat::DrawLine(enemi->x + enemi->vecDirector.x, enemi->y + enemi->vecDirector.y, (enemi->x + enemi->vecDirector.x) + izquierda.x, (enemi->y + enemi->vecDirector.y) + izquierda.y);
    esat::DrawLine((enemi->x + enemi->vecDirector.x) + izquierda.x,
    (enemi->y + enemi->vecDirector.y) + izquierda.y, 
    ((enemi->x + enemi->vecDirector.x) + izquierda.x) + izquierda2.x, 
    ((enemi->y + enemi->vecDirector.y) + izquierda.y) + izquierda2.y);

    esat::DrawLine(((enemi->x + enemi->vecDirector.x) + izquierda.x) + izquierda2.x,
                   ((enemi->y + enemi->vecDirector.y) + izquierda.y) + izquierda2.y,
                   enemi->x,
                   enemi->y);

    //Derecha
    esat::DrawLine(enemi->x + enemi->vecDirector.x, enemi->y + enemi->vecDirector.y, (enemi->x + enemi->vecDirector.x) + derecha.x, (enemi->y + enemi->vecDirector.y) + derecha.y);
    esat::DrawLine((enemi->x + enemi->vecDirector.x) + derecha.x,
                   (enemi->y + enemi->vecDirector.y) + derecha.y,
                   ((enemi->x + enemi->vecDirector.x) + derecha.x) + derecha2.x,
                   ((enemi->y + enemi->vecDirector.y) + derecha.y) + derecha2.y);
    esat::DrawLine(((enemi->x + enemi->vecDirector.x) + derecha.x) + derecha2.x,
                   ((enemi->y + enemi->vecDirector.y) + derecha.y) + derecha2.y,
                   enemi->x,
                   enemi->y);

    //Dibujar triangulillo del medio

}


void EnemyShotPlayer(TEnemy *enemi){
    TDisparo *disparos = enemi->disparos;
    TDisparo *disparosPlayer = player.disparos;

    //Enemy shot
    for (int i = 0; i < 4; i++){
        if((disparos+i)->disparando){
            // printf("Disparo%d en X->%f Y->%f\n",i,(disparos+i)->x,(disparos+i)->y);
            //Sacar modulo
            xemath::Vector2 direccion = {player.x - (disparos+i)->x, player.y - (disparos+i)->y};
            float distance = xemath::Vec2Modulo(direccion);
            if(distance<=20 && !debug){
                player.nivel = 0;
                enemi->velocidad /=2; 
                DiePlayer();
                InitEnemies();
            }
        }
    }

    // Player shot

    for (int i = 0; i < 4; i++){
        if((disparosPlayer+i)->disparando){
            // printf("Disparo%d en X->%f Y->%f\n",i,(disparos+i)->x,(disparos+i)->y);
            //Sacar modulo
            xemath::Vector2 direccion = {enemi->x - (disparosPlayer+i)->x, enemi->y - (disparosPlayer+i)->y};
            float distance = xemath::Vec2Modulo(direccion);
            if(distance<=20){
                player.nivel = 0;
                enemi->velocidad /=2; 
                // DiePlayer();
                player.score +=150;
                InitEnemies();
            }
        }
    }
    

}

void MoveEnemy(TEnemy *enemi){
    // Sacar vector director entre el enemigo y el jugador
    // bool nuevoDisp = false;
    if(enemi->canMove){

        xemath::Vector2 direccion = {player.x - enemi->x, player.y - enemi->y};
        float distance = xemath::Vec2Modulo(direccion);
        direccion = xemath::Vec2Normalize(direccion);

        direccion.x *= enemi->velocidad;
        direccion.y *= enemi->velocidad;
        enemi->x += direccion.x;
        enemi->y += direccion.y;
        
        if(distance <=20){
            player.nivel = 99;
            enemi->x = 100.0f;
            enemi->y = 350.0f;
            player.x = (float) CENTROX;
            player.y = (float) CENTROY;
            enemi->velocidad *=2; 
            for (int i = 0; i < 4; i++){
                ((enemi->disparos)+i)->disparando = false;
            }
            
        }


        if(shootFramesCont%(nextShootTime * fps) == 0){
            //Sorteamos cuando saldrá el proximo disparo
            nextShootTime = 1 + rand() % SHOOT_FRECUENCY;
            // printf("Disparo, siguiente en %ds\n",nextShootTime);
            Disparo(enemi1.disparos, enemi1.x, enemi1.y, direccion, Rojo, true);
        }
        Disparo(enemi1.disparos, enemi1.x, enemi1.y, direccion, Rojo, false);

        shootFramesCont++;
    }else{
        enemi->secondsToMoveCount++;

        //Fix division by zero
        if(enemi->secondsToMoveCount == 0){
            enemi->secondsToMoveCount = 1;
        }
        if(enemi->secondsToMove == 0){
            enemi->secondsToMove = 2;
        }
        

        if (enemi->secondsToMoveCount%(enemi->secondsToMove*fps) == 0){
            enemi->canMove = true;
        }
    }
}