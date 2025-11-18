#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to compute the minimum cost to connect all ropes
int minCostToConnectRopes(vector<int> ropes) {
    int totalCost = 0; // Total minimal cost

    // STEP 1: Continue until only one rope remains
    while (ropes.size() > 1)
    {
        // STEP 2: Find the two smallest ropes
        int smallNumber = INT16_MAX;        // Smallest rope length
        int secondSmallNumber = INT16_MAX;  // Second smallest rope length
        int idxSmall, idxSecondSmall;       // Indices of the two ropes

        for (int i = 0; i < ropes.size(); i++)
        {
            if(smallNumber > ropes[i]) {
                // Current rope is smaller than the smallest found so far
                secondSmallNumber = smallNumber;  // Previous smallest becomes second smallest
                smallNumber = ropes[i];           // Update smallest
                idxSecondSmall = idxSmall;        // Update index of second smallest
                idxSmall = i;                     // Update index of smallest
            } else if (secondSmallNumber > ropes[i]) {
                // Current rope is smaller than second smallest
                secondSmallNumber = ropes[i];
                idxSecondSmall = i;
            }
        }

        // STEP 3: Compute cost of connecting the two smallest ropes
        int cost = smallNumber + secondSmallNumber;
        totalCost += cost; // Add to total cost

        // STEP 4: Remove the two ropes from the vector
        if (idxSmall > idxSecondSmall) swap(idxSmall, idxSecondSmall); // Remove larger index first
        ropes.erase(ropes.begin() + idxSecondSmall);
        ropes.erase(ropes.begin() + idxSmall);

        // STEP 5: Add the new combined rope back
        ropes.push_back(cost);
    }

    // STEP 6: Return total minimal cost
    return totalCost;
}

int main() {
    int n;
    cin >> n; // Number of ropes

    vector<int> ropes(n);

    // Read input: lengths of ropes
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    // Compute minimal cost to connect all ropes
    int result = minCostToConnectRopes(ropes);

    // Print result
    cout << result << endl;

    return 0;
}
/*
===============================================================
                PROGRAM EXPLANATION — STEP BY STEP
===============================================================

1. PROBLEM GOAL:
---------------------------------------------------------------
    We have 'n' ropes, each with a length.
    Goal → Connect all ropes into one rope with minimal total cost,
        where the cost to connect two ropes = sum of their lengths.

---------------------------------------------------------------
2. HOW THE CODE WORKS:
---------------------------------------------------------------
    → While there are more than 1 rope left:
        1. Find the two ropes with the smallest lengths.
        2. Compute cost = sum of their lengths.
        3. Add the cost to totalCost.
        4. Remove the two ropes from the list.
        5. Add the new combined rope back to the list.
    → Repeat until only one rope remains.
    → Return totalCost as the minimum cost.

---------------------------------------------------------------
3. EXAMPLE:
---------------------------------------------------------------
    Input:
    4
    4 3 2 6

    Step-by-step:
    - ropes = [4,3,2,6]
    - smallest two = 2,3 → cost = 5 → totalCost = 5 → ropes = [4,6,5]
    - smallest two = 4,5 → cost = 9 → totalCost = 14 → ropes = [6,9]
    - smallest two = 6,9 → cost = 15 → totalCost = 29 → ropes = [15]
    - Only one rope remains → Output: 29

---------------------------------------------------------------
4. OUTPUT:
---------------------------------------------------------------
    Minimum total cost to connect all ropes = 29

---------------------------------------------------------------
5. COMPLEXITY:
---------------------------------------------------------------
    Time complexity: O(n^2) (because of repeated search for two smallest)
    Space complexity: O(n)

===============================================================
*/
