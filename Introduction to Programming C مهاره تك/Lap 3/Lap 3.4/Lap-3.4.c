#include <stdio.h>

int main()
{
    int id;
    printf("Please Enter Your ID : ");
    scanf("%d", &id);

    switch (id)
    {
    case 1234:
        printf("Welcome Ahmed");
        break;
    case 2345:
        printf("Welcome Mohamed");
    break;
    case 3456:
        printf("Welcome Abdullah");
    break;
    case 4567:
        printf("Welcome Said");
    break;
    default:
        printf("Wrong ID");
        break;
    }
    return 0;
}