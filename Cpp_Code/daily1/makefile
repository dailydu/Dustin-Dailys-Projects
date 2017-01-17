# Your name here 
# CSIS 352 - Asmt #1
# Makefile - prog1


CC = g++ 


OBJECTS = main.o currency.o

CFLAGS = 

LFLAGS =

EXE = prog1


$(EXE):		$(OBJECTS) 
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:		main.cpp currency.h
		$(CC) $(CFLAGS) -c main.cpp 

currency.o:	currency.cpp currency.h
		$(CC) $(CFLAGS) -c currency.cpp
   

clean:
		rm -rf $(EXE) $(OBJECTS) 
