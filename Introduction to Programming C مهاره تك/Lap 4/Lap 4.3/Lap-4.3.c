#include <stdio.h>

int main()
{
    int sum,num;
    float avg = 0.0;
    sum = 0; // initialization [variable in c if not initial set garbage value]
    printf("Enter The 10 Number: \n");
    for (int i = 1; i <= 10; i++)
    {
        printf("Number %d : ", i);
        scanf("%d", &num);
        sum += num;
    }
    printf("The Sum Of 10 No Is: %d \n", sum);
    avg = (float)sum / 10.0; // Explicit Casting || Implicit Casting [To change from int to float]
    printf("The Avarage Is: %.2f", avg);

    return 0;
}