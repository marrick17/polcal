#include<stdio.h>
#include<stdlib.h>/*for atof()*/
#include<math.h>
#include <stdbool.h>
#include"calc.h"
#include"smal_lib.h"
#include "command.h"



#define VARISIZE 10
#define MAXOP 100
/********************************************************************************************/
int main(){

  int type;
  double op2;
  //double swap1;
  //double swap2;

  
  char variable_num[VARISIZE];
  char variable_name[VARISIZE];
  char del_vari_name[VARISIZE];
  char ans_str[10];
  double ans_num;
  
  char s[MAXOP];

  while((type = getop(s)) != EOF){
    switch(type){

    case '+':
      push(pop() + pop());
      break;
      
    case '-':
      push(-1 *(pop()) + pop() );
      break;
      
    case MULTIPLY:
      push( pop() * pop() );
      break;

    case MODULUS:
      op2 = pop();
      if (op2 != 0.0){
	push( ( (int)pop() ) % ( (int)op2 ) );
      }
      else{
	printf("error: zero divisor\n");	  
      }
      break;
    
    case DIVIDE:
      op2 = pop();
      if(op2 != 0.0){
	push(pop()/op2);
      }
      else{
	printf("error: zero divisor\n");	  
      }
      break;

    case SINE:
      push(sin(pop()));
      break;

    case EXPONENT:
      push(exp(pop()));
      break;   

    case POWER:
      push(pow(pop(), pop()));
      break;

    case SWAP:
      
      /* 
      swap1 = pop();
      swap2 = pop();
      push(swap2);
      push(swap1);
      */

      swapsanspop(); 
      break;

    case PTOP:
      prtopstack();
      break;

    case CLEARSTACK:
      clrstak();
      break;

    case VARIABLE: /*var*/
      get_variable( variable_num, variable_name);
      vari_handler_assign( variable_name, variable_num);
      break;

    case DELVARIABLE: /**/
      vari_handler_clr(del_vari_name);
      break;

    case NUMBER:
      push(atof(s));
      break;

    case '\n':
      ans_num = pop();
      
      ftoa(ans_num,ans_str);
	
      vari_handler_clr_ans();
      vari_handler_assign_ans(ans_str);
     
      printf("\t%.8g\n", ans_num); 
      break;
      
    case  CORRUPTION:
      printf("Error! unknown command %s\n", s);
      break;
      
    }
  
  }
  return 0;
}

/********************************************************************************************/

