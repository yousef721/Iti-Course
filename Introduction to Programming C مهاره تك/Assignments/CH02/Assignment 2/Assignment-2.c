#include <stdio.h>

int main()
{
    // Static Code [Only 3 Numbers]
    int num1,num2,num3;
    printf("Please Enter Number 1 : ");
    scanf("%d", &num1);
    printf("Please Enter Number 2 : ");
    scanf("%d", &num2);
    printf("Please Enter Number 3 : ");
    scanf("%d", &num3);
    printf("Number 3 : %d \n",num3);
    printf("Number 2 : %d \n",num2);
    printf("Number 1 : %d \n",num1);


    // Dynamic Code [Numbers selected by user]
    int countNum;
    printf("Enter Number Of Elements : ");
    scanf("%d", &countNum);
    int arr[countNum];
    for (int i = 0; i < countNum; i++)
    {
        printf("Enter Number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = countNum - 1; i >= 0; i--)
    {
        printf("Number %d : %d\n", i + 1, arr[i]);
    }    
    return 0;
}