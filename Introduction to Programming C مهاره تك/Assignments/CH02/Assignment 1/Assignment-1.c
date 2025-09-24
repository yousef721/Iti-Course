#include <stdio.h>

int main()
{
    // Static Code [Only 10 Rows]
    printf("         *\n");
    printf("        * *\n");
    printf("       * * *\n");
    printf("      * * * *\n");
    printf("     * * * * *\n");
    printf("    * * * * * *\n");
    printf("   * * * * * * *\n");
    printf("  * * * * * * * *\n");
    printf(" * * * * * * * * *\n");
    printf("* * * * * * * * * *\n");


    // Dynamic Code [Rows Selected By User]
    int row;
    printf("Enter Number Of Row : ");
    scanf("%d", &row);
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < row; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}