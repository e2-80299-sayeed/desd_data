#include <stdio.h>

int main(void)
{
    int n, num;

    printf("Enter Number: ");
    scanf("%d", &num);
    for (n = 31; n >= 0; n--)
    {
        num = (num & ~(1 << 31)); //536870911
        // printf("num %d\n",num);
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