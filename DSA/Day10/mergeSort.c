#include<stdio.h>
#include<stdlib.h>

#define SIZE 9

void print_array(int arr[], int size);
void merge_sort(int arr[], int left, int right);

int main(void)
{
    int arr[SIZE] = {6, 1, 9, 3, 7, 2, 8, 4, 5};

    printf("Before sort : ");
    print_array(arr, SIZE);
    printf("\n");

    merge_sort(arr, 0, SIZE-1);

    printf("After sort : ");
    print_array(arr, SIZE);

    return 0;
}

void print_array(int arr[], int size)
{
    for(int i = 0 ; i < size ; i++)
        printf("%-4d", arr[i]);
}

void merge_sort(int arr[], int left, int right)
{
    //0. stop when yoou will get single element partition
    if(left == right)
        return;
    //1. divide array into two parts
    int mid = (left + right) / 2;
    //2. sort both partitions individually
    //2.1 sort left partition by calling same function
    merge_sort(arr, left, mid);
    //2.2 sort right partition by calling same function
    merge_sort(arr, mid + 1, right);
    //3. merge both sorted partitions into temp array in sorted order
    int size = right - left + 1;
    int *temp = (int *)malloc(sizeof(int) * size);
    int i = left, j = mid + 1, k = 0;
    // compare ith element with jth element
    while(i <= mid && j <= right)
    {
        /*if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }*/
        temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    // if right partition is finished, add all remaining elements of left partition into temp array
    while(i <= mid)
    {
        /*temp[k] = arr[i];
        k++;
        i++;*/
        temp[k++] = arr[i++];
    }
    // if left partition is finished, add all remaining elements of right partition into temp array
    while (j <= right)
    {
        /*temp[k] = arr[j];
        k++;
        j++;*/
        temp[k++] = arr[j++];
    }
    //4. over write temp array into original array
    for(int i = 0 ; i < size ; i++)
        arr[left + i] = temp[i];
    free(temp);
}