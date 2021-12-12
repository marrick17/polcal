#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "smal_lib.h"

#define VARISIZE 50 

/*****************************************************************************************************************************/
/*get_variable(sgetop_num, sgetop_name): get the variable name and number*/
/*****************************************************************************************************************************/
void get_variable( char* sgetop_num, char* sgetop_name){

  char toanalysis[VARISIZE];

  printf("Enter variable as  [NAME] = [NUMBER] or as [NAME] = [NAME]\n");
  ngetline(toanalysis, VARISIZE);

  char* pvarline = &toanalysis[0];
  char* ptr_num  = &sgetop_num[0];
  char* ptr_name = &sgetop_name[0];
  
  /*skip space*/
  for(; *pvarline == ' ' || *pvarline == '\t'; pvarline++){
    ;
  }
  
  /*Check the first character; if not valid exit*/
  if( (*pvarline >= 'A' && *pvarline <= 'Z') && ( *(pvarline+1) == ' ' || *(pvarline+1) == '=') ){
    
    /*Store the name*/
    *ptr_name++ = *pvarline;
    *ptr_name = '\0';
    
    ++pvarline;
  }
  else{
    printf("Error: not valid name for a variable\n");
    return;
  }
    
  /*skip space*/
  for(; *pvarline == ' ' || *pvarline == '\t'; pvarline++){
    ;
  }
    
  /*if we are not at '= 256', exit */
  if(*pvarline == '=' && (isdigit(*(pvarline+1)) || *(pvarline+1) == ' ' || *(pvarline+1) == '\t')){
      ++pvarline;
  }
  else{
    printf("Error:The input to the variable is not valid\n");
    return;
  }
    
  /*skip space*/  
  for(; *pvarline == ' ' || *pvarline == '\t'; pvarline++){
    ;
  }
    
  /*if we are not at digit, exit*/
  if( isdigit(*pvarline) ){
    *ptr_num++ = *pvarline++; /*The first letter*/
  }
  else{
    printf("Error: input to the variable is not valid\n");
    return;
  }
    
  /*Get the rest of the number*/
  for ( ;isdigit(*pvarline); pvarline++, ptr_num++){
    
    *ptr_num = *pvarline;
    
  }
    
  if((*pvarline == '.' && isdigit(*(pvarline+1))) || *pvarline == '\n' ){

    if (*pvarline == '\n'){
      
      *ptr_num ='\0';        /*valid number: integer*/

      printf("The variable %s has been assigned to %s.\n", sgetop_name, sgetop_num );
      
    }
    else{
      for(*ptr_num = *pvarline++; isdigit(*pvarline); pvarline++, ptr_num++){
	*ptr_num = *pvarline;
      }
       /*skip space*/
      for(; *pvarline == ' ' || *pvarline == '\t'; pvarline++){
	 ;
      }
      
      if (*pvarline == '\n'){
	*ptr_num  = '\0';     /*valid number: floating pt */
	printf("The variable %s has been assigned to %s.\n", sgetop_name, sgetop_num);
      }
      else{
	printf("Error: input to the variable is not valid");
        return;
      }
      
      
    }

  }
  else {
    printf("Error: input to the variable is not valid\n");
    return;
  }

}
/*****************************************************************************************************************************/
