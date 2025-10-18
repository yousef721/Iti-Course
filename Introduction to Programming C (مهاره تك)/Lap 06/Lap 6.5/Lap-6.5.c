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

    int start = 0;    
    int end = countNum - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == target) 
        {
            printf("Value found");
            break;
        } else if (arr[mid] > target)
        {
            end = --mid;
        } else 
        {
            start = ++mid;
        }
    }
	if(start > end)
		printf("Value Not Exist");
        
    
    return 0;
}