#include <stdio.h>

int main() {
	// nested function definations are allowed in modern C standard.
	// they were not allowed in traditional C language.

	// the nested functions are local functions
	// these functions are accessible only inside the function in which it is defined
	int main() {
		printf("1. Hello, World!\n");
		return 0;
	}

	// calling the nested function
	main(); // since function has same name as of outer function, it will not cause recursion
			// this will call inner function only.
	printf("2. Hello, World!\n");
	return 0;
}

