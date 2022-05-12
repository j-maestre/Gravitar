
// player.velocidad = xemath::Vec2Normalize(player.vecDirector);
void DiePlayer(){
  if(!debug){

    player.vidas--;
    player.vecDirector.x = 0.0f;
    player.vecDirector.y = -15.0f;
    player.aceleration.x = 0.0f;
    player.aceleration.y = 0.0f;
    player.velocity.x = 0.0f;
    player.velocity.y = 0.0f;

    switch (player.nivel){
    case 1:
      player.y = 112.8f;
      player.x = 514.8f;
    break;
    case 2:
      player.y = 112.8f;
      player.x = 480.8f;
    break;
    case 5:
      player.y = 112.8f;
      player.x = 480.8f;
    break;
    
    default:
      break;
    }
  }
  
}


void InitPlayer(){
  player.disparos = (TDisparo*) malloc(sizeof(TDisparo)*4);
  (player.disparos)->disparando = false;
  (player.disparos+1)->disparando = false;
  (player.disparos+2)->disparando = false;
  (player.disparos+3)->disparando = false;

  for (int i = 0; i < 4; i++){
    printf("Disparo inicial i->%d bool->[%d]\n",i,(player.disparos+i)->disparando);
  }
  
}

void DrawPlayer(){

  //Escalamos el vector director cada frame para evitar la reduccion del mismo
  player.vecDirector = xemath::ScalateVec2(player.vecDirector,20);

  esat::DrawSetStrokeColor(0,255,0);

  //Linea del centro (columna)
  // esat::DrawLine(player.x, player.y, player.x + player.vecDirector.x,player.y + player.vecDirector.y);

  //Sacamos el vector de la linea principal
  xemath::Vector2 aux ={(player.x + player.vecDirector.x)- player.x,(player.y + player.vecDirector.y)- player.y};
  //Rotamos el vector
  xemath::Vector2 izquierda = xemath::RotateVec2(aux,200.0f);
  xemath::Vector2 derecha = xemath::RotateVec2(aux,-200.0f);

  xemath::Vector2 izquierdaAbajo = xemath::RotateVec2(aux,135);
  izquierdaAbajo = xemath::ScalateVec2(izquierdaAbajo,6);

  xemath::Vector2 derechaAbajo = xemath::RotateVec2(aux,-135);
  derechaAbajo = xemath::ScalateVec2(derechaAbajo,6);

  xemath::Vector2 izquierdaCentro = xemath::RotateVec2(aux,45);
  izquierdaCentro = xemath::ScalateVec2(izquierdaCentro,4);

  xemath::Vector2 derechaCentro = xemath::RotateVec2(aux,-45);
  derechaCentro = xemath::ScalateVec2(derechaCentro,4);

  //Arriba izquierda
  esat::DrawLine(
    player.x + player.vecDirector.x,
    player.y + player.vecDirector.y,
    (player.x + player.vecDirector.x) + izquierda.x,
    (player.y + player.vecDirector.y) + izquierda.y);

  //Abajo izquierda
  esat::DrawLine(
   (player.x + player.vecDirector.x) + izquierda.x,
   (player.y + player.vecDirector.y) + izquierda.y,
   ((player.x + player.vecDirector.x) + izquierda.x) + izquierdaAbajo.x,
   ((player.y + player.vecDirector.y) + izquierda.y) + izquierdaAbajo.y);

  //Izquierda centro
  esat::DrawLine(
    ((player.x + player.vecDirector.x) + izquierda.x) + izquierdaAbajo.x,
    ((player.y + player.vecDirector.y) + izquierda.y) + izquierdaAbajo.y,
    (((player.x + player.vecDirector.x) + izquierda.x) + izquierdaAbajo.x) + izquierdaCentro.x,
    (((player.y + player.vecDirector.y) + izquierda.y) + izquierdaAbajo.y) + izquierdaCentro.y);

  //Arriba derecha
  esat::DrawLine(
    player.x + player.vecDirector.x,
    player.y + player.vecDirector.y,
    (player.x + player.vecDirector.x) + derecha.x,
    (player.y + player.vecDirector.y) + derecha.y);

    //Abajo derecha
  esat::DrawLine(
   (player.x + player.vecDirector.x) + derecha.x,
   (player.y + player.vecDirector.y) + derecha.y,
   ((player.x + player.vecDirector.x) + derecha.x) + derechaAbajo.x,
   ((player.y + player.vecDirector.y) + derecha.y) + derechaAbajo.y);

   //Derecha centro
  esat::DrawLine(
    ((player.x + player.vecDirector.x) + derecha.x) + derechaAbajo.x,
    ((player.y + player.vecDirector.y) + derecha.y) + derechaAbajo.y,
    (((player.x + player.vecDirector.x) + derecha.x) + derechaAbajo.x) + derechaCentro.x,
    (((player.y + player.vecDirector.y) + derecha.y) + derechaAbajo.y) + derechaCentro.y);
}

