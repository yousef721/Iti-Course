#include <stdio.h>

int main()
{
    int countNum;
    printf("Enter Number Of Elements : ");
    scanf("%d", &countNum);
    int arr[countNum];
    for (int i = 0; i < countNum; i++)
    {
        printf("Please Enter Number %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("The Value In Reversed Order \n");

    for (int i = countNum - 1; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
    }    
    return 0;
}