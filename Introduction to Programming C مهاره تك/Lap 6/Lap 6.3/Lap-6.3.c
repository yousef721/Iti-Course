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


    for (int i = 0; i < countNum - 1; i++) {
        for (int j = 0; j < countNum - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array After Sorting : ");
    printf("{");
    for (int i = 0; i < countNum; i++)
    {
        if (countNum == i + 1)
            printf("%d", arr[i]);
        else
            printf("%d,", arr[i]);
    }
    printf("} \n");
    
    return 0;
}