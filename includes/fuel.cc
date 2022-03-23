



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

        //Fuel3
        pointsFuel3Map1[i][0] = pointsFuel3Map1[i][0] / 843.0f;
        pointsFuel3Map1[i][1] = pointsFuel3Map1[i][1] / 718.0f;
        *(pointsFuel3Normalized+(i*2)) =  pointsFuel3Map1[i][0];
        *(pointsFuel3Normalized+(i*2 + 1)) = pointsFuel3Map1[i][1];
        
        //Fuel4
        pointsFuel4Map1[i][0] = pointsFuel4Map1[i][0] / 843.0f;
        pointsFuel4Map1[i][1] = pointsFuel4Map1[i][1] / 718.0f;
        *(pointsFuel4Normalized+(i*2)) =  pointsFuel4Map1[i][0];
        *(pointsFuel4Normalized+(i*2 + 1)) = pointsFuel4Map1[i][1];


        //Fuel struct to check colision TODO cambiar a algo mas limpio

        //Fuel1
        (Fuel1+(i*2))->x =  pointsFuel1Map1[i][0];
        (Fuel1+(i*2 + 1))->y = pointsFuel1Map1[i][1];
        //Fuel2
        (Fuel2+(i*2))->x =  pointsFuel2Map1[i][0];
        (Fuel2+(i*2 + 1))->y = pointsFuel2Map1[i][1];
        //Fuel3
        (Fuel3+(i*2))->x =  pointsFuel3Map1[i][0];
        (Fuel3+(i*2 + 1))->y = pointsFuel3Map1[i][1];
        //Fuel4
        (Fuel4+(i*2))->x =  pointsFuel4Map1[i][0];
        (Fuel4+(i*2 + 1))->y = pointsFuel4Map1[i][1];

    };

    for (int i = 0; i < 8; i++){
        (Fuel1+i)->obtained = false;
        (Fuel2+i)->obtained = false;
        (Fuel3+i)->obtained = false;
        (Fuel4+i)->obtained = false;
    }

}

void ScalateFuel(float fuel[4][3], float *pointsNormalized){
    for (int i = 0; i < 4; i++){
        fuel[i][0] = fuel[i][0] * valorScalate;
        *(pointsNormalized+(i*2)) = fuel[i][0] + 150;
        *(pointsNormalized+(i*2 + 1)) = *(pointsNormalized+(i*2 + 1)) *valorScalate;

    }
    
}




void FuelActions(){

}