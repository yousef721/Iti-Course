#include <stdio.h>

int main()
{
    int num;
    printf("Please Enter A Number : ");
    scanf("%d", &num);
    if (num % 2 == 0)
    {
        printf("Number Is Even");
    } else 
    {
        printf("Number Is Odd");
    }
    return 0;
}