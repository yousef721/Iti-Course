#include <stdio.h>
int getMax(int a, int b);

int main()
{
    int a,b;
    printf("Please Enter Value : ");
    scanf("%d", &a);
    printf("Please Enter Value : ");
    scanf("%d", &b);

    int max = getMax(a,b);

    printf("The Maximum Value Is : %d", max);

    return 0;
}
int getMax(int a, int b)
{
    if (a > b)
    {
        return a;
    } else
    {
        return b;
    }
}