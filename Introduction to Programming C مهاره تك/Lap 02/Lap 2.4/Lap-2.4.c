#include <stdio.h>
#include <stdbool.h>
int main()
{
    printf("Size Of Integer: %lu \n", sizeof(int));
    printf("Size Of Float: %lu \n", sizeof(float));
    printf("Size Of Double: %lu \n", sizeof(double));
    printf("Size Of Character: %lu \n", sizeof(char));
    printf("Size Of Boolean: %lu \n", sizeof(bool));
    return 0;
}