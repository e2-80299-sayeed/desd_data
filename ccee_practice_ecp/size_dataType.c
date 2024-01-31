#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("Size and limits of data types on this system:\n");

    printf("char:   size = %zu bytes, range = %d to %d\n",
          sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("int:    size = %zu bytes, range = %d to %d\n",
          sizeof(int), INT_MIN, INT_MAX);
    printf("short:  size = %zu bytes, range = %d to %d\n",
          sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("long:   size = %zu bytes, range = %ld to %ld\n",
          sizeof(long), LONG_MIN, LONG_MAX);
    printf("float:  size = %zu bytes, precision = ~%d decimal digits\n",
          sizeof(float), FLT_DIG);
    printf("double: size = %zu bytes, precision = ~%d decimal digits\n",
          sizeof(double), DBL_DIG);

    return 0;
}

