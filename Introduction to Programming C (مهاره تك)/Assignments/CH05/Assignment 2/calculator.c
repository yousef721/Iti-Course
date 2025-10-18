#include "calculator.h" // Interface

int add(int num1, int num2) { return num1 + num2; }
int subtract(int num1, int num2) { return num1 - num2; }
int multiply(int num1, int num2) { return num1 * num2; }
float divided(int num1, int num2) { return (float)num1 / num2; }
int bitwiseAnd(int num1, int num2) { return num1 & num2; }
int bitwiseOr(int num1, int num2) { return num1 | num2; }
int bitwiseXOr(int num1, int num2) { return num1 ^ num2; }
int remainderUserDefined(int num1, int num2) { return num1 % num2; }
int bitwiseNot(int num) { return ~num; }
int increment(int num) { return num + 1; }
int decrement(int num) { return num - 1; }