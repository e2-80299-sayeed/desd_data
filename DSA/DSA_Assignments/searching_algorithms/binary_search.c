#include<stdio.h>
#define SIZE 9
int binary_search(int arr[],int key);
int rec_binary_search(int arr[],int key, int left, int right);
int comparisons;
//for Binary search we need sorted array only
int main ()
{
    int arr[SIZE] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int key;
    printf("Enter the key to search : ");
    scanf("%d",&key);

    int index = binary_search(arr, key);
    if(index != -1)
        printf("Key found at index = %d\n",index);
    else 
        printf("Key not found !!");
    printf("comparisons = %d\n",comparisons);

    int result = rec_binary_search(arr,key,0,SIZE - 1);
    if(result != -1)
        printf("Recusive: Key found at index = %d",result);
    else    
        printf("Recusive: Key not found !!");
/*
    printf("Enter array elements : ");

    for(int i = 0; i < SIZE; i ++)
        scanf("%d",&(arr[i]));      
    
     for(int i = 0; i < SIZE; i ++)
        printf("%4d",arr[i]);

 
       printf("\n");
*/
    return 0;
}

int binary_search(int arr[],int key)
{
    int left = 0, right = SIZE-1, mid;
    while(left <= right)
    {
        comparisons++;
        mid = (left + right)/2;
        if(key == arr[mid])
            return mid;
        if(key < arr[mid]) // left sub- array
            right = mid - 1;
        else                // right sub array
            left = mid + 1;   
    }
    return -1;
}

int rec_binary_search(int arr[],int key, int left, int right)
{
    int result;
    if(left > right)
        return -1;
    int mid = (left + right)/2;

    if (key == arr[mid])
        return mid;
    else if(key < arr[mid])
        result = rec_binary_search(arr, key, left, mid - 1);
    else
        result = rec_binary_search(arr, key, mid + 1, right);

    return result;
}