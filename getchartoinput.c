#include <stdio.h>
#include <stdbool.h>
#include"smal_lib.h"

#define BUFSIZE 1000
static int buf[BUFSIZE];
static int *bufp = &buf[0];


/*******************************************************************************************************/
/*getch() & ungetch() & ungets()*/
/*******************************************************************************************************/
int getch(void){
  
  return (bufp > &buf[0])? *--bufp: getchar();
  
}
/***************************************************************************/
void ungetch(int c){        /*push character back on input*/

  if (bufp >= &buf[BUFSIZE]){
    
    printf("ungetch: too many characters\n");
    
  }
  else{
    
    *bufp++ = c;
    
  }
}
/***************************************************************************/

/***************************************************************************/
void ungets(char *s){
  
  nreverse(s);
  ungetch('\0');
  
  for( ;*s!= '\0' ; s++ ){
    ungetch(*s) ;
  }
  
}
/******************************************************************************************************/