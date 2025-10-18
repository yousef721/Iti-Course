#include <stdio.h>

int main()
{
    int num1,num2;
    printf("Please Enter Number a : ");
    scanf("%d", &num1);
    printf("Please Enter Number b : ");
    scanf("%d", &num2);
    printf("a + b : %d \n", num1 + num2);
    printf("a - b : %d \n", num1 - num2);
    printf("a & b : %d \n", num1 & num2);
    printf("a | b : %d \n", num1 | num2);
    printf("a ^ b : %d \n", num1 ^ num2);

    return 0;
}