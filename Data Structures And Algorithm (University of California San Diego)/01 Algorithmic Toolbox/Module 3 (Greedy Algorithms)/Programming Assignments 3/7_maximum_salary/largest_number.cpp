#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

// =======================================================
//  Helper Function: isBetter
// -------------------------------------------------------
//  This function compares two numbers (as strings) to see
//  which one should come first to form the largest number.
//
//  Example:
//      x = "9", y = "34"
//      Compare: "934" vs "349"
//      → "934" is larger ⇒ "9" should come before "34"
// =======================================================
bool isBetter(const string& x, const string& y) {
    return x + y > y + x;  // Return true if x should come before y
}

// =======================================================
//  Main Function: largest_number
// -------------------------------------------------------
//  Builds the largest number possible by concatenating
//  the given integers in the best order.
// =======================================================
string largest_number(vector<string> a) {
    string result = "";

    // Keep looping until all elements are used
    while (!a.empty()) {

        int bestIndex = 0; // Assume first element is the best at the start

        // Find the "best" element in the remaining list.
        // Compare each element with the current best using isBetter().
        for (int i = 1; i < a.size(); i++) {
            if (isBetter(a[i], a[bestIndex])) {
                bestIndex = i; // Update bestIndex if we find a better number
            }
        }

        // Add the best element to the result string
        result += a[bestIndex];

        // Remove that element from the list so it won't be used again
        a.erase(a.begin() + bestIndex);
    }

    // Handle special case: if all numbers are zero
    // (e.g., input = 0 0 0 → output should be "0", not "000")
    if (result[0] == '0')
        return "0";

    // Return the final largest concatenated number
    return result;
}

int main() {
  int n;
  std::cin >> n; // Read number of elements
  vector<string> a(n);

  // Read all numbers as strings (important to keep leading zeros if any)
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  // Print the largest possible number
  std::cout << largest_number(a);
}

/*
===============================================================
                PROGRAM EXPLANATION — STEP BY STEP
===============================================================

1. GOAL:
---------------------------------------------------------------
   Given n integers, arrange them so that their concatenation
   forms the largest possible number.

2. IDEA:
---------------------------------------------------------------
   Instead of sorting numerically, we compare which order of
   concatenation gives a larger result:
      x before y  →  x + y
      y before x  →  y + x
   If (x + y) > (y + x), x should come first.

3. PROCESS:
---------------------------------------------------------------
   • Keep choosing the "best" number that gives the largest prefix.
   • Append it to the result string.
   • Remove it from the list.
   • Repeat until the list is empty.

4. EXAMPLE:
---------------------------------------------------------------
   Input:  3 30 34 5 9

   Step 1 → compare all → pick "9"
   Step 2 → remaining: [3, 30, 34, 5] → pick "5"
   Step 3 → remaining: [3, 30, 34] → pick "34"
   Step 4 → remaining: [3, 30] → pick "3"
   Step 5 → remaining: [30] → pick "30"

   Result = "9534330"

5. COMPLEXITY:
---------------------------------------------------------------
   Time:  O(n² × k)   (k = avg length of strings)
   Space: O(n)         (for storing result + vector copy)

===============================================================
*/
