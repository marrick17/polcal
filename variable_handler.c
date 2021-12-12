#include <stdbool.h>
#include <stdio.h>
#include "smal_lib.h"

/********************************************************************************************/
static char var_num_array[270];
static char *variable_handler_a[][2] ={
  {"A\0", NULL}, {"B\0", NULL}, {"C\0", NULL}, {"D\0", NULL}, {"E\0", NULL},
  {"F\0", NULL}, {"G\0", NULL}, {"H\0", NULL}, {"I\0", NULL}, {"J\0", NULL},
  {"K\0", NULL}, {"L\0", NULL}, {"M\0", NULL}, {"N\0", NULL}, {"O\0", NULL},
  {"P\0", NULL}, {"Q\0", NULL}, {"R\0", NULL}, {"S\0", NULL}, {"T\0", NULL},
  {"U\0", NULL}, {"V\0", NULL}, {"W\0", NULL}, {"X\0", NULL}, {"Y\0", NULL},
  {"Z\0", NULL}, {"ans\0", &var_num_array[260]}
};
/********************************************************************************************/



/**************************************************************************************************************************/
/*
vari_handler_assign(vari_name, vari_num):
(1) Search the pointer two dimensional array,char (**vari_handler_arr)[2],  for 
vari_name which is to be found in the first elment of a cell; if not found print an error message;
 Else, when this cell is located, if the second element is NULL, place vari_num into into the second element.
2)If this pointer is not null, print a message telling the user that the  
variable name is occupied and that she needs to delete it.
*/
/**************************************************************************************************************************/
void vari_handler_assign(char *vari_name, char *vari_num){
  
  int size = 26;
  int i,k;

  /*search for vari_name in variable_handler_a[]*/
  for(i = 0 ; i < size && !(comparestr( (*(variable_handler_a + i))[0], vari_name ) ); i++){
    ;
  }
  
  /*vari_name is not in variable_handler_a[]*/
  if (i >= size){   
    printf("Error: %s is not recognised as a variable\n", vari_name);
    return;   
  }

  
  if(  (*(variable_handler_a + i))[1] == NULL ){
    
    k =  10*i;

    (*(variable_handler_a + i))[1] = &var_num_array[k];
    
    nstrcpy( (*(variable_handler_a + i))[1], vari_num);

    return;
    
  }
  else{
    
    printf("ERROR: the variable %s is occupied; clear before assignment\n", vari_name );
    return;
    
  }

  
}
/****************************************************************************************************************************/

/****************************************************************************************************************************/
/*vari_handler_clr(vari-name) Delete the value of the previous assignmenment and make it ready for the new assignment*/
/****************************************************************************************************************************/
void vari_handler_clr(char *vari_name){

  int size = 26;
  int i, k, count;

  printf("Enter the name of the variable that you want to delete\n");
  int line_size = ngetline(vari_name, 5);
  vari_name[line_size -1] = '\0';     /*replace the '\n' with '\0'*/
  
  for(i = 0 ; i < size && !(comparestr( (*(variable_handler_a + i))[0], vari_name )); i++){
    ;
  }

  /*vari_name is not in variable_handler_a[]*/
  if (i >= size){   
    printf("Error: %s is not recognised as a variable\n", vari_name);
    return;   
  }
  
  if(  (*(variable_handler_a + i))[1] == NULL ){
    printf("%s is already open for assignment\n", vari_name);
    return;
  }
  else{
    
     k =  10*i;
     for( count = k+10; k < count; ){
       var_num_array[k++] = '\0'; 
     }
     
     (*(variable_handler_a + i))[1] = NULL;

     printf("%s is now ready for assignment\n", vari_name);
  
  }

}
/*****************************************************************************************************************************/

/******************************************************************************************************************************/
/**********************************************************************************************/
/*vari_handler_clr_ans(void):*/
/**********************************************************************************************/
void vari_handler_clr_ans(void){

  int end, k;
  for( k =260, end = 270; k < end; k++ ){
       var_num_array[k] = '\0'; 
     }    
}

/**********************************************************************************************/


/**********************************************************************************************/
/*it is assumed that vari_handler_clr_ans is called before */
/**********************************************************************************************/
void vari_handler_assign_ans(char *ans_str){
  
  nstrcpy( (*(variable_handler_a + 26))[1], ans_str);
  
}
/******************************************************************************************************************************/


/*******************************************************************************************************/
    /*
       search variable_array_a; if s is found to be a vari_name  and its  vari_num is not NULL; copy 
       var_num into s[]; return NUMBER. If no, search command list.
    */
/*******************************************************************************************************/
bool vari_search(char *s){
 
  int size = 27;
  int i;

  /*search for vari_name in variable_handler_a[]*/
  for(i = 0 ; i < size && !(comparestr( (*(variable_handler_a + i))[0], s ) ); i++){
    ;
  }

  if (i >= size){   
   
     return false; /* s is not a variable name*/
    
  }
  
  if(  (*(variable_handler_a + i))[1] != NULL ){

    nstrcpy(s, (*(variable_handler_a + i))[1] );

    return true;
  }
  
  return false;

}
/************************************************************************************************************************/

