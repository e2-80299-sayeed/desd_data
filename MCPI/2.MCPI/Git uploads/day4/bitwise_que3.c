#include <stdio.h>

int main(void)
{
    int n, num,n1;

    printf("Enter Number: ");
    scanf("%d", &num);
    for (n = 15; n >= 0; n--)
    {
        num = (num ^(1 << 9) ^ (1<<8));   
        
        if (num & (1 << n))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    return 0;
}