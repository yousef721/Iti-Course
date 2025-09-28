#include <stdio.h>

int main()
{
    int num;
    int i = 1;
    printf("Enter The Number To Display Its Multiplication Table : ");
    scanf("%d", &num);

    while (i <= 10)
    {
       printf("%d x %d = %d \n", num, i, num * i);
       i++;
    }
    
    return 0;
}