#include <stdio.h>

int main()
{
    int num;
    int factorial = 1;
    printf("Enter An Integer : ");
    scanf("%d", &num);

    while (num != 0)
    {
        factorial *= num;
        num--;
    }
    
    printf("Factorial : %d", factorial);

    return 0;
}