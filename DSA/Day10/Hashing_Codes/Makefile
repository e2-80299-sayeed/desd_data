
TARGET=demo02

CSRCS= $(TARGET).c list.c 
COBJS= $(CSRCS:.c=.o)

CC= gcc

CFLAGS= -Wall
LDFLAGS=

$(TARGET): $(COBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(COBJS):%.o: %.c
	$(CC) $(CFLAGS) -c $<

run:
	./$(TARGET)

clean:
	rm *.o $(TARGET)

.phony:	run clean
















