#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "auxiliar.h"
   //Este programa procesa cada fichero en el orden indicado(o en su defecto,la entrada estándar)leyendo cada línea y emite por su sálida estándar dichas líneas,pero en orden inverso,es decir,la primera línea del primer fichero deberá ser la última mostrada,y la primera mostrada la última del último fichero. 
     

      int main(int argc, char* argv[]){//Declaramos el main al que se le pasa por argumentos:argc que son el número de parámetros y argv que son los parámetros del ejecutable
       char array[2048];//Lineas que se van leyendo
       char **linea; //Array con las líneas que se han ido leyendo
       int leidas;//número de lineas leidas
       int j;//Variable de recorrido
argv0 = "bocabajo";
    
       //Tenemos dos argumentos
   if(((argc==2) && strcmp(argv[1],"-h") ==0)||((argc==2) && strcmp(argv[1], "--help")==0)){
           fprintf(stdout, "bocabajo: Uso: bocabajo [ fichero... ]\n");
           fprintf(stdout, "bocabajo: Invierte el orden de las líneas de los ficheros (o de la entrada).\n");
       
           return EX_OK;
    }
       
// Comprobación de error:Alguno de los archivos no es legible
        int i;//Declaramos una variable de recorrido
        FILE *archivo;
        

       for(i=1; i<argc; i++){//Mientras haya ficheros sin abrir
          

    linea=(char **)malloc(sizeof(char *));//Reservamos el espacio de memoria 
    leidas=0;//incializamos para luego ir almacenando las líneas leídas

        if(!linea){//Sino se puede reservar memoria 
            Error(EX_OSERR,"No se pudo ubircar la memoria dinamica necesaria");

         }

 archivo = fopen(argv[i],"r");//Abrir el fichero
          if(archivo == NULL){

             Error(EX_NOINPUT, "El fichero \"%s\" no pudo ser leido", argv[i]);

          }
          
          else{//Sino lo cerramos
                       while(fgets(array,100000,archivo)!=NULL){
if( (strlen(array)-1)>2048){Error(EX_OSERR,"No se pudo ubircar la memoria dinamica necesaria");}
              linea[leidas]=strdup(array);
              leidas++;
              linea=(char **)realloc(linea,sizeof(char *) *(leidas+1));//Reservamos la memoria con argumentos un puntero y el tamaño
              
              if(!linea){//Si no se puede reservar memoria
                  Error(EX_OSERR,"No se pudo ubircar la memoria dinamica necesaria");}
               }
               fclose(archivo);
          }
    }


   
   
   i=argc-1;
   while(i>0){
         leidas=0;


        archivo = fopen(argv[i],"r");//Abrimos el archivo
        while(fgets(array,2048,archivo)!=NULL){
              linea[leidas]=strdup(array);
              leidas++;
              linea=(char **)realloc(linea,sizeof(char *) *(leidas+1));//Reservamos la memoria con argumentos un puntero y el tamaño
              
               }
    
              j=leidas;

              while(j>0){
                    printf("%s",linea[j-1]);
                    j--;
              } 
              fclose(archivo);
      i--;


}

 return EX_OK; 
    
}

