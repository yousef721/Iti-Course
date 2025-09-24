/*
In GCC (GNU Compiler Collection), the concept of false value usually relates to C boolean logic.
Here’s the breakdown:

1. In C (before C99)

C did not have a built-in boolean type.

Any integer value can act as a condition:

0 → false

1 → true 
*/
#include <stdio.h>

int main()
{
    int x = 1;
    int y = 0;
    printf("False Value In GCC: %d \n", x && y); // [0] False
    printf("True Value In GCC: %d", x || y); // [1] True
    return 0;
}