#include <stdio.h>

// -------------------------------
// Method 1: Default struct (with compiler padding)
// Compiler will add padding automatically to align data members
typedef struct
{
    char a;  // 1 byte 
    char b;  // 1 byte 
             // compiler adds 2 bytes padding
    int x;   // 4 bytes
} structPadding1;
// Expected size = 8 bytes (2 bytes padding)

// -------------------------------
// Method 2: Using pragma pack(1)
// Force compiler to pack the struct without adding padding
#pragma pack(1)   // Force 1-byte alignment for all structs defined after this line
// #pragma pack()    // Reset packing to compiler default
typedef struct 
{
    char a; // 1 byte 
    char b; // 1 byte 
    int x;  // 4 bytes
} structPadding2;
// Expected size = 6 bytes (no padding)

// -------------------------------
// Method 3: Using GCC attribute (packed)
// Packing is applied only to this struct (does not affect others)
typedef struct 
{
    char a; // 1 byte 
    char b; // 1 byte 
    int x;  // 4 bytes
} structPadding3 __attribute__((packed));
// Expected size = 6 bytes (no padding)

// -------------------------------

int main()
{
    structPadding1 s1;
    structPadding2 s2;
    structPadding3 s3;
	
    printf("Size of struct (Method 1, default padding) = %zu\n", sizeof(s1)); 
    printf("Size of struct (Method 2, pragma pack)     = %zu\n", sizeof(s2)); 
    printf("Size of struct (Method 3, attribute)       = %zu\n", sizeof(s3)); 

    return 0;
}
