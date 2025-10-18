#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum;
}

int fibonacci_fast(long long n) {
    // -----------------------------------------------
    // Optimization using Pisano Period:
    // -----------------------------------------------
    // - The sequence of Fibonacci numbers modulo 10 repeats every 60 terms.
    // - This repeating cycle is known as the Pisano period (for modulus 10).
    // - Therefore, we only need to compute F(n % 60) to find the result efficiently.
    // Example: Fibonacci mod 10 → 0, 1, 1, 2, 3, 5, 8, 3, 1, 4, ... → repeats → period = 60
    n = n % 60;

    int previous = 0;
    int current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10; // Keep only last digit
    }

    return current; // Return F(n) mod 10
}

int fibonacci_sum_last_digit(long long n) {
    if (n <= 1)
        return n;

    // -----------------------------------------------
    // Formula used:
    // Sum(F(0) .. F(n)) = F(n + 2) - 1
    //
    // To get the last digit:
    // (F(n + 2) - 1) mod 10  ≡  (F(n + 2) + 9) mod 10
    // (We add 9 instead of subtracting 1 to avoid negatives)
    // -----------------------------------------------
    int sum = (fibonacci_fast(n + 2) + 9) % 10;
    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;

    std::cout << fibonacci_sum_naive(n) << std::endl;  // Slow version
    std::cout << fibonacci_sum_last_digit(n) << std::endl; // Fast version
}


/*
---------------------------------------------------------------
-- Explanation of the program step by step:
---------------------------------------------------------------

1. Purpose:
---------------------------------------------------------------
   This program calculates the **last digit of the sum of the
   first n Fibonacci numbers**.

   Mathematically:
      S(n) = F(0) + F(1) + F(2) + ... + F(n)
   The output is:
      last_digit(S(n))

   Example:
      Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8
      Sum S(6) = 0 + 1 + 1 + 2 + 3 + 5 + 8 = 20
      Last digit = 0

---------------------------------------------------------------
2. Functions Overview:
---------------------------------------------------------------

(1) fibonacci_sum_naive(n)
    -------------------------
    - Computes Fibonacci numbers one by one.
    - Keeps a running total of their sum.
    - Returns (sum % 10) → the last digit.
    - Simple but inefficient for large n (too slow).

    Example:
       Input: 7
       Fibonacci numbers: 0, 1, 1, 2, 3, 5, 8, 13
       Sum = 33 → last digit = 3
       Output: 3

---------------------------------------------------------------

(2) fibonacci_fast(n)
    -------------------------
    - Computes the last digit of F(n) efficiently.
    - Uses the Pisano period (mod 10 → period = 60).
    - Avoids large numbers by taking % 10 at each step.

    Example:
       Input: 7
       F(7) = 13 → 13 % 10 = 3
       Output: 3

---------------------------------------------------------------

(3) fibonacci_sum_last_digit(n)
    -------------------------
    - Uses a mathematical shortcut:
          S(n) = F(n + 2) - 1
    - So, we only need F(n + 2), not all Fibonacci numbers.
    - Calls `fibonacci_fast(n + 2)` to get it efficiently.
    - Adjusts result with +9 to handle negative modulo cases.

---------------------------------------------------------------
3. Example Calculation:
---------------------------------------------------------------
   Input: 239  
   Goal: Find last digit of S(239)

   Step 1: S(239) = F(241) - 1  
   Step 2: F(241) mod 10 = 1  
   Step 3: (1 - 1) mod 10 = 0  

   Output: 0

---------------------------------------------------------------
4. Time Complexity:
---------------------------------------------------------------
   Naive Approach   → O(n)
   Fast Approach    → O(1)   (due to Pisano period optimization)
---------------------------------------------------------------
*/
