#include<stdio.h>

int main()
{
    bool b=true; //false
    printf("\n bool b=%d  size of b=%d", b,sizeof(b));

    wchar_t wch='A';
    printf("\n wchar_t wch=%c  size of wch=%d", wch,sizeof(wch));
    return 0;
}