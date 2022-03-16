// int aux = 0;

void CheckMapColision(){
    for (int i = 0; i < 38; i++){

        // int i = aux;
        // if(esat::IsKeyPressed('J')){
        //     aux++;
        //     if(aux>38)aux=0;
        // }
        // esat::DrawLine(player.x,player.y, *(pointsNormalized + (i * 2)), *(pointsNormalized + ((i * 2) + 1)));
        // esat::DrawLine(player.x,player.y,*(pointsNormalized + ((i * 2) + 2)),*(pointsNormalized + ((i * 2) + 3)));
        // esat::DrawSetStrokeColor(Rojo.r,Rojo.g,Rojo.b);
        // esat::DrawLine(*(pointsNormalized + i * 2),*(pointsNormalized + ((i * 2) + 1)),*(pointsNormalized + ((i * 2) + 2)),*(pointsNormalized + ((i * 2) + 3)));
        
        xemath::Vector2 vec1 = {*(pointsNormalized + (i * 2))-player.x,*(pointsNormalized + ((i * 2) + 1))-player.y};
        xemath::Vector2 vec2 = {*(pointsNormalized + ((i * 2) + 2))-player.x,*(pointsNormalized + ((i * 2) + 3))-player.y};
        xemath::Vector2 vecMapa = {*(pointsNormalized + i * 2)-*(pointsNormalized + i * 2 + 2),*(pointsNormalized + i * 2 + 1)-*(pointsNormalized + i * 2 + 3)};
        //El modulo del vector2 que une los dos puntos del mapa, habrá colision cuando la suma del modulo 
        //de los dos vectores que unen la nave sea < que el modulo de los vectores que unen el mapa 
        float modulo1 = xemath::Vec2Modulo(vec1);
        float modulo2 = xemath::Vec2Modulo(vec2);
        float modulo3 = xemath::Vec2Modulo(vecMapa);
        float moduloSum = modulo1 + modulo2;

        // if(moduloSum < modulo3 + 1){
        //     printf("---COLISION---\n");
        // }else{
        //     printf("-");
        // }
    }
    

}