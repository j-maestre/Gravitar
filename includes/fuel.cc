// TODO: Te has quedado por aqui, hacer lo mismo que Fuel1 en Fuel2,3 y 4 y ya están los fuels
// TODO: Pasar parametros a la funcion InitFuelMap1 para parametrizar los fuels

void InitFuelMap1(float points[4][3], float *pointsNormalized, TFuelNew *fuel){
    for (int i = 0; i < 4; i++){

        //Puntos para el puntero que se va a pintar
        *(pointsNormalized+(i*2)) =  points[i][0] / 843.0f;
        *(pointsNormalized+(i*2 + 1)) =  points[i][1] / 718.0f;

        //Puntos para la struct para las colisiones
        *((fuel->points)+i*2) = points[i][0] / 843.0f;
        *((fuel->points)+i*2+1) = points[i][1] / 718.0f;
    }

    (fuel->obtained) = false;

    printf("Fuel inicializado en X->%f Y->%f\n",*pointsNormalized,*(pointsNormalized+1));
    
}

void ScalateFuelNew(float *pointsStruct, float *points){
    for (int i = 0; i < 4; i++){
        *(pointsStruct + i * 2) *= valorScalate;
        *(pointsStruct + i * 2 + 1) *= valorScalate;

        *(points + i * 2) = *(pointsStruct + i * 2) + 150.0f;
        *(points + i * 2 + 1) = *(pointsStruct + i * 2 + 1);
    }
    
}

void ScalateFuel(float fuel[4][3], float *pointsNormalized){
    printf("---Escalando---\n");
    for (int i = 0; i < 4; i++){
        fuel[i][0] = fuel[i][0] * valorScalate;
        *(pointsNormalized+(i*2)) = fuel[i][0] + 150;
        *(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1)) *valorScalate;

    }
    
}

void ResetFuelPoints(float pointsOriginal[4][3], float *points){
    printf("Reset fuel\n");
    for (int i = 0; i < 4; i++){
        *(points+i*2) = pointsOriginal[i][0];
        *(points+i*2+1) = pointsOriginal[i][1];
    }
    
}




void FuelActions(){

}