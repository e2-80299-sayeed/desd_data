#include<stdio.h>

void print_binary(void *ptr, int size)
{
	ptr = (unsigned char *)ptr + size - 1;
		for(int i = 0 ; i < size ; i++)
		{
				unsigned char var = *(unsigned char *)ptr;
				unsigned char mask = 0X80;
				while(mask)
				{
						if(var & mask)
								printf("1");
						else
								printf("0");

						mask = mask >> 1;	
				}
				printf(" ");
				(unsigned char *)ptr--;
		}
		printf("\n");
}

int main(void)
{
		unsigned char var = 10;

		print_binary(&var, sizeof(var));

	
		short sh = 10;
		//	0000 0000 0000 1010
		print_binary(&sh, sizeof(sh));
		return 0;
}































