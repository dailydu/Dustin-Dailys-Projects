# Dustin Daily
# CSIS 352 - Assign #2
# Makefile - prog2


CC = g++ 


OBJECTS = main.o date.o

CFLAGS = 

LFLAGS =

EXE = prog2


$(EXE):		$(OBJECTS) 
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:		main.cpp date.h
		$(CC) $(CFLAGS) -c main.cpp 

date.o:	date.cpp date.h
		$(CC) $(CFLAGS) -c date.cpp
   

clean:
		rm -rf $(EXE) $(OBJECTS) 
