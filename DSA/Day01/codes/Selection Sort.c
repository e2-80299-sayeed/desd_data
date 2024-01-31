// Selection Sort
#include<stdio.h>
#define SIZE 6
#define SWAP(a,b){int t=a;a=b;b=t;}
void selection_sort(int arr[]);
void display(int arr[]);
int main()
{
    int arr[SIZE] = {30,20,60,50,10,40};
    printf("\n Before Sort \n");
    display(arr);
    selection_sort(arr);
    printf("After Sort \n");
    display(arr);
    return 0;
}

void selection_sort(int arr[])
{
    for(int sel_pos = 0;sel_pos < SIZE-1; sel_pos++)
    {
        for(int pos = sel_pos+1; pos < SIZE; pos++)
        {
            if(arr[sel_pos] > arr[pos])
            {
                // swap
                SWAP(arr[sel_pos],arr[pos]);
                /*
                    int t = arr[sel_pos];
                    arr[sel_pos] = arr[pos];
                    arr[pos] = t;  
                */
            }
        }
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