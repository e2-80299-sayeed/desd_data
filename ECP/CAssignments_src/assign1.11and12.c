#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(void)
{
	printf("Range of signed char:  %d\tto\t%d\n",CHAR_MIN,CHAR_MAX); 
	
	printf("Range of unsigned char:  %d\tto\t%d\n",0,UCHAR_MAX); 
	
	printf("Range of unsigned short:  %u\tto\t%u\n",0,USHRT_MAX); 
	
	printf("Range of signed short:  %d\tto\t%d\n",SHRT_MIN,SHRT_MAX); 
	
	printf("Range of signed int:  %d\tto\t%d\n",INT_MIN,INT_MAX); 
	
	printf("Range of unsigned int:  %u\tto\t%u\n",0,UINT_MAX); 
	
	printf("Range of signed long int:  %ld\tto\t%ld\n",LONG_MIN,LONG_MAX); 
	
	printf("Range of unsigned long int:  %lu\tto\t%lu\n",0,ULONG_MAX); 
	

	printf("Range of float:  %e\tto\t%e\n",FLT_MIN,FLT_MAX); 
	
	printf("Range of double:  %g\tto\t%g\n",DBL_MIN,DBL_MAX); 
	
	printf("Range of long double:  %Lf\tto\t%Lf\n",LDBL_MIN,LDBL_MAX); 
	
		

return 0;
}
