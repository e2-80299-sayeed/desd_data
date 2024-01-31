
TARGET=demo12

SRC=$(TARGET).c
OBJ=$(SRC:.c=.o)

CC=gcc

CFLAGS=
LDFLAGS=

# Rule 1 - Linking
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJ)

# Rule 2 - Compiling
$(OBJ):	$(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

# Rule 3 - Running
run:
	./$(TARGET)

# Rule 4 - Cleaning
clean:
	rm *.o $(TARGET)

.phony: run clean










