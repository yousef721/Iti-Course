#include <iostream>
#include <vector>
using namespace std;

// ============================================================================
//  FUNCTION: get_optimal_value
// ============================================================================
//  Purpose:
//      Solves the Fractional Knapsack problem recursively.
//
//  Parameters:
//      - capacity : remaining weight capacity of the knapsack.
//      - weights  : vector containing item weights.
//      - values   : vector containing item values.
//
//  Logic Summary:
//      1. Base case: stop when capacity = 0 or no items left.
//      2. Find the item with the highest value-to-weight ratio.
//      3. Take as much as possible from that item (may take a fraction).
//      4. Calculate the gained value for the taken amount.
//      5. Remove that item and recurse with reduced capacity.
// ============================================================================
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    if (capacity == 0 || weights.empty())
        return 0; // Base case

    // Step 1: Find the item with the best value-to-weight ratio
    int bestIndex = 0;
    double bestRatio = (double)values[0] / weights[0];

    for (int i = 1; i < weights.size(); i++) {
        double ratio = (double)values[i] / weights[i];
        if (ratio > bestRatio) {
            bestRatio = ratio;
            bestIndex = i;
        }
    }

    // Step 2: Take as much as possible from the selected item
    int amount = min(weights[bestIndex], capacity);

    // Step 3: Compute the fractional value taken
    double value = values[bestIndex] * ((double)amount / weights[bestIndex]);

    // Step 4: Remove the used item and reduce capacity
    weights.erase(weights.begin() + bestIndex);
    values.erase(values.begin() + bestIndex);
    capacity -= amount;

    // Step 5: Recurse for remaining items and capacity
    return value + get_optimal_value(capacity, weights, values);
}

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<int> values(n);
    vector<int> weights(n);

    for (int i = 0; i < n; i++)
        cin >> values[i] >> weights[i];

    double optimal_value = get_optimal_value(capacity, weights, values);

    cout.precision(10);
    cout << fixed << optimal_value << endl;
    return 0;
}

/*
=======================================================================
                 PROGRAM EXPLANATION — STEP BY STEP
=======================================================================

1. PROBLEM DEFINITION
---------------------------------
Given:
  • n items, each with a value and a weight
  • A knapsack with limited capacity W

Goal:
  → Maximize the total value that can be placed in the knapsack.
  → You are allowed to take *fractions* of items (not just whole items).

Example:
  Input:
    n = 3, W = 50
    Values  = [60, 100, 120]
    Weights = [20, 50, 30]

  Output:
    180.0000000000


2. RECURSIVE GREEDY STRATEGY
---------------------------------
At each step:
  1. Find the item with the best value-to-weight ratio.
  2. Take as much of it as possible (fully or partially).
  3. Remove it from the list.
  4. Recurse on the remaining capacity and items.

Base case:
  → Stop when capacity = 0 or no items remain.


3. EXAMPLE EXECUTION
---------------------------------
W = 50
Items:
   #1: value = 60, weight = 20 → ratio = 3
   #2: value = 100, weight = 50 → ratio = 2
   #3: value = 120, weight = 30 → ratio = 4

Step 1 → Pick item #3 (best ratio = 4)
   Take all 30 weight → gain = 120
   Remaining capacity = 20

Step 2 → Pick item #1 (ratio = 3)
   Take all 20 weight → gain = 60
   Remaining capacity = 0

✅ Total value = 120 + 60 = 180


4. WHY THE GREEDY METHOD WORKS
---------------------------------
For the *fractional* knapsack problem, the greedy approach is **optimal**
because taking the highest value per unit weight first always leads to
the maximum total value (this follows the "Greedy Choice Property").


5. COMPLEXITY ANALYSIS
---------------------------------
Each recursive call:
   - Finds the max ratio → O(n)
   - Removes one item     → O(n) shift
   - Total calls = n

➡ Time Complexity:  O(n²)
➡ Space Complexity: O(n)  (due to recursion stack)


6. SUMMARY
---------------------------------
-- Problem Type: Fractional Knapsack (Greedy + Recursion)
-- Strategy: Pick highest (value / weight) ratio repeatedly
-- Stops when bag is full or no items left
-- Guarantees optimal result without using `sort()`
===============================================================================
*/
