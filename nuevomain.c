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

void separador(char comando[], char *comandoseparado[], char simbolo[]){
  char * puntero;
  int k = 0;
  puntero = strtok(comando,simbolo);
  while(puntero!=NULL){
   comandoseparado[i] = puntero;
   puntero = strtok(NULL,simbolo);
   i++;
   }
}
int main(){
	while(1){
		char command[100];
		print("-> ");
		scanf("%99[^\n]",command);
		if (!strcmp("exit",command)){
			break:
		}

		pid_t pid = fork();
		if(!pid){
			//execute(comando);  //funcion de los manes 
		}else{
			wait(NULL);
		}

	}
	return 0;
}

