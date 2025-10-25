#include <iostream>

// -------------------------------------------------------------
// Recursive Greedy Method for the Money Change Problem
// -------------------------------------------------------------
int get_change(int m) {
    int denominations[3] = {1, 5, 10}; // available coin denominations

    // Base case: if no money is left, no coins are needed
    if (m == 0)
        return 0;

    // Choose the largest possible coin that does not exceed m
    if (m >= 10) {
        m -= 10; // use a 10-coin
    } else if (m >= 5) {
        m -= 5;  // use a 5-coin
    } else {
        m -= 1;  // use a 1-coin
    }

    // Each recursive call represents taking one coin
    return 1 + get_change(m);
}

// -------------------------------------------------------------
// Fast Mathematical Solution (O(1) time)
// -------------------------------------------------------------
int get_change_fast(int m)
{
    // number of 10-value coins we can take
    int d10 = m / 10;

    // remainder → amount left after taking 10-value coins
    int remainder = m % 10;

    // number of 5-value coins we can take from the remainder
    int d5 = remainder / 5;

    // number of 1-value coins needed for the rest
    int d1 = remainder % 5;

    // total number of coins = a (10s) + b (5s) + c (1s)
    return d10 + d5 + d1;
}

// -------------------------------------------------------------
// Main Function
// -------------------------------------------------------------
int main() {
    int m;
    std::cin >> m;

    // Option 1: recursive version (slow)
    // std::cout << get_change(m) << '\n';

    // Option 2: fast version (recommended)
    std::cout << get_change_fast(m) << '\n';

    return 0;
}

/*
===============================================================
                PROGRAM EXPLANATION — STEP BY STEP
===============================================================

1. PROBLEM DEFINITION:
---------------------------------------------------------------
   You need to compute the **minimum number of coins**
   required to make change for a given amount of money `m`
   using coins with denominations {1, 5, 10}.

   Example:
       Input: 28
       Coins: {10, 10, 5, 1, 1, 1}
       Output: 6  (because 6 coins are used)

---------------------------------------------------------------
2. APPROACH 1 — Recursive Greedy Solution (get_change)
---------------------------------------------------------------
   Logic:
   - Always take the largest possible coin.
   - Subtract it from the total.
   - Repeat recursively until `m = 0`.

   Example:
       m = 28
       → take 10 → m = 18
       → take 10 → m = 8
       → take 5 → m = 3
       → take 1 → m = 2
       → take 1 → m = 1
       → take 1 → m = 0
       Total coins = 6

   Drawback:
       - Works correctly but is **slow** for large inputs
         because it calls itself many times recursively.
       - Time complexity ≈ O(m)

---------------------------------------------------------------
3. APPROACH 2 — Fast Mathematical Solution (get_change_fast)
---------------------------------------------------------------
   - Instead of subtracting coins one by one,
     we use simple division and modulo operations.

   Step-by-step example (m = 28):
   -----------------------------------------
   d10 = m / 10 = 2    → take two 10s
   remainder = 28 % 10 = 8
   d5 = remainder / 5 = 1   → take one 5
   d1 = remainder % 5 = 3   → take three 1s

   Total = d10 + d5 + d1 = 2 + 1 + 3 = 6 coins ✅

   Time complexity: O(1)
   → Just a few arithmetic operations, no loops or recursion.

---------------------------------------------------------------
4. MATHEMATICAL OBSERVATION:
---------------------------------------------------------------
   For any value `m`:
       m = 10a + 5b + 1c
   where:
       d10 = number of 10-coins
       d5 = number of 5-coins
       d1 = number of 1-coins

   The fastest way is to always use as many 10s as possible,
   then 5s, and then 1s — this is a **greedy algorithm**
   that happens to be optimal for these denominations.

---------------------------------------------------------------
5. SAMPLE RUN:
---------------------------------------------------------------
   Input:
       28

   Execution (fast version):
       a = 2
       remainder = 8
       b = 1
       c = 3
       Output = 6

   Therefore, the minimum number of coins = 6.

---------------------------------------------------------------
6. SUMMARY:
---------------------------------------------------------------
   • Recursive version → simple but slower.
   • Fast version → uses math to directly compute result.
   • Both produce the same correct answer.
   • Fast version preferred for performance.
===============================================================
*/
