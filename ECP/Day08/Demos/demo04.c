#include<stdio.h>

typedef enum boolean{
	FALSE, TRUE
}bool_t;


void print_array(short [], int);
short find_min(short [], int);
short find_max(short [], int);
bool_t search_value(short [], int, short);
void selection_sort(short [], int);
int count_duplicate_values(short [], int);


int main(void)
{
	const int size = 6;
	short arr[6] = {40, 30, 60, 50, 10, 20};

	print_array(arr, size);
	printf("Minimum value = %hd\n", find_min(arr, size));
	printf("Maximum value = %hd\n", find_max(arr, size));

	// size = 7;		// error
	short key = 55;
	bool_t ret = search_value(arr, size, key);
	if(ret == TRUE)
		printf("%d Key is found\n", key);
	else
		printf("%d Key is not found\n", key);

	selection_sort(arr, size);
	print_array(arr, size);

	return 0;
}
				//short *arr
void print_array(short arr[], int size)
{
	printf("Array :  ");
	for(int i = 0 ; i < size ; i++)
		printf("%-4d", arr[i]);
	printf("\n");
}

short find_min(short arr[], int size)
{
	short min = arr[0];
	for(int i = 1 ; i < size ; i++)
	{
		if(arr[i] < min)
			min = arr[i];
	}
	return min;
}

short find_max(short arr[], int size)
{
	short max = arr[0];
	for(int i = 1 ; i < size ; i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

bool_t search_value(short arr[], int size, short key)
{
	for(int i = 0 ; i < size ; i++)
	{
		if(arr[i] == key)
			return TRUE;
	}
	return FALSE;
}

void selection_sort(short arr[], int size)
{
	for(int i = 0 ; i < size - 1;  i++)
	{
		for(int j = i + 1; j < size ; j++)
		{
			if(arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int count_duplicate_values(short arr[], int size)
{
	// TODO
}

























