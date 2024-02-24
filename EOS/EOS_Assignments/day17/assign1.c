// 1. Create a thread to sort given array of 10 integers using selection sort. Main thread should print the result after sorting is completed.
// Hint: Pass array to thread function (via arg4 of pthread_create()).

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

#define SWAP(a,b) { int t = a; a=b; b=t;}
#define SIZE 10
void display_arr(int arr[]);

void* sel_sort_arr( void*param)
{
    int *arr;
    arr = (int*)param;
    int sel_pos ;
    for( sel_pos = 0; sel_pos < SIZE-1; sel_pos++)
        {
            for(int pos = sel_pos + 1; pos < SIZE; pos++)
            {
                if(arr[sel_pos] > arr[pos])
                {
                    SWAP(arr[sel_pos],arr[pos]);  
                }
            

            }
        }
    

    return NULL;
}

int main()
{
    int ret ,arr[SIZE] = { 22, 44, 99, 11, 33, 55, 88, 66, 77, 28};
    pthread_t th;
    
    printf("Array before sort :\n");
    display_arr(arr);
    ret = pthread_create(&th, NULL,sel_sort_arr, arr);
    if(ret < 0)
    {
        perror("pthread_create() failed!\n");
        _exit(1);
    }

    printf("waiting for thread to complete....\n");
    ret = pthread_join(th,NULL);
    if(ret != 0)
    {
        perror("pthread_join() failed!!\n");
        _exit(2);
    }

    printf("Array after sort : \n");
    display_arr(arr);
    
    return 0;
}

void display_arr(int arr[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%4d", arr[i]);
    }
    printf("\n");

}
