#include<stdio.h>

typedef enum color {
	BLACK,BLUE=3,WHITE,YELLOW=-2,RED,PINK,GREY
}clr_t;
int main(void)
{

clr_t c1=10, c2=BLUE,c3;
printf("sizeof(enum color): %ld\n",sizeof(enum color));

printf("sizeof(c1): %ld\n",sizeof(c1));

printf("c1=%d, c2=%d\n",c1,c2);

c3=c1+c2;
printf("c3= %d\n",c3);

printf("BLACK= %d\n",BLACK);
printf("BLUE= %d\n",BLUE);
printf("WHITE= %d\n",WHITE);
printf("YELLOW= %d\n",YELLOW);
printf("RED= %d\n",RED);






return 0;
}
