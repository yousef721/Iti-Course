#include <stdio.h>

// declaration From Another File 
int maxValue(int n1,int n2,int n3,int n4);
int minValue(int n1,int n2,int n3,int n4);

int main()
{
    int num1,num2,num3,num4;
    printf("Enter Number 1 : ");
    scanf("%d", &num1);
    printf("Enter Number 2 : ");
    scanf("%d", &num2);
    printf("Enter Number 3 : ");
    scanf("%d", &num3);
    printf("Enter Number 4 : ");
    scanf("%d", &num4);

    printf("Maximum Value Is : %d \n", maxValue(num1,num2,num3,num4));
    printf("Minimum Value Is : %d \n", minValue(num1,num2,num3,num4));

    return 0;
}


/* 
Link Two Files To Generate One Executable File :
    1 ) Use This Command "clang Assignment-1.c min-max-value.c -o program"
    2 ) Then Run by This Command "./program"
*/