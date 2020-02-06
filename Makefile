CC = gcc
LIBS = -lm

all: main.o
	$(CC) -o line main.o $(LIBS)

main.o: main.c
	$(CC) -c main.c $(LIBS)

run:
	./line
