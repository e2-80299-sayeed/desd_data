#include<stdio.h>

#define SIZE 9

void print_array(int arr[], int size);
void quick_sort(int arr[], int left, int right);

int main(void)
{
    int arr[SIZE] = {66, 33, 99, 11, 77, 22, 55, 66, 88};

    printf("Before sort : ");
    print_array(arr, SIZE);
    printf("\n");

    quick_sort(arr, 0, SIZE-1);

    printf("After sort : ");
    print_array(arr, SIZE);

    return 0;
}

void print_array(int arr[], int size)
{
    for(int i = 0 ; i < size ; i++)
        printf("%-4d", arr[i]);
}

void quick_sort(int arr[], int left, int right)
{
    //0. stop if single element partition or invalid partition
    if(left >= right)
        return;
    //1. select one referance/axis/pivot element from array
    //int pivot = arr[left];       --> arr[left]
    //2. arrange all smaller elements than pivot on left side of pivot
    //3. arrange all greater elements than pivot on right side of pivot
    int i = left, j = right;
    while(i < j)
    {
        // find element greater than pivot from left side
        for( ; arr[i] <= arr[left] ; i++); 
        // find element less or equal than pivot from right side
        for( ; arr[j] > arr[left] ; j--);
        // if i and j are not crossed then swap ith and jth element
        if(i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } 
    }
    // if i and j are crossed then swap jth and pivot element
    int temp = arr[j];
    arr[j] = arr[left];
    arr[left] = temp;
    //4. sort left and right partition of pivot individually
    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}
