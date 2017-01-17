# Dustin Daily
# CSIS 352 - Assign #6
# Makefile - prog6


CC = g++ 


OBJECTS = main.o

CFLAGS = 

LFLAGS =

EXE = prog6


$(EXE):		$(OBJECTS) 
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:		main.cpp sortedlist.h 
		$(CC) $(CFLAGS) -c main.cpp 
   

clean:
		rm -rf $(EXE) $(OBJECTS) 
