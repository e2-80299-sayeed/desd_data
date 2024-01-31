# Make variables
CC=gcc

# Rule0 : to create main.out
main.out: main.o number.o power.o fact.o
	$(CC) -o main.out main.o number.o power.o fact.o

# Rule1 : to create main.o
main.o: main.c
	$(CC) -c main.c

# Rule2 : to create number.o
number.o: number.c
	$(CC) -c number.c

# Rule3 : to create power.o
power.o: power.c
	$(CC) -c power.c

# Rule4 : to create fact.o
fact.o: fact.c
	$(CC) -c fact.c

# Rule5 : to run application / program
run:
	./main.out

# Rule6 : to delete .o and .out file
clean:
	rm *.o main.out

.phony: run clean





