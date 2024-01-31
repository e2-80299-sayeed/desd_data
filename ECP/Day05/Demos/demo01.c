#include<stdio.h>


// typedef <existing name> <nick name>;
typedef unsigned int uint_t

unsigned int var1;
uint_t var2;

// type declaration
enum color{
	BLACK=4, WHITE, GREY=-4, BLUE, GREEN, RED, YELLOW, PINK
};

typedef enum color clr_t;

// size_t

typedef enum boolean{
	FALSE, TRUE
}bool_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;


/*
enum op1{
	ADD, SUB
};

enum op2{
	MUL, DIV
};


switch(){
	case ADD:

	case MUL:

}
*/

int main(void)
{
	//<datatype> <variable name>;
	enum color c1 = 10, c2 = BLUE, c3;

	printf("sizeof(enum color) : %ld\n", sizeof(enum color));
	printf("sizeof(c1) : %ld\n", sizeof(c1));			// 4 bytes

	printf("c1 = %d, c2 = %d\n", c1, c2);

	c3 = c1 + c2;
	printf("c3 = %d\n", c3);

	printf("BLACK = %d\n", BLACK);
	printf("BLUE = %d\n", BLUE);
	printf("RED = %d\n", RED);
	printf("PINK = %d\n", PINK);


	return 0;
}































