#include <stdio.h>

int main()
{
    printf("Hello World");
    return 0;
}


//  Building Process in C
//  _____________________

/*
    1) Preprocessing only:
        gcc -E Lap-10.1.c -o out.i
        🔹 Runs only the **preprocessor** stage.
        🔹 Expands #include, replaces macros, removes comments.
        🔹 Output is saved in "out.i".
*/

/*
    2) Compilation to Assembly:
        gcc -S Lap-10.1.c -o out.asm
        🔹 Runs the **compiler** stage (after preprocessing).
        🔹 Translates the C code into Assembly language.
        🔹 Output is saved in "out.asm".

        👉 This lets you see the low-level assembly instructions
        generated from your C code, but it does not yet create
        an object file or executable.
*/

/*
    3) Assembly to Object file:
        gcc -c Lap-10.1.c -o out.o
        🔹 Runs the **assembler** stage.
        🔹 Converts the assembly code into **machine code**
        stored inside an object file (.o).
        🔹 Output is "out.o".

        👉 At this point, it's machine code but not executable yet
        because no linking has been done.
*/

/*
    4) Linking:
        gcc Lap-10.1.c -o out.exe
        🔹 Runs the **full pipeline**: preprocessing → compiling
        → assembling → linking.
        🔹 Produces a final executable file: "out.exe".

        👉 This is the file you can run directly.
*/