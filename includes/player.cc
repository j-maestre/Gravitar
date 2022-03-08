TPlayer player;
// player.velocidad = xemath::Vec2Normalize(player.vecDirector);

void DrawPlayer(){
  esat::DrawSetStrokeColor(0,255,0);
  // esat::DrawLine(player.vecPunta.x, player.vecPunta.y,player.vecPunta.x + player.vecDirector.x, player.vecPunta.y + player.vecDirector.y);
  //Arriba izquierda
  //y - 15 para coger la punta de abajo
  //Rotar la x y escalar

  // xemath::Vector2  = {player.vecPunta.x };

  //Linea del centro (columna)
  esat::DrawLine(player.x, player.y, player.x + player.vecDirector.x,player.y + player.vecDirector.y);


  //Arriba izquierda
  xemath::Vector2 aux = xemath::RotateVec2(player.vecDirector, xemath::ToRadianes(-220));


  // esat::DrawLine(
  //  player.x + player.vecDirector.x,
  //  player.y + player.vecDirector.y,
  //  player.x - player.vecDirector.x + aux.x,
  //  player.y + player.vecDirector.y + aux.y);


//  (player.x + player.vecDirector.x) + xemath::RotateVec2(player.vecDirector, xemath::ToRadianes(90)).x,
//  (player.y + player.vecDirector.y) + xemath::RotateVec2(player.vecDirector, xemath::ToRadianes(90)).y);
  //(player.x + player.vecDirector.x) + xemath::RotateVec2(player.vecDirector, 90).x, (player.y + player.vecDirector.y) + xemath::RotateVec2(player.vecDirector, 90).y


}

void MovePlayer(){

  player.x = player.x + player.aceleration.x;
  player.y = player.y + player.aceleration.y;

  //Normalizar vector director y multiplicar por lo que quiero que mida
  player.vecDirector.x = xemath::Vec2Normalize(player.vecDirector).x * 15;
  player.vecDirector.y = xemath::Vec2Normalize(player.vecDirector).y * 15;


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

    player.velocity.x = xemath::Vec2Normalize(player.vecDirector).x * player.velocidad;
    player.velocity.y = xemath::Vec2Normalize(player.vecDirector).y * player.velocidad;

    player.aceleration = xemath::SumVec2(player.aceleration,player.velocity);

  }else{
    //Desacelerar
    player.aceleration.x *= 0.99;
    player.aceleration.y *= 0.99;

  }
}


void PlayerActions(){
  DrawPlayer();
  MovePlayer();
}
