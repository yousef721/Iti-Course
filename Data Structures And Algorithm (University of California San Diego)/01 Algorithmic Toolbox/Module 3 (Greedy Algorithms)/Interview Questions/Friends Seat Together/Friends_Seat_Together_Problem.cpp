#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find minimal moves to seat all friends together
int minMovesToSeatTogether(vector<int> seats) {
    int k = seats.size();

    // STEP 1: Sort the seats in ascending order
    sort(seats.begin(), seats.end());

    // STEP 2: Compute "shifted positions" to simplify calculation
    // shifted[i] = seats[i] - i
    // This transforms the problem to aligning friends around the median
    vector<int> shifted(k);
    for (int i = 0; i < k; i++) {
        shifted[i] = seats[i] - i;
    }

    // STEP 3: Find median of shifted array
    int median = shifted[k / 2];

    // STEP 4: Calculate total moves needed
    int moves = 0;
    for (int i = 0; i < k; i++) {
        moves += abs(shifted[i] - median);
    }

    return moves;
}


int main() {
    int k;
    cin >> k; // Number of friends

    vector<int> seats(k);

    // Read input: positions of friends in the row
    for (int i = 0; i < k; i++) {
        cin >> seats[i];
    }

    // Compute minimal moves
    int result = minMovesToSeatTogether(seats);

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
    We have 'k' friends sitting in a row at positions given in the array 'seats'.
    Goal → Move friends to sit together in k consecutive seats with minimum moves.
    Each move = friend moves one seat left or right.

2. HOW THE CODE WORKS:
---------------------------------------------------------------
    → Step 1: Sort the seat positions
    → Step 2: Compute "shifted" positions:
        shifted[i] = seats[i] - i
        This converts problem to aligning friends around a single point
    → Step 3: Find the median of shifted positions
    → Step 4: Total moves = sum of |shifted[i] - median| for all i
    → Step 5: Return total moves

3. EXAMPLE:
---------------------------------------------------------------
    Input:
    3
    1 5 9

    Step-by-step:
    - Sort seats: [1, 5, 9]
    - Shifted: [1-0, 5-1, 9-2] = [1, 4, 7]
    - Median of shifted = 4
    - Moves:
        |1-4| + |4-4| + |7-4| = 3 + 0 + 3 = 6
    Output: 6

4. OUTPUT:
---------------------------------------------------------------
    Minimum number of moves to seat all friends together = 6

5. COMPLEXITY:
---------------------------------------------------------------
    Time complexity: O(k log k) → due to sorting
    Space complexity: O(k) → storing shifted array

===============================================================
*/
