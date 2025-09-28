#include <stdio.h>

/*
    Using typedef to define fixed-size types.
    --------------------------------------------------
    - The size of C built-in types (char, int, short, long...) 
      may differ between compilers or platforms.

    Example:
      'int' may be 2 bytes on some compilers, 
      and 4 bytes on others.

    - That's why we use typedef to give them consistent names 
      (u8, u16, u32...).

    - Note: 'char' is always 1 byte according to the C standard, 
      but the definition of a "byte" (usually 8 bits) depends on 
      the platform.

    - If you need guaranteed fixed-width types, 
      it's better to use <stdint.h> (e.g., uint8_t, uint16_t, uint32_t).
*/

typedef unsigned char       u8;   // 1 byte (usually 8 bits)
typedef signed char         s8;   // 1 byte signed

typedef unsigned short int  u16;  // 2 bytes (usually 16 bits)
typedef unsigned int        u32;  // 4 bytes (usually 32 bits)

typedef signed short int    s16;  // 2 bytes signed
typedef signed int          s32;  // 4 bytes signed

typedef float               f32;  // 4 bytes (single precision)
typedef double              f64;  // 8 bytes (double precision)
typedef long double         f128; // 16 bytes on some compilers

int main()
{
    printf("The size of unsigned char data type = %zu \n", sizeof(u8));
    printf("The size of signed char data type = %zu \n", sizeof(s8));
    
    printf("The size of short unsigned int data type = %zu \n", sizeof(u16));
    printf("The size of unsigned int data type = %zu \n", sizeof(u32));
    
    printf("The size of short signed int data type = %zu \n", sizeof(s16));
    printf("The size of signed int data type = %zu \n", sizeof(s32));
    
    printf("The size of float data type = %zu \n", sizeof(f32));
    printf("The size of double data type = %zu \n", sizeof(f64));
    printf("The size of long double data type = %zu \n", sizeof(f128));    
    
    return 0;
}
