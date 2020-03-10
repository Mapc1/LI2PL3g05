all: main

main: main.o dados.o
	gcc -g -o main main.o dados.o interface.o

main.o: main.c dados.h 
	gcc -g -o main.o main.c -c -W -Wall -ansi -pedantic

dados.o: dados.c dados.h
	gcc -g -o dados.o dados.c -c -W -Wall -ansi -pedantic 

interface.o: interface.c interface.h
	gcc -g -o interface.o interface.c -c -W -Wall -ansi -pedantic

clean: 
	del /Q /S *.o *~ main