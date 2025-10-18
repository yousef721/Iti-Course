#include <stdio.h>

int main()
{
    int school[3][10] = {
        {20,40,60,80,90,59,67,88,55,64},
        {50,30,65,60,100,39,99,88,75,44},
        {80,77,66,50,69,59,57,89,75,34}};

    int numberOfPassed = 0;
    int numberOfFailed = 0;
    int highestGrade = school[0][0];
    int lowsetGrade = school[0][0];
    int sum = 0;

    for(int i = 0; i < sizeof(school) / sizeof(school[0]); i++)
    {
        for(int j = 0; j < sizeof(school[i]) / sizeof(school[0][0]); j++)
        {
            if (school[i][j] >= 50)
            {
                numberOfPassed++;
            } else
            {
                numberOfFailed++;
            }
            if(highestGrade < school[i][j])
            {
                highestGrade = school[i][j];
            }
            if(lowsetGrade > school[i][j])
            {
                lowsetGrade = school[i][j];
            }
            sum += school[i][j];
        }
    }
    float avgGrade = (float)sum / (sizeof(school) / sizeof(school[0][0])); // Explict Casting

    printf("Number Of Passed Student Is %d : \n", numberOfPassed);
    printf("Number Of Failed Student Is %d : \n", numberOfFailed);
    printf("Highset Grade Is %d : \n", highestGrade);
    printf("Lowest Grade Is %d : \n", lowsetGrade);
    printf("Average Grade Is %.2f : \n", avgGrade);

    return 0;
}