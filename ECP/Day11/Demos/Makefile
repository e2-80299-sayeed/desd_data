
TARGET=demo10

SRC=$(TARGET).c
OBJ=$(SRC:.c=.o)

CC=gcc
CFLAGS=
LDFLAGS=

$(TARGET).out: $(OBJ)
	$(CC) $(LDFLAGS) -o $(TARGET).out $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c $(SRC)

run:
	./$(TARGET).out

clean:
	rm *.o *.out






