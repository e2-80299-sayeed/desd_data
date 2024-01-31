
TARGET=demo09
SRCS=$(TARGET).c
OBJS=$(SRCS:.c=.o)

CC=gcc
CFLAGS= 
LDFLAGS=

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $<

run:
	@./$(TARGET)

clean:
	rm *.o $(TARGET)


