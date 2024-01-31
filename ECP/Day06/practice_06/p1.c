#include<stdio.h>

int main(void)
{

int num = 100;
int *ptr=&num;

printf("value of num = %d\n",num);
printf("value of num using ptr = %d\n",*ptr);

printf("&num = %u\n",&num);
printf("ptr = %u\n",ptr);

*ptr = 90;
printf("value of num = %d\n",num);

return 0;
}
