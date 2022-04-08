void AplyGravity(float X, float Y){
    //X e Y será el punto al que queremos aplicar la gravedad

    //Vector de distancia entre el jugador y el punto de gravedad
    xemath::Vector2 distance = {X-player.x, Y-player.y};
    if(xemath::Vec2Modulo(distance)>10){

        printf("Centro x-> %f Y-> %f\n",X,Y);
        printf("Player x-> %f Y-> %f\n",player.x,player.y);
        printf("Vector x[%f] Y[%f]\n",distance.x,distance.y);
        distance = xemath::Vec2Normalize(distance);
        printf("Vector x[%f] Y[%f]\n",distance.x,distance.y);


        //Multiplicamos el vector de distancia por la fueza acumulada
        distance.x*= player.gravityForce;
        distance.y*= player.gravityForce;

        //Incrementamos la fuerza
        player.gravityForce+=0.01;
        printf("Fuerza aplicada-> %f\n",player.gravityForce);
        //Sumamos la distancia al jugador
        player.x += distance.x;
        player.y += distance.y;
    }else{
        player.gravityForce = 0.0f;
    }


}