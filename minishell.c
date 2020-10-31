#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "minishell.h"

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
