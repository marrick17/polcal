###############################################################
#Polcal: Numerical calculator	Author: Marrick Mcfarlane
###############################################################
OBJS = main.o stack.o getop.o smal_lib.o getchartoinput.o \
	locate_command.o getvariable.o variable_handler.o

CFLAGS = -Wall -g 

polcal: $(OBJS)
	cc $(CFLAGS) -o polcal $(OBJS) -lm

main.o : main.c calc.h smal_lib.h command.h

stack.o : stack.c

getop.o : getop.c command.h calc.h

smal_lib.o : smal_lib.c

lsgetchartoinput.o : getchartoinput.c smal_lib.h

locate_command.o : locate_command.c command.h smal_lib.h

getvariable.o : getvariable.c smal_lib.h

variable_handler.o : variable_handler.c smal_lib.h

.PHONY : clean

clean :
	rm polcal $(OBJS)
