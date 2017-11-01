all: rpn.o stack.o main.c
	gcc -Wall -o rpn_calc main.c rpn.o stack.o

rpn.o: rpn.h rpn.c
	gcc -Wall -c rpn.c

stack.o: stack.h stack.c
	gcc -Wall -c stack.c

clean:
	rm -f *.o
