#include <stdio.h>

void addAndSub(int x, int y, int *ptrSum, int *ptrSub);

int main()
{
    int x,y;
    int sum, sub; 

    printf("Please enter num1 : ");
	scanf("%d",&x);
	
	printf("Please enter num2 : ");
	scanf("%d",&y);

    addAndSub(x, y, &sum, &sub);

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("Sum = %d\n", sum);
    printf("Sub = %d\n", sub);

    return 0;
}

void addAndSub(int x, int y, int *ptrSum, int *ptrSub)
{
    *ptrSum = x + y;
    *ptrSub = x - y;
}
