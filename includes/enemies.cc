
void DrawEnemy1(TEnemy *enemi){
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

void MoveEnemy(TEnemy *enemi){
    // Sacar vector director entre el enemigo y el jugador
    xemath::Vector2 direccion = {player.x - enemi->x, player.y - enemi->y};
    direccion = xemath::Vec2Normalize(direccion);

    direccion.x *= enemi->velocidad;
    direccion.y *= enemi->velocidad;
    enemi->x += direccion.x;
    enemi->y += direccion.y;
}