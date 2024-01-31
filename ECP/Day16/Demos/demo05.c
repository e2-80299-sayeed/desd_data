#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(void *base, int nmemb, int size, int (*compar)(const void *, const void *));

int compare(const void *ptr1, const void *ptr2)
{
	return *(int *)ptr1 - *(int *)ptr2;
}

int compare1(const void *ptr1, const void *ptr2)
{
	return *(char *)ptr1 - *(char *)ptr2;
}
int main(void)
{
	//int arr[5] = {33, 11, 44, 55, 22};
	char arr[5] = {'c', 'a', 'd', 'b', 'e'};

	printf("Array : ");
	for(int i = 0 ; i < 5 ; i++)
		//printf("%-4d", arr[i]);
		printf("%-4c", arr[i]);
	printf("\n");

	//sort(arr, 5, sizeof(int), compare);
	sort(arr, 5, sizeof(char), compare1);

	printf("Array : ");
	for(int i = 0 ; i < 5 ; i++)
		//printf("%-4d", arr[i]);
		printf("%-4c", arr[i]);
	printf("\n");
	return 0;
}


void sort(void *base, int nmemb, int size, int (*compar)(const void *, const void *))
{
	for(int i = 0 ; i < nmemb - 1 ; i++)
	{
		for(int j = i + 1 ; j < nmemb ; j++)
		{
			void *pi = (char *)base + i * size;
			void *pj = (char *)base + j * size;
			if(compar(pi, pj) > 0)
			{
				void *temp = malloc(size);				
				memcpy(temp, pi, size);		//int temp = base[i];
				memcpy(pi, pj, size);			//base[i] = base[j];
				memcpy(pj, temp, size);		//base[j] = temp;
				free(temp);
			}
		}
	}

}






























