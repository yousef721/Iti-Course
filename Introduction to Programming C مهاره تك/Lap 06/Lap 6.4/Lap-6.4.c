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

    printf("Enter Value To Search About : ");
    scanf("%d", &target);


    int count = 0; 
    for (int i = 0; i < countNum; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    if (count > 0) {
        printf("Value exists %d time(s)\n", count);
    } else {
        printf("Value does not exist\n");
    }
    return 0;
}