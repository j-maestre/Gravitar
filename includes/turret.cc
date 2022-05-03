int shootTurretFramesCont = 0;
int nextShootTurretTime = 2;

//TODO el disparo de la torreta solo sale cuando le doy yo a disparar y encima sale desde cuenca

void ShotTurret(TTurret turret){
    float x = (turret.map + 8)->x;
    float y = (turret.map + 8)->y;
    xemath::Vector2 vecDirector = {player.x -x, player.y - y};

    if(shootTurretFramesCont%(nextShootTurretTime * fps) == 0){
        printf("Disparo Nuevo\n");
        //Sorteamos cuando saldrá el proximo disparo
        nextShootTurretTime = 1 + rand() % SHOOT_FRECUENCY;
        // printf("Disparo, siguiente en %ds\n",nextShootTime);
        Disparo(turret.disparos, x, y, vecDirector, Rojo, true);
    }
    printf("Disparo\n");
    Disparo(turret.disparos, x, y, vecDirector, Rojo, false);

    shootFramesCont++;

    
}