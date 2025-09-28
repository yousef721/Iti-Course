#include <stdio.h>
int factorial(int n);

int main()
{
    int num;
    printf("Enter Number Factorial : ");
    scanf("%d", &num);
    printf("%d! = %d", num, factorial(num));
    return 0;
}
int factorial(int n)
{
    if (n <= 0)  
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}