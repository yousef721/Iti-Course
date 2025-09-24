#include <stdio.h>

int main()
{
    int grade;
    printf("Please Enter Your Grade : ");
    scanf("%d", &grade);

    if (grade >= 85)
    {
        printf("You Are Rating Is Excellent");
    } else if (grade < 85 && grade >= 75)
    {
        printf("You Are Rating Is Very Good");

    } else if (grade < 75 && grade >= 65)
    {
        printf("You Are Rating Is Good");

    } else if (grade < 65 && grade >= 50)
    {
        printf("You Are Rating Is Normal");

    } else if (grade < 50 && grade >= 0)
    {
        printf("You Are Rating Is Failed");
    }
    
    return 0;
}