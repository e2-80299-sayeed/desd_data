

int factorial(int num)
{
	// stop when num = 1
	if(num == 1)
		return 1;
	// num * (num - 1)!
	return num * factorial(num - 1);
}
