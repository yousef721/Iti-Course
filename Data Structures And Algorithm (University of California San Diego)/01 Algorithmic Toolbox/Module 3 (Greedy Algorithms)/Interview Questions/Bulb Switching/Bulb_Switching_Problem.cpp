#include <iostream>
#include <vector>

using namespace std;

// Function to find minimum number of switches to turn on all bulbs
int minSwitchesToTurnOn(vector<int> bulbs)
{
    int switchesPressed = 0;     // Total number of switch presses
    bool switchesStatus = false; // Tracks whether the effect of previous flips is active

    // STEP 1: Go through bulbs from left to right
    for (int i = 0; i < bulbs.size(); i++)
    {
        // STEP 2: Decide if we need to press the switch
        if (bulbs[i] == 0 && !switchesStatus)
        {
            // Bulb is off and no previous flips affecting it → press switch
            switchesPressed++;
            switchesStatus = true; // Now flips affect the following bulbs
        } 
        else if (bulbs[i] == 1 && switchesStatus)
        {
            // Bulb is on but previous flips have affected it → press switch
            switchesPressed++;
            switchesStatus = false; // Reset flips effect
        }
    }

    // STEP 3: Return total minimum switch presses
    return switchesPressed;
}

int main() {
    int n;
    cin >> n; // Number of bulbs

    vector<int> bulbs(n);

    // Read input: 0 = off, 1 = on
    for (int i = 0; i < n; i++) {
        cin >> bulbs[i];
    }

    // Compute minimum number of switches to press
    int result = minSwitchesToTurnOn(bulbs);

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
    We have 'n' bulbs in a line.
    0 = off, 1 = on.
    Each bulb's switch flips its state and all bulbs to the right.
    Goal → Turn all bulbs on (1) with the minimum number of switch presses.

---------------------------------------------------------------
2. HOW THE CODE WORKS:
---------------------------------------------------------------
    → Initialize switchesPressed = 0 and switchesStatus = false
    → For each bulb from left to right:
        1. If bulb is off and previous flips do not affect it → press switch
            - switchesPressed++
            - switchesStatus = true
        2. If bulb is on but previous flips affect it → press switch
            - switchesPressed++
            - switchesStatus = false
    → Return switchesPressed as minimum number of switches

---------------------------------------------------------------
3. EXAMPLE:
---------------------------------------------------------------
    Input:
    4
    0 1 0 1

    Step-by-step:
    - Bulb 1: 0 → press → switchesStatus = true → switchesPressed = 1
    - Bulb 2: 1 (flipped by previous switch) → press → switchesStatus = false → switchesPressed = 2
    - Bulb 3: 0 → press → switchesStatus = true → switchesPressed = 3
    - Bulb 4: 1 (flipped by previous switch) → press → switchesStatus = false → switchesPressed = 4

    Output: 4

---------------------------------------------------------------
4. OUTPUT:
---------------------------------------------------------------
    Minimum number of switches to turn on all bulbs = 4

---------------------------------------------------------------
5. COMPLEXITY:
---------------------------------------------------------------
    Time complexity: O(n)  → one pass through the bulbs
    Space complexity: O(1)
    
===============================================================
*/
