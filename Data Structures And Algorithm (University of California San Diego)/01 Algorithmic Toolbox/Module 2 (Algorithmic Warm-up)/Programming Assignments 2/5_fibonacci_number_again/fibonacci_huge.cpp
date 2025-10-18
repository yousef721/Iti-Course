#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

/*
---------------------------------------------------
 Function: get_pisano_period(m)
---------------------------------------------------
 - Finds the length of the Pisano period for a given m.
 - The Pisano period is the cycle length in the Fibonacci sequence modulo m.
   Example: Fibonacci mod 3 → 0, 1, 1, 2, 0, 2, 2, 1, (0, 1) repeats → period = 8
 - The period always appears within the range [0, m*m].
---------------------------------------------------
*/
int get_pisano_period(int m)
{
    int previous = 0;
    int current = 1;

    for (long long i = 0; i < m * m; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;

        // When the sequence returns to 0, 1 — the period has restarted
        if (previous == 0 && current == 1)
            return i + 1;
    }
    return 0;
}

/*
---------------------------------------------------
 Function: get_fibonacci_huge_fast(n, m)
---------------------------------------------------
 - Computes F(n) mod m efficiently using the Pisano period.
 - Steps:
     1. Compute Pisano period for m.
     2. Reduce n by taking n % period (since Fibonacci repeats every period).
     3. Compute the reduced Fibonacci number modulo m iteratively.
 - This drastically reduces the number of steps for very large n (e.g., 10^14).
---------------------------------------------------
*/
long long get_fibonacci_huge_fast(long long n, long long m) {
    int period = get_pisano_period(m);  // Step 1: Find Pisano period
    n = n % period;                     // Step 2: Reduce n to its equivalent within the period

    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }

    return current;                     // Step 3: Return Fibonacci(n) mod m
}

int main() {
    long long n, m;
    std::cin >> n >> m;

    // You can test both versions:
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}

/*
---------------------------------------------------
-- Explanation of the program step by step:
---------------------------------------------------
Goal:
    - Compute F(n) % m (the remainder of the nth Fibonacci number when divided by m).

Problem with naive method:
    - Fibonacci numbers grow exponentially.
    - Even for n = 1000, numbers become enormous → overflow & slow.

Key Insight — Pisano Period:
    - Fibonacci numbers modulo m repeat in cycles (Pisano period).
    - Once the pattern repeats, F(n) % m = F(n % period) % m.
    - This means we never need to compute all Fibonacci numbers up to n!

Example:
    Input: 7 3
    Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13
    13 % 3 = 1
    Output: 1

Time Complexity:
    - get_fibonacci_huge_naive(): O(n)
    - get_pisano_period(): O(m²)
    - get_fibonacci_huge_fast(): O(period)
    - Very efficient even for n = 10¹⁴ or higher.
---------------------------------------------------
*/
