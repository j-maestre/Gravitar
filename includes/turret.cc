int shootTurretFramesCont = 0;
int nextShootTurretTime = 2;

//TODO el disparo de la torreta solo sale cuando le doy yo a disparar y encima sale desde cuenca

void ShotTurret(TTurret turret, float *points){
    float x = *(points + 4);
    float y = *(points + 5);
    printf("Disparo desde X-> %f Y-> %f\n",x,y);
    xemath::Vector2 vecDirector = {player.x -x, player.y - y};
    vecDirector = xemath::Vec2Normalize(vecDirector);

    if(shootTurretFramesCont%(nextShootTurretTime * fps) == 0){
        //Sorteamos cuando saldrá el proximo disparo
        nextShootTurretTime = 1 + rand() % SHOOT_FRECUENCY;
        Disparo(turret.disparos, x, y, vecDirector, Rojo, true);
    }
    // printf("Turret Disparo\n");
    Disparo(turret.disparos, x, y, vecDirector, Rojo, false);

    shootTurretFramesCont++;
}