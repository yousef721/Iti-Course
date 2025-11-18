#include <iostream>
#include <vector>

using std::vector;

// Each dish has:
//   - cook: time required to cook it
//   - fresh: time it stays fresh after cooking
struct Dish {
    int cook;
    int fresh;
};

// Function to check if all dishes can be cooked and remain fresh
bool canCookAllFresh(vector<Dish> dishes) {
    // STEP 1: Calculate total cooking time for all dishes
    int totalCookTime = 0;
    for (auto& d : dishes) totalCookTime += d.cook;

    // STEP 2: While there are dishes left to process
    while (!dishes.empty()) {
        // Find the dish with the largest freshness time
        int idx = 0;
        for (int i = 1; i < dishes.size(); i++) {
            if (dishes[i].fresh > dishes[idx].fresh) {
                idx = i; // store index of dish with maximum freshness
            }
        }

        // STEP 3: Subtract its cooking time from total remaining time
        totalCookTime -= dishes[idx].cook;

        // If remaining time becomes negative, it's impossible to keep all fresh
        if (totalCookTime < 0) return false;

        // STEP 4: Remove this dish from the list
        dishes.erase(dishes.begin() + idx);
    }

    // STEP 5: If all dishes processed without failure, return true
    return true;
}

int main() {
    int n;
    std::cin >> n; // number of dishes

    vector<Dish> dishes(n);

    // Read input: each dish has (cook time, fresh time)
    for (int i = 0; i < n; i++) {
        std::cin >> dishes[i].cook >> dishes[i].fresh;
    }

    // Print result: YES if possible, NO otherwise
    if (canCookAllFresh(dishes))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    return 0;
}

/*
===============================================================
                PROGRAM EXPLANATION — STEP BY STEP
===============================================================

1. PROBLEM GOAL:
---------------------------------------------------------------
   We have 'n' dishes, each with:
     - cook: time to cook the dish
     - fresh: time it stays fresh after cooking

   Goal → Check if there is an order to cook all dishes so that
           they remain fresh at some point.

---------------------------------------------------------------
2. HOW THE CODE WORKS:
---------------------------------------------------------------
   → Calculate total cooking time for all dishes.
   → Repeatedly pick the dish with the largest freshness time.
   → Subtract its cooking time from the remaining total.
   → If remaining time becomes negative, return NO.
   → Remove that dish from the list.
   → Repeat until all dishes are processed.
   → If no failure occurs, return YES.

---------------------------------------------------------------
3. EXAMPLE:
---------------------------------------------------------------
   Input:
       n = 3
       (cook, fresh)
       5 6
       1 7
       1 8

   Step-by-step:
   - Total cook time = 7
   - Pick dish with fresh=8 → remaining time = 6
   - Pick dish with fresh=7 → remaining time = 5
   - Pick dish with fresh=6 → remaining time = 0
   - All dishes processed → Output: YES ✅

---------------------------------------------------------------
4. OUTPUT:
---------------------------------------------------------------
   YES if possible, NO otherwise.

---------------------------------------------------------------
5. COMPLEXITY:
---------------------------------------------------------------
   Time complexity: O(n²) (because of repeated search for max)
   Space complexity: O(n)

===============================================================
*/
