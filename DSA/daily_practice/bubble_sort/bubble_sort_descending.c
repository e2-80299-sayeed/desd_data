#include<stdio.h>
#define SIZE 6
#define SWAP(a,b) {int t = a; a = b; b = t;}

void bubble_sort(int arr[SIZE]);
void efficient_bubble_sort(int arr[SIZE]);
void display(int arr[SIZE]);

int main()
{
    int arr[SIZE] = {30, 20, 60, 50, 10, 40};

    printf("Before sort : \n");
    display(arr);

    bubble_sort(arr);
    
    printf("After sort : \n");
    display(arr);

    efficient_bubble_sort(arr);
    display(arr);
    return 0;

}

void bubble_sort(int arr[SIZE])
{
    int pos;
    int iterations = 0, comparisons = 0;
    for(int i = 0 ; i < SIZE -1 ; i++)
    {
        iterations++;
        for(pos = 0; pos < SIZE-1-i; pos++)
        {
            comparisons++;
            if(arr[pos] < arr[pos+1])
                {
                    SWAP(arr[pos],arr[pos+1]);

                }
        }
    }
    printf("Iterations = %d Comparisons = %d\n",iterations,comparisons);
}

void efficient_bubble_sort(int arr[SIZE])
{
    int pos, flag;
    int iterations = 0, comparisons = 0;
    for(int i = 0; i < SIZE -1; i++)
        {
            iterations++;
            flag = 0;
            for(pos = 0; pos < SIZE-1-i; pos++)
                {
                    comparisons++;
                    if(arr[pos] < arr[pos+1])
                        {
                            SWAP(arr[pos],arr[pos+1]);
                            flag = 1;
                        }
                }
                    if(flag == 0)
                        break;
        }
            printf("\n Iterations = %d comparisons = %d\n",iterations,comparisons);
}


void display(int arr[SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\n");
}