#include <stdio.h>

int main()
{
    // Static Code [Only 5 Number]
    int num1,num2,num3,num4,num5,searchNumStatic;
    printf("Please Enter Number 1 : ");
    scanf("%d", &num1);
    printf("Please Enter Number 2 : ");
    scanf("%d", &num2);
    printf("Please Enter Number 3 : ");
    scanf("%d", &num3);
    printf("Please Enter Number 4 : ");
    scanf("%d", &num4);
    printf("Please Enter Number 5 : ");
    scanf("%d", &num5);
    // Search Number
    printf("Enter Number To Search For : ");
    scanf("%d", &searchNumStatic);

    if (num1 == searchNumStatic || num2 == searchNumStatic || num3 == searchNumStatic || num4 == searchNumStatic || num5 == searchNumStatic)
    {
        printf("Value Exist Element Number");
    } else 
    {
        printf("Value Does Not Exist Element Number");
    }
    /* -------------------------------------------------------------------- */

    // Dynamic Code [Count Of Number Selected By User]
    int count,searchNumDynamic;
    printf("Please Enter Count Of Number : ");
    scanf("%d", &count);

    int arr[count];

    for (int i = 0; i < count; i++)
    {
        printf("Please Enter Number %d : ", i +1);
        scanf("%d", &arr[i]);
    }

    // Search Number
    printf("Enter Number To Search For : ");
    scanf("%d", &searchNumDynamic);

    for (int i = 0; i < count; i++)
    {
        if (arr[i] == searchNumDynamic)
        {
            printf("Value Exist Element Number");
            break;
        } else if (count == i + 1) // Search In Last Index Of Array
        {
            printf("Value Does Not Exist Element Number");
        }
    }

    return 0;
}