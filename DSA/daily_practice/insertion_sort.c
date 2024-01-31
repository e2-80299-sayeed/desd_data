#include<stdio.h>
#define SIZE 6

void insertion_sort(int arr[]);
void display(int arr[]);

int main()
{
    int arr[SIZE] = {55, 44, 22, 66, 11, 33};

    printf("Before sort:\n");
    display(arr);

    insertion_sort(arr);
    printf("After sort: \n");
    display(arr);

    return 0;
}

void insertion_sort(int arr[])
{
    int i, j ,key;

    int iterations = 0, comparisons = 0;
    for(i = 1; i< SIZE; i++)
        {
            iterations++;
            key = arr[i];

            for( j = i-1; j >= 0 && arr[j] > key; j--)
                {
                    arr[j+1] = arr[j];
                    comparisons++;
                }
            arr[j+1] = key;
        }
    printf("Iterations = %d comparisons = %d\n",iterations,comparisons);
}

void display(int arr[])
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\n");
}