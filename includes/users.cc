#include <stdio.h>
#include <iostream>
#include <cstring>

struct Nacimiento{
  char dia[10];
  char mes[10];
  char anyo[10];
  char provincia[30];
};

struct Persona{
  int id;
  char nombre[20];
  char apellido1[30];
  char apellido2[30];
  Nacimiento nacimiento;
  char telefono[20];
  char email[50];
  int puntuacion;
  int creditos;
  char password[20];
};

int valor;
Persona *personas = (Persona*) malloc(sizeof(Persona)*50);
FILE *f, *fnew;

void DeleteEnter(char palabra[80]){
  palabra[strlen(palabra)-1] = '\0';
}

void FreeCache(){
  char *basura;
  printf("Presione cualquier tecla para borrar\n");
  basura = (char *)calloc(32, sizeof(char));
  fgets(basura, 32, stdin);
  free(basura);
}


void Create(){
  Persona per;
  Nacimiento nac;


  printf("Nombre:\n");
  fgets(per.nombre,20,stdin);
  DeleteEnter(per.nombre);
  for (int i = 0; i < strlen(per.nombre); i++){
    per.nombre[i]=toupper(per.nombre[i]);
  }


  printf("Introduzca una password\n");
  fgets(per.password,20,stdin);
  DeleteEnter(per.password);

  printf("Apellido1: \n");
  fgets(per.apellido1,20,stdin);
  DeleteEnter(per.apellido1);
  // per.apellido1[strlen(per.apellido1)-1]='\0';

  printf("Apellido2: \n");
  fgets(per.apellido2,20,stdin);
  DeleteEnter(per.apellido2);
  // per.apellido2[strlen(per.apellido2)-1]='\0';


  //------
  printf("Dia de nacimiento:\n");
  fgets(nac.dia,20,stdin);
  DeleteEnter(nac.dia);

  printf("Mes de nacimiento:\n");
  fgets(nac.mes, 20, stdin);
  DeleteEnter(nac.mes);

  printf("Any de nacimiento:\n");
  fgets(nac.anyo, 20, stdin);
  DeleteEnter(nac.anyo);

  printf("Provincia:\n");
  fgets(nac.provincia,20,stdin);
  DeleteEnter(nac.provincia);

  per.nacimiento = nac;
  //------



  printf("Telefono;\n");
  // fgets(per.telefono,20,stdin);
  fgets(per.telefono,20,stdin);
  // printf("Telefono antes-> %s\n",per.telefono);
  DeleteEnter(per.telefono);
  // per.telefono[strlen(per.telefono)-1]='\0';

  // printf("Telefono despues-> %s\n",per.telefono);

  printf("Email:\n");
  fgets(per.email,50,stdin);
  DeleteEnter(per.email);
  // per.email[strlen(per.email)-1]='\0';

  printf("%s %s %s %s %s %s %s %s %s %s\n",per.nombre,per.password, per.apellido1, per.apellido2,
                                        per.nacimiento.dia, per.nacimiento.mes, per.nacimiento.anyo, per.nacimiento.provincia,
                                        per.telefono,per.email);
  f=fopen("usuarios.dat","rb");

  per.puntuacion = 0;
  per.creditos = 0;
  //Coger el id de la ultima persona y sumarle 1
  int last_id = -1;
  Persona last_per;

  //Comprobamos si hay alguna persona ya a??adida, en ese caso las recorremos todas buscando la ultima
  if(fread(&last_per,sizeof(Persona),1,f)){
    printf("Ya hay alguien\n");
    //Movemos el offset al principio
    // fseek(f,sizeof(Persona),SEEK_CUR);
    rewind(f);

    while(fread(&last_per,sizeof(Persona),1,f)){
      fseek(f,-1*sizeof(Persona),SEEK_END);
      fread(&last_per,sizeof(Persona),1,f); //Cogemos la ultima persona
      last_id = last_per.id;
      printf("Id leido->%d\n",last_per.id);
      fseek(f,sizeof(Persona),SEEK_CUR);
    }
  }else{
    printf("Primer usuario\n");
  }
  fclose(f);
  per.id = last_id + 1;
  printf("Id de la ultima persona %d id de la nuev apersona %d\n",last_id,per.id );


  f=fopen("usuarios.dat","ab");
  fwrite(&per,sizeof(Persona),1,f);
  fclose(f);
}

void ReadAllPersonas(int size, Persona *personas){
  for (int i = 0; i < size; i++){
    printf("\n--------------------------------------------------\n");
    printf("Id: %d | Nombre: %s |Password: %s | Apellido1 %s | Apellido2 %s | Nacimiento: %s/%s/%s | Provincia: %s | tlf: %s | Email:%s | Puntuacion Maxima: %d | Creditos: %d\n", (personas+i)->id, (personas+i)->nombre,(personas+i)->password, (personas+i)->apellido1, (personas+i)->apellido2,
     ((personas+i)->nacimiento).dia,
      (personas+i)->nacimiento.mes, (personas+i)->nacimiento.anyo, (personas+i)->nacimiento.provincia,
      (personas+i)->telefono, (personas+i)->email,
      (personas+i)->puntuacion, (personas+i)->creditos);
  }
//   free(personas);
}



