#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
//incluir .h de declaracion funciones

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
