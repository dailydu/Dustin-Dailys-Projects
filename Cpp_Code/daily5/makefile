# Dustin Daily
# CSIS 352 - Assign #5
# Makefile - prog5


CC = g++ 


OBJECTS = main.o

CFLAGS = 

LFLAGS =

EXE = prog5


$(EXE):		$(OBJECTS) 
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:		main.cpp graph.h 
		$(CC) $(CFLAGS) -c main.cpp 
   

clean:
		rm -rf $(EXE) $(OBJECTS) 