int LoadToMemory(Persona *personas){
    // printf("Abriendo fichero...\n");
    int index = 0;
    if(f = fopen("./includes/usuarios.dat", "rb")){
        
        // printf("----Fichero abierto Ole los caracoles----\n");  
        Persona per;

        while (fread(&per, sizeof(Persona), 1, f)){
            // printf("Leyendo fichero\n");

            *(personas + index) = per;
            // printf("\n--------------------------------------------------\n"); //
            // printf("Id: %d | Nombre: %s | apellido1 %s | apellido2 %s | Nacimiento: %s/%s/%s | Provincia: %s | tlf: %s | Email: %s | Puntuacion Maxima: %s\n", per.id, per.nombre, per.apellido1, per.apellido2, per.nacimiento.dia, per.nacimiento.mes, per.nacimiento.anyo,per.nacimiento.provincia, per.telefono, per.email, per.puntuacion);
            // printf("Id: %d | Nombre: %s | Contrase??a %s | Apellido1 %s | Apellido2 %s | Nacimiento: %s/%s/%s | Provincia: %s | tlf: %s | Email:%s | Puntuacion Maxima: %d\n", per.id, per.nombre,per.password, per.apellido1, per.apellido2, per.nacimiento.dia, per.nacimiento.mes, per.nacimiento.anyo, per.nacimiento.provincia, per.telefono, per.email, per.puntuacion);
            index++;
        }
        fclose(f);
    }else{
        printf("Error abriendo fichero usuarios.dat\n");
    }

    return index;
}

void Read(){

  int size = LoadToMemory(personas);
  // ReadAllPersonas(size,personas);
}

void Update(){
  f=fopen("usuarios.dat","r+b");
  int id;
  Persona per;
  bool encontrado = false;
  printf("Introduzca el id de la persona\n");
  scanf("%d",&id);

  while(fread(&per,sizeof(Persona),1,f)){

    if(per.id == id){
      //Persona encontrada
      encontrado=true;
      printf("Que valor quiere cambiar?\n");
      printf("1- Nombre\n2- Apellido1\n3- Apellido2\n4- Dia nacimiento\n5- Mes nacimiento\n6- Anyo nacimiento\n7- telefono\n8- Email\n");
      int opcion=(int)getch();
      opcion-=48;
      char aux[20];
      fgets(aux,20,stdin); //Vaciar el buffer
      switch (opcion) {
        case 1:
          printf("Introduzca nuevo nombre\n");
          fgets(per.nombre,20,stdin);
          per.nombre[strlen(per.nombre)-1]='\0';
        break;
        case 2:
          printf("Introduzca nuevo Apellido1\n");
          fgets(per.apellido1,20,stdin);
          per.apellido1[strlen(per.apellido1)-1]='\0';
        break;
        case 3:
          printf("Introduzca nuevo Apellido2\n");
          fgets(per.apellido2,20,stdin);
          per.apellido2[strlen(per.apellido2)-1]='\0';
        break;
        case 4:
          printf("Introduzca nuevo Dia de nacimiento\n");
          fgets(per.nacimiento.dia, 10, stdin);
          // scanf("%d",&per.nacimiento.dia);
          
        break;
        case 5:
          printf("Introduzca nuevo Mes de nacimiento\n");
          fgets(per.nacimiento.mes, 10, stdin);
          // scanf("%d", &per.nacimiento.mes);
          break;
        case 6:
          printf("Introduzca nuevo Anyo de nacimiento\n");
          fgets(per.nacimiento.anyo, 10, stdin);
          // scanf("%d",&per.nacimiento.anyo);
          break;
        case 7:
          printf("Introduzca nuevo Telefono\n");
          fgets(per.telefono,20,stdin);
          per.telefono[strlen(per.telefono)-1]='\0';
        break;
        case 8:
          printf("Introduzca nuevo Email\n");
          fgets(per.email,20,stdin);
          per.email[strlen(per.email)-1]='\0';
        break;
      }
      fseek(f,-1*sizeof(per),SEEK_CUR);
      fwrite(&per,sizeof(Persona),1,f);
      fseek(f,sizeof(valor),SEEK_CUR);
    }
  }
  fclose(f);
  if(!encontrado)printf("Persona no encontrada\n");
}

void Delete(){
  f=fopen("usuarios.dat","rb");
  fnew=fopen("newusuarios.dat","wb");
  Persona per;
  int id;
  char id_char[3];
  printf("Introduzca el id del usuario que desea borrar\n");
  scanf("%d",&id);
  printf("Id introducido %d\n",id );
  FreeCache();
  

  bool encontrado = false;
  while(fread(&per,sizeof(Persona),1,f)){
    if(per.id != id){
      fwrite(&per,sizeof(Persona),1,fnew);
    }else{
      encontrado = true;
    }
  }
  if(!encontrado)printf("Usuario no encontrado\n");
  fclose(f);fclose(fnew);
  remove("usuarios.dat");
  rename("newusuarios.dat","usuarios.dat");

}
void Menu(){
  int opcion;

  do{

    printf("\n1- Alta\n2- Baja\n3- Consultar\n4- Modificar\n5- Salir\n");
    opcion=(int)getch();

    
    opcion-=48;
    printf("Opcion elegida %d\n",opcion);
    // scanf("%d",&opcion);
    switch (opcion) {
      case 1:Create();break;
      case 2:Delete();break;
      case 3:Read();break;
      case 4:Update();break;
    }
  }while(opcion!=5);
}