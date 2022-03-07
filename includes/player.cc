TPlayer player;
// player.velocidad = xemath::Vec2Normalize(player.vecDirector);

void DrawPlayer(){
  esat::DrawSetStrokeColor(0,255,0);
  // esat::DrawLine(player.vecPunta.x, player.vecPunta.y,player.vecPunta.x + player.vecDirector.x, player.vecPunta.y + player.vecDirector.y);
  //Arriba izquierda
  //y - 15 para coger la punta de abajo
  //Rotar la x y escalar

  // xemath::Vector2  = {player.vecPunta.x };

  //Arriba izquierda
  xemath::Vector2 aux = xemath::RotateVec2(player.vecDirector, xemath::ToRadianes(-220));
  esat::DrawLine(player.x, player.y, player.x + player.vecDirector.x,player.y + player.vecDirector.y);

  // esat::DrawLine(
  //   player.x + player.vecDirector.x,
  //   player.y + player.vecDirector.y,
  //   player.x - player.vecDirector.x + aux.x,
  //   player.y + player.vecDirector.y + aux.y);
    // (player.x + player.vecDirector.x) + xemath::RotateVec2(player.vecDirector, xemath::ToRadianes(90)).x,
    // (player.y + player.vecDirector.y) + xemath::RotateVec2(player.vecDirector, xemath::ToRadianes(90)).y);
  //(player.x + player.vecDirector.x) + xemath::RotateVec2(player.vecDirector, 90).x, (player.y + player.vecDirector.y) + xemath::RotateVec2(player.vecDirector, 90).y


}

void MovePlayer(){
  // player.velocidad = xemath::Vec2Normalize(player.vecDirector);
  // player.vecDirector.x +=player.aceleration;
  // player.vecDirector.y +=player.aceleration;


  // player.x +=player.aceleration.x;
  // player.y +=player.aceleration.y;
  player.x = player.x + (player.vecDirector.x * player.aceleration.x);
  player.y = player.y + (player.vecDirector.y * player.aceleration.y);


  // player.x = player.x + player.vecDirector.x * player.acelerationFull;
  // player.y = player.y + player.vecDirector.y * player.acelerationFull;

  if(esat::IsKeyPressed('A')){
    //Rotar sentido contrario de las agujas del reloj
    printf("Rotar Izquierda\n");
    player.vecDirector = xemath::RotateVec2(player.vecDirector,-ANGLE_ROTATION);
  }

  if(esat::IsKeyPressed('D')){
    //Rotar sentido de las agujas del reloj
    printf("Rotar Derecha\n");
    player.vecDirector = xemath::RotateVec2(player.vecDirector,ANGLE_ROTATION);

  }

  if(esat::IsKeyPressed('W')){
    // player.aceleration.x +=player.velocidad.x;
    // player.aceleration.y +=player.velocidad.y;




    //Acelerar hacia arriba

    player.aceleration.x += player.velocidad;
    player.aceleration.y += player.velocidad;

    // if(player.acelerationFull <0.5f){
    //   player.acelerationFull +=0.05f;
    // }
  }else{
    //Desacelerar
    if(player.velocidad >0){
      player.aceleration.x += player.velocidad;
      player.aceleration.y += player.velocidad;
    }else{
      player.velocidad = 0.05f;
    }




    // if(player.acelerationFull >= 0.05f){
    //   player.acelerationFull -= 0.05f;
    // }else{
    //   player.acelerationFull = 0.0f;
    // }
  }
}


void PlayerActions(){
  DrawPlayer();
  MovePlayer();
}
