#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>    

using namespace std;

// Function to find the minimum time for all mice to get into holes
int mice_holes(vector<int> mice, vector<int> holes) {
    // STEP 1: Sort both mice and holes positions
    // Sorting ensures that each mouse is assigned to the closest hole
    sort(mice.begin(), mice.end());
    sort(holes.begin(), holes.end());

    int maxDistance = 0; // To store the maximum distance any mouse has to travel
    
    // STEP 2: Assign each mouse to the corresponding hole
    for (int i = 0; i < mice.size(); i++) {
        int distance = abs(mice[i] - holes[i]); // distance between mouse and hole
        if (distance > maxDistance)
            maxDistance = distance; // update maximum distance if current is larger
    }

    // STEP 3: Return the maximum distance
    // This represents the minimum time needed for all mice to get into holes
    return maxDistance; 
}

int main() {
    int n;
    cin >> n; // number of mice (and also holes)

    vector<int> mice(n);
    vector<int> holes(n);

    // STEP 4: Read positions of mice
    for (int i = 0; i < n; i++)
        cin >> mice[i];

    // STEP 5: Read positions of holes
    for (int i = 0; i < n; i++)
        cin >> holes[i];

    // STEP 6: Print the minimum time (maximum distance)
    cout << mice_holes(mice, holes) << endl;

    return 0;
}

/*
===============================================================
                PROGRAM EXPLANATION — STEP BY STEP
===============================================================

1. PROBLEM GOAL:
---------------------------------------------------------------
   We have 'n' mice and 'n' holes on a straight line.

   - Each mouse and hole has a position (integer on the line).
   - Each mouse can move at the same speed.
   - Each hole can hold only one mouse.

   Goal → Assign mice to holes so that the **maximum distance**
           any mouse travels is **as small as possible**.

---------------------------------------------------------------
2. HOW THE CODE WORKS:
---------------------------------------------------------------
   → Sort both the mice and hole positions in increasing order.
   → Match the i-th mouse with the i-th hole.
   → Calculate the absolute distance for each pair.
   → Track the maximum distance among all pairs.
   → The result (maximum distance) = minimum time for all mice to hide.

---------------------------------------------------------------
3. EXAMPLE:
---------------------------------------------------------------
   Input:
       n = 3
       Mice positions: 4  -4   2
       Hole positions: 4   0   5

   After sorting:
       Mice: -4, 2, 4
       Holes: 0, 4, 5

   Pairing:
       Mouse at -4 → Hole at 0  → Distance = 4
       Mouse at 2  → Hole at 4  → Distance = 2
       Mouse at 4  → Hole at 5  → Distance = 1

   Maximum distance = 4 ✅

---------------------------------------------------------------
4. OUTPUT:
---------------------------------------------------------------
   Minimum time (maximum distance) = 4

---------------------------------------------------------------
5. COMPLEXITY:
---------------------------------------------------------------
   Time complexity: O(n log n)  → due to sorting
   Space complexity: O(1)       → in-place sorting

===============================================================
*/
