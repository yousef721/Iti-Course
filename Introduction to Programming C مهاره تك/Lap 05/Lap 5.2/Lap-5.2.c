#include <stdio.h>
void swap();
int x = 7,y = 9;

int main()
{

    printf("x Before Swap : %d \n", x);
    printf("y Before Swap : %d \n", y);


    printf("----------------- \n");

    swap();

    printf("x After Swap : %d \n", x);
    printf("y After Swap : %d \n", y);

    return 0;
}
void swap()
{
    int temp = x;
    x = y;
    y = temp;
}