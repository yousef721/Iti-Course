#include <stdio.h>

int main()
{
    // Static Code [Only 3 Number]
    int num1,num2,num3;
    printf("Enter Number 1 : ");
    scanf("%d", &num1);
    printf("Enter Number 2 : ");
    scanf("%d", &num2);
    printf("Enter Number 3 : ");
    scanf("%d", &num3);

    if (num1 >= num2 && num1 >= num3)
    {
        printf("Maximum Number Is %d \n", num1);
    } else if (num2 >= num3)
    {
        printf("Maximum Number Is %d \n", num2);
    } else 
    {
        printf("Maximum Number Is %d \n", num3);
    }

    /*-----------------------------------------------------------*/

    // Dynamic Code [Count Of Number Selected By User]
    int count;
    printf("Please Enter Count Of Number : ");
    scanf("%d", &count);

    int arr[count];

    for (int i = 0; i < count; i++)
    {
        printf("Please Enter Number %d : ", i +1);
        scanf("%d", &arr[i]);
    }
    // First element
    int max = arr[0];

    for (int i = 1; i < count; i++)
    {
        if (arr[i] > max) // Compare First element with Second Then Third with max
        {
            max = arr[i];
        }
    }
    printf("Maximum Number Is %d", max);

    return 0;
}