#include <stdio.h>

void fn(int *x);
int main()
{
    int x = 20;
    fn(&x);
    printf("x = %d\n", x);

    return 0;
}
void fn(int *x)
{
    *x = 10;
}