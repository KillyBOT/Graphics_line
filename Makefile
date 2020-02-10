CC = gcc
LIBS = -lm

all: main.o line.o
	$(CC) -o line main.o line.o $(LIBS)

main.o: main.c line.h
	$(CC) -c main.c $(LIBS)

line.o: line.c line.h
	$(CC) -c line.c $(LIBS)

run:
	./line
