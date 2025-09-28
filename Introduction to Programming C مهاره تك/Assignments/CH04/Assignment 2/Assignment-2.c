#include <stdio.h>

int main()
{
    int password,id;
    printf("Enter Your ID : ");
    scanf("%d", &id);

    if (id == 1234)
    {
        printf("Enter Your Password : ");
        scanf("%d", &password);
        // i = Tries
        int i = 4; // Equal 4 To Enter Loop if The last Try Is Correct
        for (; i > 0; i--)
        {
            if (password == 7788)
            {
                printf("Welcome Ahmed");
                break;
            } else
            {
                printf("Incorrect Password Try Again [%d tries left]: ", i - 1);
                scanf("%d", &password);
            }
        }
        if (i == 0)
        {
            printf("No More Tries");
        }
    } else if (5678)
    {
        printf("Enter Your Password : ");
        scanf("%d", &password);
        int i = 4;
        for (; i > 0; i--)
        {
            if (password == 5566)
            {
                printf("Welcome Amr");
                break;
            } else
            {
                printf("Incorrect Password Try Again [%d tries left]: ", i - 1);
                scanf("%d", &password);
            }
        }
        if (i == 0)
        {
            printf("No More Tries");
        }

    } else if (9870)
    {
        printf("Enter Your Password : ");
        scanf("%d", &password);
        int i = 4;
        for (; i > 0; i--)
        {
            if (password == 1122)
            {
                printf("Welcome wael");
                break;
            } else
            {
                printf("Incorrect Password Try Again [%d tries left]: ", i - 1);
                scanf("%d", &password);
            }
        }
        if (i == 0)
        {
            printf("No More Tries");
        }

    } else
    {
        printf("You are Not Registered");
    }
    
    return 0;
}