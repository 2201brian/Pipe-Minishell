#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int haysimbolopipe(char comando[]){
  if(strchr(comando, '|')!=NULL){
     return 1;
   }
   return 0;
}

int haysimbolodireccion(char comando[]){
  if(strchr(comando, '>')!=NULL){
     return 1;
   }
   return 0;
}

/*void separador(char comando[], char *comandoseparado[], char simbolo[]){
  char * puntero;
  int k = 0;
  puntero = strtok(comando,simbolo);
  while(puntero!=NULL){
   comandoseparado[i] = puntero;
   puntero = strtok(NULL,simbolo);
   i++;
   }
}*/

//wordCounter cuentas las palabras en una cadena, conciderandolas por espacio
int wordCounter(char cadena[]){
    //Contar palabras de la cadena
    int i=0, cont=0;
    int longitud = strlen(cadena);

    while(i<longitud){
        while(cadena[i]==' '){
        i=i+1;
        }
        cont=cont+1;
        while(cadena[i]!=' '){
        i=i+1;
        }
   }
   //printf("Longitud del arreglo cont+1 = %d\n", cont+1);
   return cont;
}

//arrayChunks recibe una cadena y un arreglo de la longitud de pablabras de la cadena
//se llena el arreglo con las palabras de la cadena
void arrayChunks(char cadena[],char *cadenaVals[], int wc){
   char delimitador[] = " ";
   char *token = strtok(cadena, delimitador);
    int j=0;
    while (j<wc){
        cadenaVals[j]=token;
        //printf("Encontramos un token: %s\n", token);
        token = strtok(NULL, delimitador);
        j++;
    }
    cadenaVals[wc]=NULL;
}

void execute(char command[]){
   int size = strlen(command);
   if (haysimbolopipe(command)==0 && haysimbolodireccion(command)==0){
      int lon= wordCounter(command);
      char *vals[lon+1];
      arrayChunks(command,vals,lon);
      execvp(vals[0],vals);
   }
}

int main(){
        while(1){
                char command[100];
                printf("-> ");
                scanf("%99[^\n]",command);
                if (!strcmp("exit",command)){
                        break;
                }

                pid_t pid = fork();
                if(!pid){
                        execute(command);
                }else{
                        wait(NULL);
                }

        }
        return 0;
}

