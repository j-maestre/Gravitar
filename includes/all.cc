#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <string.h>
#include <stdlib.h>
#include "xemath.cc"
#include <conio.h>
#include "users.cc"

bool debug = false;

//Ancho -> 256*4
//Alto -> 192*4
const int ANCHO = 1124, ALTO = 868, CENTROX = 562, CENTROY = 434 ;
const double dPI = 3.1415926535897;
unsigned char fps=60;
double current_time,last_time;
const float ANGLE_ROTATION = 3;
const int SHOOT_FRECUENCY = 4;
const int FUEL_CONSUME = 4;
const int TIME_TO_EXPLOSION = 10;
const float ENEMY_HITBOX_SIZE = 30.0f;
bool intro = true, interfaz = true;
int credits = 1;
bool scalating = false;
bool scrollHorizontal = false;
bool bombShooted = false;

int id_current_user;

//Para escalar los puntos, cogemos los puntos de un mapa cualquiera, los normalizamos para pasarlos entre 0-1 y luego lo multiplicamos 
//Por el ancho y alto de nuestra pantalla para escalar cualquier mapa a nuestra pantalla


struct TColor{
  int r = 255;
  int g = 255;
  int b = 255;
  int a = 0;
};

struct TDisparo{
  float x,y;
  TColor color;
  bool disparando = false;
  xemath::Vector2 vecDirector = {0.0f,0.0f};
};

struct TPlayer{
  TDisparo *disparos;
  int disparosTotal = 0;
  xemath::Vector2 vecDirector = {0.0f,-15.0f};   //Esto es a donde apunta
  xemath::Vector2 vecPunta = {100.0f, 100.0f};
  float x = 500.0f;
  float y = 400.0f;
  xemath::Vector2 aceleration = {0.0f,0.0f};
  xemath::Vector2 velocity = {0.0f,0.0f}; //NO SE USAeste depende de la direccion de la nave, cuando pulso w la aceleracion = aceleracion anterior + la nueva
  float velocidad = 0.1f;
  float angle;
  int nivel = 0;
  int vidas = 5;
  // int fuel = 10000;
  int fuel = 10000;
  int score = 0;
  float gravityForce = 0.01f;
  int timeLeft = 23;
  bool shield;
};

struct TEnemy{
  bool vivo = true;
  TDisparo *disparos;
  xemath::Vector2 vecDirector = {0.0f, -5.0f};
  xemath::Vector2 vecPunta = {100.0f, 200.0f};
  float x = 100.0f;
  float y = 300.0f;
  float velocidad = 1.0f;
  float gravityForce = 0.01f;
  float angle;
  bool canMove;
  int secondsToMove;
  int secondsToMoveCount;
};

struct TFuel{
  float x,y;
  bool obtained = false;
};


struct TFuelMat{
  esat::Vec3 *map;
  float *points;
  float escalar = 1.0f;
  int size;
  bool obtained;
};
struct TTurret{
  esat::Vec3 *map;
  float *points;
  float escalar = 100.0f;
  int size;
  bool vivo;
  TDisparo *disparos;
  int nextShootTurretTime = 6;
  int shootTurretFramesCont = 0;
};

struct TMap{
  esat::Vec3 *map;
  float escalar = 231.0f;
  int size;
  bool normalized;
};




float *points_tmp_map1 = (float*) calloc(0,sizeof(float) * 250); //91
float *points_tmp_map2 = (float*) calloc(0,sizeof(float) * 250); //150?
float *points_tmp_map2_bomb = (float*) calloc(0,sizeof(float) * 250); //49
float *points_tmp_map3 = (float*) calloc(0,sizeof(float) * 250); //74
float *points_tmp_map4 = (float*) calloc(0,sizeof(float) * 250); //74




TColor Rojo = {180,0,0};

TColor Verde = {0,180,0};
TColor VerdeClaro = {0,255,157};
TColor VerdeFuel = {144,210,145};
TColor VerdeScore = {72,147,74};

TColor Azul = {0,0,180};
TColor AzulClaro = {0,238,255};
TColor AzulText = {118,209,217};

TColor Blanco = {255,255,255};
TColor Negro = {0,0,0};

TColor Amarillo = {252,255,0};
TColor Morado = {255,0,243};
TColor MoradoOscuro = {192,0,255};
TColor Rosa = {255,0,154};

TPlayer player;
TPlayer player1;