void MovePlayer(){

  //Movimiento
  if(player.x <= 0){
    //Rebotar en X
    player.x=0;
    player.aceleration.x = - (player.aceleration.x * 0.8f);
  }
  if(player.x >= ANCHO){
    //Rebotar en X
    player.x=ANCHO;
    player.aceleration.x = - (player.aceleration.x * 0.8f);
  }

  
  //Movimiento
  if(player.y <= 0){
    //Rebotar en Y
    player.y=0;
    player.aceleration.y = - (player.aceleration.y * 0.8f);
  }
  if(player.y >= ALTO){
    //Rebotar en X
    player.y=ALTO;
    player.aceleration.y = - (player.aceleration.y * 0.8f);
  }

  if(!scrollHorizontal)player.x = player.x + player.aceleration.x;
  player.y = player.y + player.aceleration.y;

  if(esat::IsKeyPressed('A')){
    //Rotar sentido contrario de las agujas del reloj
    player.vecDirector = xemath::RotateVec2(player.vecDirector,-ANGLE_ROTATION);
  }

  if(esat::IsKeyPressed('D')){
    //Rotar sentido de las agujas del reloj
    player.vecDirector = xemath::RotateVec2(player.vecDirector,ANGLE_ROTATION);

  }

  if(esat::IsKeyPressed('W')){
    player.fuel -= FUEL_CONSUME;

    player.velocity.x = xemath::Vec2Normalize(player.vecDirector).x * player.velocidad;
    player.velocity.y = xemath::Vec2Normalize(player.vecDirector).y * player.velocidad;
    player.aceleration = xemath::SumVec2(player.aceleration,player.velocity);
  

    //Pintar fuego
    esat::DrawSetStrokeColor(255,0,0);

    //Vector principal
    xemath::Vector2 aux ={(player.x + player.vecDirector.x)- player.x,(player.y + player.vecDirector.y)- player.y};

    //Vectores del triangulo
    xemath::Vector2 derecha = xemath::RotateVec2(aux,140.0f);
    xemath::Vector2 izquierda = xemath::RotateVec2(aux,220.0f);
    derecha = xemath::ScalateVec2(derecha,7);
    izquierda = xemath::ScalateVec2(izquierda,7);


    esat::DrawLine(player.x, player.y, player.x+derecha.x,player.y+derecha.y);
    esat::DrawLine(player.x, player.y, player.x+izquierda.x,player.y+izquierda.y);
    esat::DrawLine(player.x+izquierda.x, player.y+izquierda.y,player.x+derecha.x ,player.y+derecha.y);

  }else{
    //Desacelerar
    player.aceleration.x *= 0.99;
    player.aceleration.y *= 0.99;

  }
}

void ApplyShotScroll(){
  for (int i = 0; i < 4; i++){
    if((player.disparos+i)->disparando){
      (player.disparos+i)->x -= (player.aceleration.x);
      // (player.disparos+i)->y -= (player.aceleration.y);
    }
  }
  
    
}


void PlayerActions(){
  DrawPlayer();
  if(!scalating)MovePlayer();
  Disparo(player.disparos, player.x,player.y,player.vecDirector);

}


