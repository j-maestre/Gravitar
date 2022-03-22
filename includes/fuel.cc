



void InitFuelMap1(){

    //Dividir la matriz por los elementos mas grandes para que los valores esten entre 0-1    
    //843,718,1
    //Normalizado de la matriz 3x1
    for(int i = 0; i <4; i++){
        //Fuel1
        pointsFuel1Map1[i][0] = pointsFuel1Map1[i][0] / 843.0f;
        pointsFuel1Map1[i][1] = pointsFuel1Map1[i][1] / 718.0f;
        *(pointsFuel1Normalized+(i*2)) =  pointsFuel1Map1[i][0];
        *(pointsFuel1Normalized+(i*2 + 1)) = pointsFuel1Map1[i][1];
        //Fuel2
        pointsFuel2Map1[i][0] = pointsFuel2Map1[i][0] / 843.0f;
        pointsFuel2Map1[i][1] = pointsFuel2Map1[i][1] / 718.0f;
        *(pointsFuel2Normalized+(i*2)) =  pointsFuel2Map1[i][0];
        *(pointsFuel2Normalized+(i*2 + 1)) = pointsFuel2Map1[i][1];


        //Fuel struct to check colision TODO cambiar a algo mas limpio

        //Fuel1
        (Fuel1+(i*2))->x =  pointsFuel1Map1[i][0];
        (Fuel1+(i*2 + 1))->y = pointsFuel1Map1[i][1];
        //Fuel2
        (Fuel2+(i*2))->x =  pointsFuel2Map1[i][0];
        (Fuel2+(i*2 + 1))->y = pointsFuel2Map1[i][1];

    };

    for (int i = 0; i < 8; i++){
        (Fuel1+i)->obtained = false;
        (Fuel2+i)->obtained = false;
    }

}

void ScalateFuel(float fuel[4][3], float *pointsNormalized){
    for (int i = 0; i < 4; i++){
        fuel[i][0] = fuel[i][0] * valorScalate;

        //Fuel1
        *(pointsNormalized+(i*2)) = fuel[i][0] + 150;
        *(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1)) *valorScalate;

    }
    
}




void FuelActions(){

}