TEnemy enemi1;



void Createcircle(float x, float y, float radio, TColor color = Rosa,float excentricidadX = 1.0f,float excentricidadY = 1.0f, int points = 32, int extravagancia = -1, float peculiaridad = -1.0f){
    
    if(points==0)printf("--------------------------\n--------------------------\n--------------------------\n--------------------------\n--------------------------\n--------------------------\nDebug %d--------------------------\n--------------------------\n--------------------------\n--------------------------\n--------------------------\n--------------------------\n\n", points);
    
    //Iniciar circulo
    float *circulo = (float*) malloc(sizeof(float)*(points * 3));
    float angle = (dPI*2) / (float) points;
    for(int i = 0; i<points; i++){
        if(extravagancia ==-1){
            *(circulo + (i * 2)) = (float) cos(angle * i) * excentricidadX;
            *(circulo + (i * 2 +1)) = (float) sin(angle * i) * excentricidadY;
        }else{
            //Cirulo raro
            if(i%extravagancia == 0){
                *(circulo + (i * 2)) = ((float) cos(angle * i) * excentricidadX) * peculiaridad;
                *(circulo + (i * 2 +1)) = ((float) sin(angle * i) * excentricidadY) * peculiaridad;
            }else{
                *(circulo + (i * 2)) = (float) cos(angle * i) * excentricidadX;
                *(circulo + (i * 2 +1)) = (float) sin(angle * i) * excentricidadY;

            }
        }
    }

    //Pintar circulo
    esat::DrawSetStrokeColor(color.r,color.g,color.b);
    esat::DrawSetFillColor(color.r,color.g,color.b,0);

    float *circleToDraw = (float*) malloc(sizeof(float)*(points*3));

    for(int i = 0; i<points; i++){
        *(circleToDraw + (i * 2)) = *(circulo + (i * 2)) * radio + x;
        *(circleToDraw + (i * 2 + 1)) = *(circulo + (i * 2 + 1)) * radio + y;
    }

    esat::DrawSolidPath(circleToDraw,points);
    free(circulo);
    free(circleToDraw);
}

void CheckColisionPlayerEnemy(TDisparo *disparo, bool enemy){
  //Colision del disparo del jugador contra el enemigo
  if(!enemy){
    if(enemi1.vivo && enemi1.canMove){
      xemath::Vector2 distancia = {enemi1.x - (disparo)->x, enemi1.y - (disparo)->y};
      //xemath::Vector2 distancia = {enemi1.x - (float) esat::MousePositionX(), enemi1.y - (float)esat::MousePositionY()};
      float modulo = xemath::Vec2Modulo(distancia);


      if (modulo <= ENEMY_HITBOX_SIZE){
        // enemi1.vivo = false;
        printf("AL CARRER en %f\n",modulo);
        player.score += 100;
      }else{
        // printf("Distancia-> %f EnemyX->%f EnemyY->%f\n",modulo,enemi1.x,enemi1.y);
      }
    }
  }

}

void DrawShoot(TDisparo *disparo, TColor color){
  // Pintar disparos
    if ((disparo)->disparando){

      (disparo)->x += (disparo)->vecDirector.x;
      (disparo)->y += (disparo)->vecDirector.y;
      // printf("Dibujar disparo en X->%f Y->%f\n", (disparo)->x, (disparo)->y);
      Createcircle((disparo)->x, (disparo)->y, 2, color, 1, 1, 8);

      // if ((disparo)->x <= 0 || (disparo)->x >= ANCHO || (disparo)->y <= 0 || (disparo)->y >= ALTO){
      //   // El disparo ha llegado al borde
      //   printf("\n-----\nLimite\n-----\n-----\n");
      //   (disparo)->disparando = false;
      // }

    }
  
}

