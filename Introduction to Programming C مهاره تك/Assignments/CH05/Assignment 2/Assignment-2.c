#include <stdio.h>
#include "calculator.h"  

int main()
{
    int num1, num2;
    char operation;
    printf("Enter Operation (+,-,*,/,%%,&,|,^,~,i,d): ");
    scanf(" %c", &operation);

    if (operation != 'i' && operation != 'd' && operation != '~') {
        printf("Enter Number 1 : ");
        scanf("%d", &num1);
        printf("Enter Number 2 : ");
        scanf("%d", &num2);
    } else {
        printf("Enter Number : ");
        scanf("%d", &num1);
    }

    switch (operation)
    {
    case '+':
        printf("%d + %d = %d", num1, num2, add(num1,num2));
        break;
    case '-':
        printf("%d - %d = %d", num1, num2, subtract(num1,num2));
        break;
    case '*':
        printf("%d * %d = %d", num1, num2, multiply(num1,num2));
        break;
    case '/':
        if (num2 == 0) {
            printf("Error: Division by zero is not allowed!\n");
        } else {
            printf("%d / %d = %.2f", num1, num2, divided(num1,num2));
        }
        break;
    case '&':
        printf("%d & %d = %d", num1, num2, bitwiseAnd(num1,num2));
        break;
    case '|':
        printf("%d | %d = %d", num1, num2, bitwiseOr(num1,num2));
        break;
    case '^':
        printf("%d ^ %d = %d", num1, num2, bitwiseXOr(num1,num2));
        break;
    case '%':
        if (num2 == 0) {
            printf("Error: Remainder with zero is not allowed!\n");
        } else {
            printf("%d %% %d = %d", num1, num2, remainderUserDefined(num1,num2));
        }
        break;
    case 'i':
        printf("%d++ = %d", num1, increment(num1));
        break;
    case 'd':
        printf("%d-- = %d", num1, decrement(num1));
        break;
    case '~':
        printf("~%d = %d", num1, bitwiseNot(num1));
        break;
    default:
        printf("Invalid operation!");
    }
    return 0;
}


/* 
Link Two Files To Generate One Executable File :
    1 ) Use This Command "clang Assignment-2.c calculator.c -o program"
    2 ) Then Run by This Command "./program"
*/