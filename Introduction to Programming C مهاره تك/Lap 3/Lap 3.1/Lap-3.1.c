#include <stdio.h>

int main()
{
    int hours;
    printf("Please Enter Your Working Hour : ");
    scanf("%d", &hours);
    int salary = hours * 50;
    if (hours < 40)
    {
        int deduction = hours * 50 * 10 / 100;
        salary -= deduction;
    }
    printf("Your Salary Is %d", salary);

    return 0;
}