#include <stdio.h>

int main()
{
    int countNum,target;
    printf("Enter Number Of Elements : ");
    scanf("%d", &countNum);
    int arr[countNum];
    for (int i = 0; i < countNum; i++)
    {
        printf("Please Enter Number %d: ", i);
        scanf("%d", &arr[i]);
    }
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < countNum; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        } 
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("Maximum Is %d : \n" , max);
    printf("Minimum Is %d : \n", min);

    return 0;
}