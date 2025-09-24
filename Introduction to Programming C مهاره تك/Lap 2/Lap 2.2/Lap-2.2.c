#include <stdio.h>

int main()
{
    int x = 7;
    int y = 4;
    printf("X & Y = %d\n", x & y); // 4
    printf("X | Y = %d\n", x | y); // 7
    printf("X ^ Y = %d\n", x ^ y); // 3
    printf("X >> Y = %d\n", x >> 1); // 3
    printf("X << Y = %d\n", y << 2); // 16
    return 0;
}
