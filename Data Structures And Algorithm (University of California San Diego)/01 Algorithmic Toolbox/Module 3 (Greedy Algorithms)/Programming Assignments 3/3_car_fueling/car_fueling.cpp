#include <iostream>
#include <vector>

using namespace std;

// -------------------------------------------------------------
// Function: compute_min_refills
// Purpose : Find minimum number of refills needed to reach 'dist'
// -------------------------------------------------------------
int compute_min_refills(int dist, int tank, vector<int> &stops) {
    // Add starting point (0) and destination (dist)
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);

    int numRefills = 0;     // number of refills
    int currentPos = 0;     // current station index

    // Move until we reach the destination
    while (currentPos < stops.size() - 1) {
        int lastPos = currentPos;

        // Move forward as far as we can with current fuel
        while (currentPos < stops.size() - 1 && stops[currentPos + 1] - stops[lastPos] <= tank) {
            currentPos++;
        }

        // If we didn't move → next stop is too far → impossible
        if (currentPos == lastPos)
            return -1;

        // If we haven't reached destination yet, refill here
        if (currentPos < stops.size() - 1)
            numRefills++;
    }

    return numRefills;
}

// -------------------------------------------------------------
// Main Function
// -------------------------------------------------------------
int main() {
    int d, m, n;
    cin >> d >> m >> n;

    vector<int> stops(n);
    for (int i = 0; i < n; ++i)
        cin >> stops[i];

    cout << compute_min_refills(d, m, stops) << endl;

    return 0;
}

/*
===============================================================
            PROGRAM EXPLANATION — STEP BY STEP
===============================================================

1. PROBLEM DEFINITION:
---------------------------------------------------------------
You are given:
  • Total distance `d` between two cities.
  • A car that can travel at most `m` miles on a full tank.
  • A sequence of gas stations (stops) along the way.

Goal:
  → Find the **minimum number of refills** needed to reach the
    destination, or print -1 if it’s not possible.

Example:
  Input:
      d = 950
      m = 400
      n = 4
      stops = [200, 375, 550, 750]

  Output:
      2  ✅
  (Refuel at 375 and 750 miles)

---------------------------------------------------------------
2. GREEDY ALGORITHM IDEA:
---------------------------------------------------------------
At each step, drive as far as possible with the current fuel.
When you cannot reach the next station, **refuel at the farthest
reachable one**.

This greedy choice ensures the minimum number of stops.

---------------------------------------------------------------
3. STEP-BY-STEP LOGIC:
---------------------------------------------------------------
1️⃣ Add starting point (0) and destination (d) to the list:
    stops = [0, 200, 375, 550, 750, 950]

2️⃣ Initialize:
    num_refills = 0
    currentPos = 0  (we start at 0)

3️⃣ While we haven't reached the destination:
    - Save current position (lastPos)
    - Move forward while next stop is within the fuel range
      (stops[currentPos + 1] - stops[lastPos] <= tank)
    - If we didn’t move → next stop is too far → return -1
    - If not yet at destination → refill here (num_refills++)

---------------------------------------------------------------
4. WALKTHROUGH EXAMPLE:
---------------------------------------------------------------
Input:
    d = 950, m = 400, stops = [200, 375, 550, 750]

Extended stops:
    [0, 200, 375, 550, 750, 950]

Step 1:
    Start = 0 → we can reach 200, 375, but not 550
    → Refill at 375
    num_refills = 1

Step 2:
    From 375 → we can reach 550, 750, but not 950
    → Refill at 750
    num_refills = 2

Step 3:
    From 750 → reach 950 (destination)
    ✅ Done.

Output: 2 refills

---------------------------------------------------------------
5. EDGE CASES:
---------------------------------------------------------------
✔️ If `dist` ≤ `tank` → no refills needed → output 0  
✔️ If a gap between stations > `tank` → impossible → output -1  
✔️ Works with any valid sequence of stations (increasing order).

---------------------------------------------------------------
6. COMPLEXITY ANALYSIS:
---------------------------------------------------------------
• Time Complexity  →  O(n)
  (Each stop is visited at most once)
• Space Complexity →  O(1)
  (Only a few variables used)

---------------------------------------------------------------
7. SUMMARY:
---------------------------------------------------------------
Algorithm Type : Greedy  
Approach       : Always drive as far as possible, then refill.  
Output         : Minimum refills, or -1 if impossible.  
Correctness    : Proven optimal for this problem.

===============================================================
*/
