
TARGET=main
SRCS=$(TARGET).c fun.c
OBJS=$(SRCS:.c=.o)

CC=gcc
CFLAGS= 
LDFLAGS=

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

# % - stem
# Automatic variables
# $@ - automatically resolves to target of the rule
# $^ - automatically resolves to list of dependancies
# $< - automatically resolves to first/corresponding dependancy

# this rule will be executed for all .o/.c file
%.o: %.c
	$(CC) $(CFLAGS) -c $<

run:
	./$(TARGET)

clean:
	rm *.o $(TARGET)


