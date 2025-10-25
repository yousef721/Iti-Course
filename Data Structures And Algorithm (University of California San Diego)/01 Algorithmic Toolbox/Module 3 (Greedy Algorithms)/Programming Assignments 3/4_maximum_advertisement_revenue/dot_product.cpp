#include <iostream>
#include <vector>

using std::vector;

// -------------------------------------------------------------
// Function: max_dot_product
// Purpose : Compute the maximum dot product of two sequences
// -------------------------------------------------------------
long long max_dot_product(vector<int> a, vector<int> b) {
    // Base case: if one of the sequences is empty → no more multiplication possible
    if (a.empty() || b.empty())
    {
        return 0;
    }
    
    // Step 1: Find the maximum element in vector a (most clicks)
    int mostClick = 0;
    int indexClick = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > mostClick)
        {
            mostClick = a[i];
            indexClick = i;
        }
    }

    // Step 2: Find the maximum element in vector b (best price)
    int bestPrice = 0; 
    int indexPrice = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] > bestPrice)
        {
            bestPrice = b[i];
            indexPrice = i;
        }
    }

    // Step 3: Multiply the best (max click × max price)
    long long result = (long long)mostClick * bestPrice;

    // Step 4: Remove these used elements from both vectors
    a.erase(a.begin() + indexClick);
    b.erase(b.begin() + indexPrice);

    // Step 5: Repeat recursively for the remaining elements
    return result + max_dot_product(a,b);
}

// -------------------------------------------------------------
// Main Function
// -------------------------------------------------------------
int main() {
  size_t n;
  std::cin >> n;  // number of elements
  vector<int> a(n), b(n);

  // Read clicks array
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  // Read prices array
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  // Compute and print the maximum dot product
  std::cout << max_dot_product(a, b) << std::endl;
}



/*
===============================================================
                PROGRAM EXPLANATION — STEP BY STEP
===============================================================

1. PROBLEM GOAL:
---------------------------------------------------------------
   You are given two integer sequences:
     - a[i] = number of clicks expected for each ad slot
     - b[i] = price per click offered by advertisers

   You need to pair them in such a way that maximizes:
       (a1×b1) + (a2×b2) + ... + (an×bn)

---------------------------------------------------------------
2. HOW THE CODE WORKS:
---------------------------------------------------------------
   → The function picks the largest element in each list
     (the one that gives the highest product).

   → It multiplies them together (max click × max price),
     adds the result, removes them from the lists,
     and repeats recursively until no elements remain.

---------------------------------------------------------------
3. EXAMPLE:
---------------------------------------------------------------
   Input:
       n = 3
       a = [1, 3, 5]
       b = [2, 4, 6]

   Step 1 → pick max(5) and max(6)
             product = 5×6 = 30

   Step 2 → remove them:
             a = [1,3], b = [2,4]

   Step 3 → pick max(3) and max(4)
             product = 3×4 = 12

   Step 4 → pick max(1) and max(2)
             product = 2

   Total = 30 + 12 + 2 = 44 ✅

---------------------------------------------------------------
5. COMPLEXITY:
---------------------------------------------------------------
   Time complexity: O(n²) due to searching max each time
   Space complexity: O(n) (recursive stack + vectors)

===============================================================
*/
