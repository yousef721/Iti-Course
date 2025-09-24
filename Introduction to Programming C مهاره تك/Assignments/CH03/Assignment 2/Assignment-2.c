#include <stdio.h>

int main()
{
    int id, password;
    printf("Enter Your ID : ");
    scanf("%d", &id);

    switch (id)
    {
    case 1234:
        printf("Enter Your Password : ");
        scanf("%d", &password);

        switch (password)
        {
        case 1234:
            printf("User Name Is Ahmed");
            break;
        default:
            printf("Invalid Password");
            break;
        }

        break;
    case 5678:
        printf("Enter Your Password : ");
        scanf("%d", &password);

        switch (password)
        {
        case 5678:
            printf("User Name Is Mohamed");
            break;
        default:
            printf("Invalid Password");
            break;
        }

        break;
    case 4321:
        printf("Enter Your Password : ");
        scanf("%d", &password);

        switch (password)
        {
        case 4321:
            printf("User Name Is Abdullah");
            break;
        default:
            printf("Invalid Password");
            break;
        }

        break;
    case 8765:
        printf("Enter Your Password : ");
        scanf("%d", &password);

        switch (password)
        {
        case 8765:
            printf("User Name Is Yousef");
            break;
        default:
            printf("Invalid Password");
            break;
        }

        break;
    default:
        printf("Invalid ID");
        break;
    }

    return 0;
}