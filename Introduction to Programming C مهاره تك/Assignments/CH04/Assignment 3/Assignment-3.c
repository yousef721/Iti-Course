#include <stdio.h>

int main()
{
    int row;
    printf("Enter Number Of Row : ");
    scanf("%d", &row);
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < row; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}