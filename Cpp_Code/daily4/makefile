# Dustin Daily
# CSIS 352 - Assign #4
# Makefile - prog4


CC = g++ 


OBJECTS = main.o

CFLAGS = 

LFLAGS =

EXE = prog4


$(EXE):		$(OBJECTS) 
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:		main.cpp linkedQueue.h 
		$(CC) $(CFLAGS) -c main.cpp 
   

clean:
		rm -rf $(EXE) $(OBJECTS) 
