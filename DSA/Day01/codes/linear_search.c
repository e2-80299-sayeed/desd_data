#include<stdio.h>
#define SIZE 9
int linear_search(int arr[],int key);
int main()
{
    int arr[SIZE] = {33,55,88,77,44,11,66,22,99};
    int key;
    // step 1 : get the key from the user
    printf("Enter the key to search :");
    scanf("%d",&key);
    int index = linear_search(arr,key);

    if(index != -1)
        printf("Key is found at index %d\n",index);
    else
        printf("Key not Found !");
        
    return 0;
}

int linear_search(int arr[],int key)
{
    // step 2 : start the traversal from index 0
    for(int i = 0; i<SIZE; i++)
    {
        // step 3 : compare the key with each element
        if(key == arr[i])
            return i; // if matching, return the index
    }
    return -1; // return false in case of key not found
}