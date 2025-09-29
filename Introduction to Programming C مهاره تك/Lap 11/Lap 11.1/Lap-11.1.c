#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count;
    int *ptr; // pointer to hold dynamically allocated array
    
    // 1) Get number of elements from user
    printf("Please Enter The Number Of Numbers: ");
    scanf("%d", &count);

    // 2) Allocate memory dynamically using malloc
    ptr = (int*)malloc(count * sizeof(int));

    // 3) Check if malloc failed
    if (ptr == NULL)
    {
        printf("Sorry! unable to allocate memory");
        exit(0);
    }

    // 4) Take input from user into the allocated array
    for(int i = 0; i < count; i++)
    {
        printf("Please Enter Number %d : " , i + 1);
        scanf("%d", (ptr + i)); // store input at (ptr+i)
    }
    
    // 5) Sort values using Bubble Sort
    printf("The values after sorting are :\n");
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (*(ptr + j) > *(ptr + j + 1))
            {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }

    // 6) Print the sorted values
    for(int i = 0; i < count; i++)
    {
        printf("%d\n", *(ptr + i));
    }

    // 7) Free allocated memory
    free(ptr);

    return 0;
}
