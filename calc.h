/********************************************************************************************/
/*getch() & ungetch()*/
/********************************************************************************************/
#include<stdbool.h> 
int getch(void);
void ungetch(int);
void ungets(char *s);

/********************************************************************************************/

/********************************************************************************************/
/*push() & pop()*/
/********************************************************************************************/
void push(double f);
double pop(void);
void clrstak(void);
void prtopstack(void);
void swapsanspop(void);
/********************************************************************************************/

/********************************************************************************************/
int getop(char s[]);
char locate_command(char *s);

void vari_handler_assign(char *vari_name, char *vari_num);
void vari_handler_clr(char *vari_name);
/********************************************************************************************/
void vari_handler_assign_ans(char *ans_str);
void vari_handler_clr_ans(void);
bool vari_search(char *s);
/********************************************************************************************/

 /********************************************************************************************/
void get_variable( char* sgetop_num, char* sgetop_name);
/********************************************************************************************/
