#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define READ  0
#define WRITE 1


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
   //parametros para el arreglo de valores de la cadena
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


int main(int argc,char *argv[])
{
    //Definicion de arreglos de valores de las cadenas de comandos
    int lonL= wordCounter(argv[1]);
    int lonR= wordCounter(argv[2]);
    char *Lvals[lonL+1];
    char *Rvals[lonR+1];
    arrayChunks(argv[1],Lvals,lonL);
    arrayChunks(argv[2],Rvals,lonR);

    //TEST EJECUACION  PIPE EXCVP
    /*char *aa[3]={"cat","p4.c",NULL};
    char *bb[3]={"wc","-l",NULL};

    int h=0;
    while(Lvals[h] != NULL){
    printf("valor %d del arreglo L %s\n",h,Lvals[h]);
    h++;
    }*/

    //definiciones para el pipe
    pid_t pid;
    int fd[2];

    if (pipe(fd)==-1){
    perror("Creating pipe");
    exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1){

       perror("fork() failed xd");
       exit(EXIT_FAILURE);

    } else if (pid == 0){

       //// Close the pipe write descriptor.
       close(fd[WRITE]);
       // Redirect STDIN to read from the pipe.
       dup2(fd[READ], STDIN_FILENO);
       // Execute wc
       execvp(Rvals[0],Rvals);

    } else {

       // Close the pipe read descriptor.
       close(fd[READ]);
       // Redirect STDOUT to write to the pipe.
       dup2(fd[WRITE], STDOUT_FILENO);
       // Execute ls -l
       //execvp(Lvals[0],Lvals);
       execvp(Lvals[0],Lvals);
  }

    //TEST DE EJECUCION DEL ARREGLO
    /*
    printf("valor 0 del arreglo L %s\n",Lvals[0]);
    printf("valor 1 del arreglo L %s\n",Lvals[1]);

    printf("valor 0 del arreglo R %s\n",Rvals[0]);
    printf("valor 1 del arreglo R %s\n",Rvals[1]);
    */
}
