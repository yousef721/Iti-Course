#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

// -------------------------------------------------------------
// Function: optimal_summands
// Purpose : Find the maximum number of distinct positive integers
//            whose sum equals the given number n.
// -------------------------------------------------------------
vector<int> optimal_summands(int n) {
    vector<int> summands; // store the distinct integers (prizes)
    int current = 1;      // start from 1 and keep increasing

    // Keep adding numbers as long as the remaining candies
    // are enough to give a distinct next prize
    while (n > 2 * current) {
        summands.push_back(current);
        n -= current;   // reduce n by the used candies
        current++;      // move to next distinct number
    }

    // Add the remaining candies as the last (possibly larger) number
    summands.push_back(n);

    return summands;
}

// -------------------------------------------------------------
// Main Function
// -------------------------------------------------------------
int main() {
    int n;
    cin >> n; // Input the total number of candies

    vector<int> summands = optimal_summands(n);

    // Output number of children (k)
    cout << summands.size() << "\n";

    // Output the actual distribution (distinct summands)
    for (int i = 0; i < summands.size(); ++i) {
        cout << summands[i] << " ";
    }
    cout << "\n";

    return 0;
}



/*
===============================================================
                PROGRAM EXPLANATION — STEP BY STEP
===============================================================

1. PROBLEM GOAL:
---------------------------------------------------------------
   You have a total of `n` candies.
   You want to distribute them among children so that:
     ✅ Each child gets a *different* (distinct) number of candies.
     ✅ A higher place gets *more* candies.
     ✅ You maximize the *number of children* who get candies.

   Mathematically:
       Find the maximum number k such that:
          n = a₁ + a₂ + ... + aₖ
       where all aᵢ are distinct positive integers.

---------------------------------------------------------------
2. HOW THE CODE WORKS:
---------------------------------------------------------------
   → The program starts from 1 and keeps adding consecutive numbers
     (1, 2, 3, 4, ...) as long as the remaining candies (n)
     can still support the next distinct number.

   → When there are not enough candies to give the next distinct number,
     the remaining candies are all added to the *last child*.

---------------------------------------------------------------
3. DETAILED EXAMPLE:
---------------------------------------------------------------
   Input:
       n = 8

   Step 1 → current = 1, n = 8 → n > 2×1 ✅
       summands = [1], n = 8 - 1 = 7

   Step 2 → current = 2, n = 7 → n > 2×2 ✅
       summands = [1, 2], n = 7 - 2 = 5

   Step 3 → current = 3, n = 5 → n > 2×3 ❌
       stop loop and add remaining n (5) as last number

   Final summands = [1, 2, 5]
   Total sum = 1 + 2 + 5 = 8 ✅

---------------------------------------------------------------
4. OUTPUT:
---------------------------------------------------------------
   3
   1 2 5

---------------------------------------------------------------
5. COMPLEXITY:
---------------------------------------------------------------
   Time complexity:  O(√n)
   Space complexity: O(√n)

   (Because the loop increases `current` until 1+2+3+... ≈ n)

===============================================================
*/
