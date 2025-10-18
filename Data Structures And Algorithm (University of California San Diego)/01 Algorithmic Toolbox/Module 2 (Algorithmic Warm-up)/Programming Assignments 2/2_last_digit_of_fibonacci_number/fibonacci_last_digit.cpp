#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n){
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
}

int main() 
{
    int n;
    std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    int cfast = get_fibonacci_last_digit_fast(n);
    // std::cout << c << '\n';
    std::cout << cfast << '\n';
}

/*
-----------------------------------------------
-- Explanation of the program step by step:
-----------------------------------------------

1. The program computes the **last digit of the nth Fibonacci number**.

   Example:
   Fibonacci sequence:  0, 1, 1, 2, 3, 5, 8, 13, ...
   Last digits only:    0, 1, 1, 2, 3, 5, 8, 3, ...

2. There are two implementations:
   --------------------------------------------
   get_fibonacci_last_digit_naive()
   --------------------------------------------
   - Calculates the full Fibonacci number.
   - Takes the last digit at the end using `% 10`.
   - May overflow for large `n` because the Fibonacci numbers grow very fast.
     Example:
        Input: 239 
        Output (wrong): 9
        Correct output: 1

   --------------------------------------------
   get_fibonacci_last_digit_fast()
   --------------------------------------------
   - Uses `% 10` **inside** the loop at every step.
   - Keeps numbers small (0–9) throughout the computation.
   - Avoids overflow and works efficiently even for large `n`.

3. main():
   - Reads `n` from input.
   - Calls the fast function.
   - Prints the last digit of `F(n)`.

-----------------------------------------------
-- Example:
-----------------------------------------------
Input: 7
Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13
Last digit of F(7) = 3
Output: 3

-----------------------------------------------
-- Time Complexity:
-----------------------------------------------
Naive approach: O(n)
Fast approach:  O(n)
(Same complexity, but the fast version avoids large number overflow.)
-----------------------------------------------
*/
