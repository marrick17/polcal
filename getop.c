/**********************************************************************/
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "command.h"
#include "calc.h"
/**********************************************************************/

/********************************************************************************************/
int getop(char s[]){

  int c;
  int cdeux;
  char command_value;
  char *operp = &s[0];
  bool notsignednum = true;

  /*skip white space*/
  while((c = getch()) == ' ' || c ==  '\t'){   
     ;  
  }
  if (c == EOF){
    return EOF;
  }
  /*first non- whitespace character*/
  *operp++ = c;
  *operp = '\0';

  
  if (c== '\n'){  /* execute*/
    return c;
  }

  
  /*if the command is totally alphanuaeric*/
  if( !(isdigit(c)) && c != '+' &&  c != '-'){

    for( ; ((c = getch()) != EOF) && c != '\n'&& c != ' ' && c != '\t'; operp++ ){

      *operp = c;
      
    }

    // ungetch(c);
    
    *operp = '\0';

    if (vari_search(s)){
      ungetch(c); 
      return NUMBER;
    }

    /*s[] can now be compared with a command list; no match found is CORRUPTIION */
    

    command_value = locate_command(s);  

    if(command_value == MODULUS || command_value == DIVIDE || command_value == SINE ||
	command_value == EXPONENT || command_value == POWER || command_value == MULTIPLY){
      
      ungetch(c);

    }

    return command_value;
    
  }
   
  /* if the input is +dgfdf, or -fgdfgd, or "+  ", or "- ", for example.*/ 
  else if( (c == '+' || c == '-') && (notsignednum = !(isdigit(cdeux = getch()))) ){
    
    /* the pure case - or +; a command*/
    if (cdeux == ' ' || cdeux == '\t'|| cdeux == '\n' || cdeux == EOF){
      
      ungetch(cdeux);

      return c;
      
    }

    /*the corrupted cases*/
    else {

      for (*operp++ = cdeux; (c =getch()) != EOF && c != '\n' && c != '\t' && c != ' '; operp++ ){
	
	*operp = c;
	
      }
      
      if (c == EOF){
	ungetch(c);
      }
      
      *operp ='\0';

      return CORRUPTION;
      
    }
   
  }

  /*get the number */
  else {

    if (notsignednum == false) {
      
      *operp++ = cdeux;
    }

    for(; isdigit(c = getch());  ){

      *operp++ = c;

    }

    if ( c == '.' ){

      *operp++ = '.';
      
      /*the fractional part*/
      if( isdigit(c = getch()) ){

	*operp++ =c;
      
	for ( ; isdigit(c = getch()); ){

	  *operp++ = c;
	
	}
	
      }
      
      /*"100. " not a number*/
      else {
	
	if (c == ' '|| c == '\n'|| c == '\t' || c == EOF){
	  if(c == EOF){
	    ungetch(c);
	  }
	  *operp ='\0';
	  
	  return CORRUPTION;
	  
	}
      } 
    }

    /*A Number is found */
    if(c == ' '|| c == '\n'|| c == '\t' || c == EOF){

        *operp = '\0';

	ungetch(c);

	return NUMBER;
	
      }
      
    /*A corrupted number*/
    else{

      for( *operp++ = c; (c = getch()) != EOF && c != ' ' &&  c != '\n' && c != '\t';  ){

	*operp++ = c;
	
      }
      if (c == EOF){
	ungetch(c);
      }
      
      *operp = '\0';
      
      return CORRUPTION;
      
    } 
     
  }
}
/*******************************************************************************************************/
