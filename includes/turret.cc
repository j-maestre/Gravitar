int shootTurretFramesCont = 0;
int nextShootTurretTime = 2;


void ShotTurret(TTurret *turret, float *points, int index = 0){
    float x = *(points + 4);
    float y = *(points + 5);
    // printf("Disparo desde X-> %f Y-> %f\n",x,y);
    xemath::Vector2 vecDirector = {player.x -x, player.y - y};
    float modulo = xemath::Vec2Modulo(vecDirector);
    // if(index == 1)printf("Modulo1 -> %f\n",modulo);
    if(modulo<=155.0f){

        vecDirector = xemath::Vec2Normalize(vecDirector);

        if(turret->shootTurretFramesCont%(turret->nextShootTurretTime * fps) == 0){
            //Sorteamos cuando saldrá el proximo disparo
            turret->nextShootTurretTime = 1 + rand() % SHOOT_FRECUENCY;
            printf("Next shot-> %d\n", turret->nextShootTurretTime);
            Disparo(turret->disparos, x, y, vecDirector, Rojo, true);
        }
        // printf("Turret Disparo\n");
        Disparo(turret->disparos, x, y, vecDirector, Rojo, false);

        turret->shootTurretFramesCont++;
    }
}