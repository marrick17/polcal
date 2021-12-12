#include <stdbool.h>
/*floating pt to alpha*/
void ftoa(double f, char *s);

/*integer to alpha*/
void itoa(int n, char *alpha);

/*nreverse(): reverse the character strings, terminate it with '\0' */
void nreverse(char *s);

/*comparestr(): return true if found; if no false*/
bool comparestr(char *base, char *str);

/*nstrcpy(): string compare*/
void nstrcpy(char *dest, char *orig);

/*ngetline(): get line from terminal*/
int ngetline(char *line, int max);

