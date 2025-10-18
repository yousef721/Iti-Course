#include <iostream>

// -------------------------------------------------------------
// Naive method to compute the last digit of the sum of squares
// of the first n Fibonacci numbers.
// -------------------------------------------------------------
int fibonacci_sum_squares_naive(long long n) {

    // The Pisano period for modulo 10 is 60 — Fibonacci mod 10 repeats every 60 numbers.
    n = n % 60;

    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    // Compute Fibonacci numbers and accumulate the sum of their squares
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;  // Return only the last digit
}

// -------------------------------------------------------------
// Helper function: returns the last digit of the n-th Fibonacci number.
// Uses Pisano period optimization for modulo 10 (period = 60).
// -------------------------------------------------------------
int get_fibonacci(long long n) {

    n = n % 60;

    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;  // F(n) mod 10
}

// -------------------------------------------------------------
// Efficient method to compute the last digit of the sum of squares
// of Fibonacci numbers up to F(n).
// -------------------------------------------------------------
int fibonacci_sum_squares_fast(long long n)
{
    // Mathematical identity:
    // ----------------------------------------
    // Sum(F(0)^2 + F(1)^2 + ... + F(n)^2) = F(n) * F(n + 1)
    // ----------------------------------------
    // So instead of squaring and summing all Fibonacci numbers,
    // we can simply calculate F(n) and F(n + 1) and multiply them.

    long long fab = get_fibonacci(n);       // F(n) mod 10
    long long fab_plus_1 = get_fibonacci(n + 1); // F(n + 1) mod 10

    // The result is the last digit of F(n) * F(n + 1)
    return (fab * fab_plus_1) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;

    // std::cout << fibonacci_sum_squares_naive(n) << std::endl; // Slow version
    std::cout << fibonacci_sum_squares_fast(n) << std::endl;     // Fast version
}


/*
===============================================================
           PROGRAM EXPLANATION — STEP BY STEP
===============================================================

1. Purpose:
---------------------------------------------------------------
   The program computes the **last digit of the sum of squares of
   the first n Fibonacci numbers**.

   Mathematically:
      S(n) = F(0)^2 + F(1)^2 + F(2)^2 + ... + F(n)^2

   Example:
      Fibonacci sequence: 0, 1, 1, 2, 3
      S(4) = 0² + 1² + 1² + 2² + 3² = 15
      Last digit = 5

---------------------------------------------------------------
2. Functions Overview:
---------------------------------------------------------------

(1) fibonacci_sum_squares_naive(n)
    -------------------------------------------
    - Generates all Fibonacci numbers up to index n.
    - Squares each Fibonacci number and adds it to `sum`.
    - Finally returns `sum % 10`.
    - Works correctly but is slow for large n.

---------------------------------------------------------------

(2) get_fibonacci(n)
    -------------------------------------------
    - Returns the **last digit** of the n-th Fibonacci number.
    - Uses the **Pisano period** for modulo 10 (period = 60).
      → This means Fibonacci mod 10 repeats every 60 numbers.
    - Keeps calculations efficient and prevents overflow.

---------------------------------------------------------------

(3) fibonacci_sum_squares_fast(n)
    -------------------------------------------
    - Uses a mathematical identity:
         Sum(F(0)^2 .. F(n)^2) = F(n) × F(n + 1)
    - So we only compute F(n) and F(n + 1),
      multiply them, and take the last digit.

    Example:
       Input: n = 7
       Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13
       S(7) = 0²+1²+1²+2²+3²+5²+8²+13² = 273
       Last digit = 3

       F(7) = 13 → last digit = 3
       F(8) = 21 → last digit = 1
       F(7) * F(8) = 3 × 1 = 3 → correct!

---------------------------------------------------------------
3. Example:
---------------------------------------------------------------
Input:
   n = 239
Steps:
   → F(239) mod 10 = 1
   → F(240) mod 10 = 0
   → (1 × 0) % 10 = 0

Output: 0

---------------------------------------------------------------
4. Time Complexity:
---------------------------------------------------------------
   Naive Approach   → O(n)
   Fast Approach    → O(1)
   (Because Pisano period = 60 → at most 60 iterations)
---------------------------------------------------------------
*/
