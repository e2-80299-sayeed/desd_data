// bubble Sort
#include<stdio.h>
#define SIZE 6
#define SWAP(a,b){int t=a;a=b;b=t;}

void bubble_sort(int arr[]);
void display(int arr[]);
void efficient_bubble_sort(int arr[]);

int main()
{
    int arr[SIZE] = {30,20,60,50,10,40};
    printf("\n Before Sort :\n");
    display(arr);
    bubble_sort(arr);
    printf("After Sort :\n");
    display(arr);
    efficient_bubble_sort(arr);
    display(arr);
    return 0;
}

void bubble_sort(int arr[])
{
    for(int it = 0;it < SIZE-1; it++) // 0 to 4
    {
        for(int pos=0;pos < SIZE-1-it; pos++)
        {
            if(arr[pos] > arr[pos+1])
            {
                // swap
                SWAP(arr[pos],arr[pos+1]);
            }
        }
    }
}


void efficient_bubble_sort(int arr[])
{
    int flag ;
    for(int it = 0;it < SIZE-1; it++) // 0 to 4
    {
        flag = 1;
        for(int pos=0;pos < SIZE-1-it; pos++)
        {
            if(arr[pos] > arr[pos+1])
            {
                // swap
                SWAP(arr[pos],arr[pos+1]);
                flag = 0;
            }
        }
        if(flag == 1)
            break;
    }
}

void display(int arr[])
{
    for(int i =0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\n");
}