#include <stdio.h>

int main()
{
    int answer;
    printf("Enter The Answer Of 3 x 4 = ");
    scanf("%d", &answer);
    
    while (answer != 12)
    {
        printf("Not Correct, Try Again: ");
        scanf("%d", &answer);
    }
    
    printf("Thank You");
    
    return 0;
}