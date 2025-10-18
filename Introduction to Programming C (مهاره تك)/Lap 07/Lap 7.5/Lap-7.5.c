#include <stdio.h>

int scalarMultiplication(int *ptrArr1, int *ptrArr2, int size);
int main()
{
    int count;
    printf("Enter Number Of Item In Array : ");
    scanf("%d", &count);
    
    int arr1[count], arr2[count];
    int *ptrArr1 = arr1;
    int *ptrArr2 = arr2;
    for (int i = 0; i < count; i++)
    {
        printf("Enter Number %d To Array One: ", i + 1);
        scanf("%d", (ptrArr1 + i));
    }
    for (int i = 0; i < count; i++)
    {
        printf("Enter Number %d To Array Two: ", i + 1);
        scanf("%d", (ptrArr2 + i));
    }
    
    printf("Scalar Multiplication of 2 arrays = %d", scalarMultiplication(ptrArr1, ptrArr2, count));
    
    return 0;
}
int scalarMultiplication(int *ptrArr1, int *ptrArr2, int size)
{   
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ((*(ptrArr1 + i)) * (*(ptrArr2 + i)));
    }
    return sum;
}