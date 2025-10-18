#include <stdio.h>

int main()
{
    int num1,num2;

    do {
        printf("Enter First Number : ");
        scanf("%d", &num1);
        printf("Enter Second Number : ");
        scanf("%d", &num2);

        printf("The Result Is : %d \n", num1 + num2);

    }
    while (1);
    
    return 0;
}