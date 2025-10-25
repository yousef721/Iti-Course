#include <iostream>
#include <vector>

using std::vector;

// Structure to represent a segment with a start and end point
struct Segment {
    int start, end;
};

// Function to find the minimum number of points that cover all segments
vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points; // to store chosen points

    // Keep looping until all segments are covered (removed)
    while (!segments.empty())
    {    
        // Step 1: Find the segment with the smallest 'end' value
        int smallestL = segments[0].end;
        for (int i = 0; i < segments.size(); i++)
        {
            if (segments[i].end < smallestL)
            {
                smallestL = segments[i].end;
            }
        }

        // Step 2: Find all segments that are covered by this point (smallestL)
        vector<int> deletedItems;
        for (int i = 0; i < segments.size(); i++)
        {
            // If this point lies within the segment, mark it for deletion
            if(smallestL >= segments[i].start)
            {
                deletedItems.push_back(i);
            }
        }

        // Step 3: Remove all covered segments (from end to start to avoid shifting)
        for (int i = deletedItems.size() - 1; i >= 0; i--)
        {
            segments.erase(segments.begin() + deletedItems[i]);
        }

        // Step 4: Add this point to the result
        points.push_back(smallestL);
    }

    return points; // return all chosen points
}

int main() {
    int n;
    std::cin >> n; // number of segments
    vector<Segment> segments(n);

    // Input all segments
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }

    // Call the function to compute the optimal points
    vector<int> points = optimal_points(segments);

    // Output the result: number of points and the points themselves
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}

/*
===============================================================
                PROGRAM EXPLANATION — STEP BY STEP
===============================================================

1. PROBLEM GOAL:
---------------------------------------------------------------
   You are given 'n' line segments, each defined by:
        start[i] → the beginning of the segment
        end[i]   → the end of the segment

   You need to find the **minimum number of points**
   such that each segment contains at least one of these points.

   Example:
       Segments: [1,3], [2,5], [3,6]
       The minimum points that cover all = [3]
---------------------------------------------------------------


2. HOW THE CODE WORKS:
---------------------------------------------------------------
   → The program repeats the following steps until all
     segments are covered (removed):

     Step  1: Find the segment that ends first
               (smallest end value).

     Step  2: Take that end point as a chosen "point"
               — because it can cover as many segments
                 as possible that start before or at it.

     Step  3: Remove all segments that are already
               covered by this chosen point.

     Step  4: Add this point to the result list
               and repeat until no segments remain.


3. DETAILED WALKTHROUGH:
---------------------------------------------------------------
   Input:
       n = 3
       Segments:
         [1, 3]
         [2, 5]
         [3, 6]

   Iteration 1:
     - Smallest end = 3  → choose point = 3
     - Segments covered by 3: [1,3], [2,5], [3,6]
     - Remove all covered segments
     - Remaining segments: none
     - Result = [3]

   Output:
       1
       3

   ✅ The point “3” covers all segments efficiently.


4. WHY THIS WORKS (GREEDY STRATEGY):
---------------------------------------------------------------
   Choosing the segment with the smallest end ensures that:
     - You always pick the optimal earliest point
     - You cover as many intervals as possible in each step
     - You never miss a better future option


5. COMPLEXITY:
---------------------------------------------------------------
   Time complexity:  O(n²)
       (Because for each chosen point, you scan all remaining segments)

   Space complexity: O(n)
       (Vectors to store segments and results)

===============================================================
*/