bool Disparo(TDisparo *disparo, float x, float y, xemath::Vector2 vecDirector,TColor color = Blanco, bool enemy = false, bool enemyShooting = false){
  bool die = false; //bool para el disparo de las torretas con el player
  //Entrará cuando pulse la tecla o cuando sea un enemigo
  if (esat::IsSpecialKeyDown(esat::kSpecialKey_Enter) || esat::IsSpecialKeyDown(esat::kSpecialKey_Space) || enemy){
    bool encontrado = false;
    // Recorrer los 4 disparos buscando uno que esté libre, en caso de estarlo, le damos sus valores y lo ponemos como disparando
    for (int i = 0; i < 4; i++){
      // Disparo libre encontrado
      if (!(disparo + i)->disparando && !encontrado){
        encontrado = true;
        // if(enemy)printf("Disparo enemigo encontrado\n");
        (disparo + i)->disparando = true;
        (disparo + i)->x = x;
        (disparo + i)->y = y;
        (disparo + i)->vecDirector = vecDirector;

        //Lo normalizo solo para el jugador porque el vector director del enemigo ya llega normalizado
        if(!enemy){
          (disparo + i)->vecDirector = xemath::Vec2Normalize((disparo + i)->vecDirector);
        }
        (disparo + i)->vecDirector.x = (disparo + i)->vecDirector.x * 3;
        (disparo + i)->vecDirector.y = (disparo + i)->vecDirector.y * 3;

      }



    }
  }

  for (int i = 0; i < 4; i++){
    DrawShoot((disparo + i), color);

      // printf("Disparando-> %d\n",((disparo +i)->disparando));
    if((disparo+i)->disparando){

      if(enemyShooting){
        //Comprobar modulo del disparo de la torreta con el player
   

            float xdisp = ((disparo +i)->x);
            float ydisp = ((disparo +i)->y);
            xemath::Vector2 disparoVector = {player.x - xdisp,player.y - ydisp};
            float moduloDisparo = xemath::Vec2Modulo(disparoVector);
            if(moduloDisparo<=20){
              printf("Modulo->%f\n",moduloDisparo);
              die = true;
              (disparo+i)->disparando = false;

            }
        
      }

    if ((disparo+i)->x <= 0 || (disparo+i)->x >= ANCHO || (disparo+i)->y <= 0 || (disparo+i)->y >= ALTO){
        // El disparo ha llegado al borde
        // printf("\n-----\nLimite i->%d X[%f] Y[%f]\n-----\n-----\n",i, (disparo + i)->x, (disparo + i)->y);
        (disparo+i)->disparando = false;
        (disparo+i)->x = 1.0f;
        (disparo+i)->y = 1.0f;
      }

    }
    // printf("Disparando-> %d [%d]\n", (disparo+i)->disparando,i);
    if((disparo+i)->disparando && (disparo+i)->x > 0 && (disparo+i)->x < ANCHO && (disparo+i)->y > 0 && (disparo+i)->y < ALTO){
      // printf("Enviar disparo->%d [%d]\n",(disparo+i)->disparando,i);
      // CheckColisionPlayerEnemy((disparo + i),enemy);
    }
    
  }


  
  return die;
  }

char* IntToAscii(int number, bool addCeros = true){
    // printf("INIT Int to asci\n");
    char *numberToChar = (char*) calloc('\0',sizeof(char)*7);
    char *aux = (char*) malloc(sizeof(char)*7);
    itoa(number,aux,10);
    //Añadimos los 0 correspondientes segun la puntuacion
    if(addCeros){
        
        if(number>=10000){
            *numberToChar = '0';
        }else if(number>=1000){
            *numberToChar = '0';
            *(numberToChar+1) = '0';
        }else if(number>=100){
            *numberToChar = '0';
            *(numberToChar+1) = '0';
            *(numberToChar+2) = '0';
        }else if(number>=10){
            *numberToChar = '0';
            *(numberToChar+1) = '0';
            *(numberToChar+2) = '0';
            *(numberToChar+3) = '0';
        }else{
            *numberToChar = '0';
            *(numberToChar+1) = '0';
            *(numberToChar+2) = '0';
            *(numberToChar+3) = '0';
            *(numberToChar+4) = '0';
        }
    }

    strcat(numberToChar,aux);
    *(numberToChar+strlen(numberToChar)) = '\0';
    free(aux);
    // printf("Int to asci OKKK\n");
    return numberToChar;
    // free(numberToChar);
}

float valorScalate = 1.05f;




void DebugPointer(float *ptr, int sizePtr){
  for (int i = 0; i < sizePtr; i++){
    printf("Valor [%f] Memoria [%p]\n",*(ptr+i),(ptr+i));
  }
  printf("----------------\n");
  
}


#include "player.cc"
#include "colisiones.cc"
#include "fuel.cc"
#include "gravity.cc"
#include "turret.cc"
#include "map.cc"
#include "enemies.cc"
#include "geometries.cc"
#include "interface.cc"