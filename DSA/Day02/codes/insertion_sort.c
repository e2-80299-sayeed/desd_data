#include<stdio.h>
#define SIZE 6

void display(int arr[]);
void insertion_sort(int arr[]);

int main()
{
    int arr[SIZE] = {55,44,22,66,11,33};
    printf(" Before Sort \n");
    display(arr);
    printf("After Sort \n");
    insertion_sort(arr);
    display(arr);

    return 0;
}

void insertion_sort(int arr[])
{
    int i,j,temp;
    for(i = 1;i < SIZE;i++)
    {
        temp = arr[i];
        for(j = i-1; j>=0 && arr[j] > temp; j--)
        {
            // shift arr[j] to j+1 position
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}

void display(int arr[])
{
    for(int i = 0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\n");
}