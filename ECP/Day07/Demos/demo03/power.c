
int my_power(int base, int index)
{
	// stop if index = 1, return base
	if(index == 1)
		return base;
	
	// base * base ^ index - 1
	return base * my_power(base, index - 1);
}
