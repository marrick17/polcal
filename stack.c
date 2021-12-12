#include <stdio.h>

#define MAXVAL 100     /*maximum depth of val stack*/
static double val[MAXVAL];    /*value stack*/
static double *sp = &val[0];  /*next free stack position*/

/***************************************************************************************************/
/*push() & pop() & clrstak() & prtopstack() & swapsanspop() */
/***************************************************************************************************/
/*push(): push f onto the value stack*/
/*********************************************************/
void push(double f){

  if(sp < &val[MAXVAL]){
    *sp++ = f;
  }
  else{
    printf("Error! stack full, can't push %g\n", f);
  }
  
}
/*********************************************************/
/*pop(): pop and return top value from the stack*/
/*********************************************************/
double pop(void){
  
  if (sp > &val[0]){
    return *--sp;
  }
  else{
    printf("Error! stack empty\n");
    return 0.0;
  }

}
/*********************************************************/
/*clrstak(): clear the stack*/
/*********************************************************/
void clrstak(void){

  double *staptr;

  for( staptr = &val[0]; staptr < sp; staptr++ ){
    *staptr = 0;
  }

  sp = &val[0];

}
/**********************************************************/
/*prtopstack(): print the top of the stack*/
/**********************************************************/
void prtopstack(void){
  
  if (sp > &val[0]){
    
    printf("The Top of the stack is %f\n", *(sp-1));
    return;
  }
  else {
     printf("Error! stack empty\n");
    return;
  }
}
/**********************************************************/
/*swapsanspop(): swap the the last two elements of the stack*/
/**********************************************************/
void swapsanspop(void){
  
  if(sp >= &val[2]){

    double temp = *(sp-1); 
    
    *(sp - 1) = *(sp - 2);
    *(sp - 2) = temp;
  }
  else{
    printf("Error! At least two elements are needed for a swap.\n");
  }
  
}
/******************************************************************************************************/
