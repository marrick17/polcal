#include <stdbool.h>
#include "smal_lib.h"
#include "command.h"

/******************************************************************************************************/
char locate_command(char *s){
 
  int i;

  static char *c[] = {"%\0", "/\0", "sin\0", "exp\0", "pow\0", "swap\0", "ptop\0", "clrstk\0", "var\0", "delvar\0", "*\0" };

  for(i = 0; i < NUM_COMMANDS && !(comparestr(c[i], s)) ; i++){
    ;
  }

  switch(i){
    
  case 0:
    return MODULUS;
    break;
    
  case 1:
    return DIVIDE;
    break;
    
  case 2:
    return SINE;
    break;
    
  case 3:
    return EXPONENT;
    break;
    
  case 4:
    return POWER;
    break;

  case 5:
    return SWAP;
    break;

  case 6:
    return PTOP;
    break;
    
  case 7:
    return CLEARSTACK;
    break;
    
  case 8:
    return VARIABLE;
    break;

  case 9:
    return DELVARIABLE;
    break;

  case 10:
    return MULTIPLY;
    break;
      
  case 11:
    return CORRUPTION;
    break;
    
    
  }

}
/************************************************************************************************************************/
