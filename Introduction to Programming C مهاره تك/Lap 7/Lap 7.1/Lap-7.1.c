#include <stdio.h>

int main()
{
    int x = 10;
    printf("x = %d\n", x);
    int *ptr;
    printf("Pointer = %d\n", ptr);
    ptr = &x;
    printf("Pointer Of x = %d\n", ptr);
    printf("Value Of x From Pointer = %d\n", *ptr);
    *ptr = 20;
    printf("After Change Value Of x From Pointer : x = %d\n", x);

    return 0;
}