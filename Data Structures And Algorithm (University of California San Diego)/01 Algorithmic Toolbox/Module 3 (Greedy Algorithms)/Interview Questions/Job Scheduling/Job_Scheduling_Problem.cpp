#include <iostream>
#include <vector>

using std::vector;

// Structure to represent each job
// Each job has a deadline (time limit) and a profit (reward if done before the deadline)
struct JobsScheduling
{
    int deadline, profit;
};

// Function to calculate the maximum total profit
long long largest_Profit(vector<JobsScheduling> JobsScheduling) {

    long long result = 0; // Stores total profit

    // STEP 1: Find the maximum deadline among all jobs
    int NumberOfSlots = 0;
    for (int i = 0; i < JobsScheduling.size(); i++)
    {
        if (JobsScheduling[i].deadline > NumberOfSlots)
        {
            NumberOfSlots = JobsScheduling[i].deadline;
        }
    }

    // STEP 2: Create a time slot array to represent available time slots
    // 0 = free slot, 1 = occupied
    vector<int> slots(NumberOfSlots, 0);
        
    // STEP 3: Schedule jobs one by one until all are processed
    while (!JobsScheduling.empty())
    {
        // Find the job with the highest profit
        int bestProfit = JobsScheduling[0].profit;
        int m = 0;
        for (int i = 0; i < JobsScheduling.size(); i++)
        {
            if (JobsScheduling[i].profit > bestProfit)
            {
                bestProfit = JobsScheduling[i].profit;
                m = i; // store index of job with maximum profit
            }
        }
        
        // STEP 4: Try to schedule this job in the latest available slot
        // If the deadline is 3, try to place it in slot 3, then 2, then 1
        for (int i = slots.size() - 1; i >= 0; i--)
        {
            // Check if this slot is within the job’s deadline and free
            if (JobsScheduling[m].deadline >= (i + 1) && slots[i] == 0)
            {
                slots[i] = 1;                // mark this slot as occupied
                result += JobsScheduling[m].profit; // add profit to total
                break;                       // move to next job
            }
        }

        // STEP 5: Remove the scheduled job from the list
        JobsScheduling.erase(JobsScheduling.begin() + m);
    }
    
    // STEP 6: Return the maximum profit achieved
    return result;
}

int main() {
    int n;
    std::cin >> n; // number of jobs

    vector<JobsScheduling> Jobs(n);

    // Read input: each job has (deadline, profit)
    for (size_t i = 0; i < Jobs.size(); i++) {
        std::cin >> Jobs[i].deadline >> Jobs[i].profit;
    }

    // Print the result — maximum total profit
    std::cout << largest_Profit(Jobs) << std::endl;
    return 0;
}

/*
===============================================================
                PROGRAM EXPLANATION — STEP BY STEP
===============================================================

1. PROBLEM GOAL:
---------------------------------------------------------------
   We have 'n' jobs, each with:
     - deadline: the time before which it must be completed
     - profit: the reward for finishing it on time

   Each job takes one time unit, and only one job can be done at a time.

   Goal → Schedule jobs to maximize total profit.

---------------------------------------------------------------
2. HOW THE CODE WORKS:
---------------------------------------------------------------
   → Find the latest possible deadline to know how many time slots we have.
   → Repeatedly pick the job with the highest profit.
   → Schedule it in the latest available slot before its deadline.
   → Mark the slot as used.
   → Add its profit to the total.
   → Remove that job from the list.
   → Repeat until all jobs are checked.

---------------------------------------------------------------
3. EXAMPLE:
---------------------------------------------------------------
   Input:
       n = 5
       (deadline, profit)
       2 100
       1 19
       2 27
       1 25
       3 15

   Step-by-step:
   - Job with 100 profit → put in slot 2 → total = 100
   - Job with 27 profit → slot 1 free → total = 127
   - Job with 25 profit → slot 1 full → skip
   - Job with 19 profit → slot 1 full → skip
   - Job with 15 profit → slot 3 free → total = 142 ✅

---------------------------------------------------------------
4. OUTPUT:
---------------------------------------------------------------
   Maximum total profit = 142

---------------------------------------------------------------
5. COMPLEXITY:
---------------------------------------------------------------
   Time complexity: O(n²)
   Space complexity: O(n)

===============================================================
*/
