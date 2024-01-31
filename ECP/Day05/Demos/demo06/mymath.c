
int add(int num1, int  num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int mul(int num1, int num2)
{
	return num1 * num2;
}

int div(int num1, int num2)
{
	return num1 / num2;
}

int factorial(int num)
{
	int fact = 1;
	for(int i = 1 ; i <= num ; i++)
		fact *= i;
	return fact;
}

int _power(int base, int index)
{
	int p = 1;
	for(int i = 0 ; i < index ; i++)
		p *= base;
	return p;
}





