#include<stdio.h>
#define SIZE 9
int binary_search(int arr[],int key);
int rec_binary_search(int arr[],int key,int left,int right);
int main()
{
    int arr[SIZE] = {11,22,33,44,55,66,77,88,99};
    int key;
    // step 1: get the key from the user
    printf("Enter the key to search :");
    scanf("%d",&key); // 77
    int index = binary_search(arr,key);
    if(index != -1)
        printf("Key is found at index %d\n",index);
    else
        printf("Key not Found !\n");
        
    int result = rec_binary_search(arr,key,0,SIZE-1);
    if(result != -1)
        printf("Recursive : Key is found at index %d\n",result);
    else
        printf("Recursive : Key not Found !");

    return 0;
}

int binary_search(int arr[],int key) // 77
{
    // find left, right, mid.
    int left = 0, right = SIZE-1,mid;

while(left <= right) // 0 <= 8 -->  5 <= 8
{
    mid = (left+right) / 2; // 4  --> 6
    // step 3: compare the key with the mid element
    if(key == arr[mid]) // 77 == 55 
        return mid;
    // step 4 : check if the key is smaller or greater to mid element
    if(key < arr[mid]) // consider left subarray
    {
        right = mid -1;
    }
    else // consider right sub array
        left = mid + 1; // left = 5
}
    return -1;

}

                    // (arr, 77,0,8)
int rec_binary_search(int arr[],int key,int left,int right)
{
    int result;
    if(left > right)
        return -1;

    int mid = (left + right) /2;

    if(key == arr[mid])
        return mid;
    else if(key < arr[mid]) // consider left sub array
        result = rec_binary_search(arr,key,left,mid-1);
    else // consider right sub array
        result = rec_binary_search(arr,key,mid+1,right);
    return result;

}
