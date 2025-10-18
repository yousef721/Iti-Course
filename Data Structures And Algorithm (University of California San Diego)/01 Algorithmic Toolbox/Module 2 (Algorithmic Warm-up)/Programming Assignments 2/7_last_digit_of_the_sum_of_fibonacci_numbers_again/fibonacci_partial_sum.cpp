#include <iostream>

// -------------------------------------------------------------
// Naive method to compute the last digit of the partial sum of
// Fibonacci numbers from index 'from' to index 'to'.
// -------------------------------------------------------------
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

// -------------------------------------------------------------
// Returns the last digit of the n-th Fibonacci number.
// Uses Pisano period optimization for modulo 10 (period = 60).
// -------------------------------------------------------------
int get_fibonacci_huge(long long n)
{
    // The sequence of Fibonacci numbers mod 10 repeats every 60 numbers.
    n = n % 60;
    
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (long long i = 0; i < n - 1; i++) 
    {
        int temp_fibonacci = previous;
        previous = current;
        current = (previous + temp_fibonacci) % 10;
    }

    return current; // Returns F(n) mod 10
}

// -------------------------------------------------------------
// Efficient function to compute the last digit of the sum of
// Fibonacci numbers in a given range: F(from) + F(from+1) + ... + F(to)
// -------------------------------------------------------------
int get_fibonacci_partial_sum_fast(long long from, long long to) {
    // Mathematical identity:
    // Sum(F(0) .. F(n)) = F(n + 2) - 1
    //
    // Therefore:
    // Sum(F(from) .. F(to)) = Sum(F(0)..F(to)) - Sum(F(0)..F(from-1))
    //                       = [F(to + 2) - 1] - [F(from + 1) - 1]
    //                       = F(to + 2) - F(from + 1)

    int sum_from = get_fibonacci_huge(from + 1); // F(from + 1) mod 10
    int sum_to = get_fibonacci_huge(to + 2);     // F(to + 2) mod 10

    // Compute last digit safely (add +10 before modulo to avoid negatives)
    int sum = (sum_to - sum_from + 10) % 10;

    return sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;

    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n'; // Slow version
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';     // Fast version
}


/*
===============================================================
           PROGRAM EXPLANATION — STEP BY STEP
===============================================================

1. Purpose:
---------------------------------------------------------------
   The program computes the **last digit of the sum of Fibonacci
   numbers within a specific range** — from F(from) to F(to).

   Mathematically:
      S(from, to) = F(from) + F(from+1) + ... + F(to)
   The program outputs the **last digit** of that sum.

   Example:
      from = 3, to = 7
      Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13
      Required part: F(3)+F(4)+F(5)+F(6)+F(7)
                     = 2 + 3 + 5 + 8 + 13 = 31
      Last digit = 1

---------------------------------------------------------------
2. Functions Overview:
---------------------------------------------------------------

(1) get_fibonacci_partial_sum_naive(from, to)
    -------------------------------------------
    - Generates all Fibonacci numbers up to index `to`.
    - Adds up the ones between `from` and `to`.
    - Returns the last digit using `sum % 10`.
    - Works fine for small inputs, but very slow for large ones.

---------------------------------------------------------------

(2) get_fibonacci_huge(n)
    -------------------------------------------
    - Returns the **last digit** of the n-th Fibonacci number.
    - Uses the **Pisano period for mod 10**, which is 60.
      (The pattern of Fibonacci mod 10 repeats every 60 numbers.)
    - Efficient even for very large n.

    Example:
       Input: n = 241
       → Since period = 60 → n % 60 = 1
       → F(241) mod 10 = F(1) mod 10 = 1

---------------------------------------------------------------

(3) get_fibonacci_partial_sum_fast(from, to)
    -------------------------------------------
    - Uses a mathematical identity to avoid looping through all terms:
          Sum(F(from) .. F(to)) = F(to + 2) - F(from + 1)
    - Calls `get_fibonacci_huge()` twice to get the last digits of
      F(to + 2) and F(from + 1).
    - Computes the final last digit as:
          (F(to + 2) - F(from + 1) + 10) % 10
      (+10 ensures we never get a negative result before the modulo.)

---------------------------------------------------------------
3. Example Calculation:
---------------------------------------------------------------
   Input:
      from = 10, to = 200
   Using the formula:
      Sum(10, 200) = F(202) - F(11)
   → F(202) mod 10 = 9
   → F(11) mod 10 = 9
   → (9 - 9 + 10) % 10 = 0

   Output: 0

---------------------------------------------------------------
4. Time Complexity:
---------------------------------------------------------------
   Naive Approach   → O(n)
   Fast Approach    → O(1)
   (Because of Pisano period optimization — only 60 iterations max)
---------------------------------------------------------------
*/
