#include<stdio.h>
#define SIZE 6
#define SWAP(a,b)  {int t = a; a = b; b = t;}

void selection_sort(int arr[SIZE]);
void display(int arr[SIZE]);

int main()
{
    int arr[SIZE] = {30, 20, 60, 50, 10, 40};
    printf("Before sort :\n");

    display(arr);

    selection_sort(arr);
    printf("After sort :\n");
    display(arr);

    return 0;
}

void selection_sort(int arr[SIZE])
{
    int sel_pos, pos;
    int iterations = 0, comparisons = 0;

    for(sel_pos = 0; sel_pos < SIZE-1; sel_pos ++)
    {
        iterations++;
        for(pos = sel_pos+1; pos < SIZE; pos++)
        {
            comparisons++;
            if(arr[sel_pos] < arr[pos])
            {
                SWAP(arr[sel_pos], arr[pos]);
            }
        }
    }
    printf("\n Iterations = %d, comparsions = %d\n",iterations,comparisons);
}


void display(int arr[SIZE])
{
    for(int i = 0; i < SIZE; i++)
        printf("%4d",arr[i]);

    printf("\n");
}