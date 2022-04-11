void AplyGravity(float X, float Y){
    //X e Y será el punto al que queremos aplicar la gravedad

    //Vector de distancia entre el jugador y el punto de gravedad
    xemath::Vector2 distance = {X-player.x, Y-player.y};
    if(xemath::Vec2Modulo(distance)>10){
        distance = xemath::Vec2Normalize(distance);
        //Multiplicamos el vector de distancia por la fueza acumulada
        distance.x*= player.gravityForce;
        distance.y*= player.gravityForce;

        //Incrementamos la fuerza
        // player.gravityForce+=0.001;

        //Sumamos la distancia al jugador
        player.aceleration.x += distance.x;
        player.aceleration.y += distance.y;
    
    }


}