
TARGET=main
SRCS=$(TARGET).c bst.c add_node.c traversal.c stack.c queue.c delete_node.c
OBJS=$(SRCS:.c=.o)

CC=gcc
CFLAGS= 
LDFLAGS=

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run:
	@./$(TARGET)

clean:
	del *.o $(TARGET)


