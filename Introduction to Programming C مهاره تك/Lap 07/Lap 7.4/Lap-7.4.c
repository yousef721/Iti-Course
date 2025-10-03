#include <stdio.h>

int main()
{
    int arr[10],sum = 0;
    int *arrPtr = &arr[0];

    for (int i = 0; i < 10; i++)
    {
        printf("Enter Number %d : ", i + 1);
        scanf("%d", (arrPtr + i));

        sum += (*arrPtr + i);
    }
    printf("The summation = %d",sum);

    
    return 0;
}