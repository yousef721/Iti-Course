#include <stdio.h>

void PrintMyName(void); // Declaration Function Another File

int main()
{
    PrintMyName();
    return 0;
}

/* 
Link Two Files To Generate One Executable File :
    1 ) Use This Command "clang Lap-5.3.c PrintMyName.c -o program"
    2 ) Then Run by This Command "./program"
*/