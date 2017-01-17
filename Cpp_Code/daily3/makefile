# Dustin Daily
# CSIS 352 - Assign #3
# Makefile - prog3


CC = g++ 


OBJECTS = main.o

CFLAGS = 

LFLAGS =

EXE = prog3


$(EXE):		$(OBJECTS) 
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:		main.cpp array.h 
		$(CC) $(CFLAGS) -c main.cpp 
   

clean:
		rm -rf $(EXE) $(OBJECTS) 
