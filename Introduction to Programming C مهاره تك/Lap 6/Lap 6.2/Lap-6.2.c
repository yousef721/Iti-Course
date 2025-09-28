#include <stdio.h>

int main()
{
    int countNum,sumArr = 0;
    printf("Enter Number Of Elements : ");
    scanf("%d", &countNum);
    int arr[countNum];
    for (int i = 0; i < countNum; i++)
    {
        printf("Please Enter Number %d: ", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < sizeof(arr) / 4; i++)
    {
        sumArr += arr[i];
    }
    

    printf("The Sum Is: %d \n", sumArr);
    float avg = (float)sumArr / ( sizeof(arr) / 4); // Explicit Casting -> (float)sumArr [To change from int to float]
    printf("The Avarage Is: %.2f", avg);

    return 0;
}