#include <iostream>
#include <cassert>

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    // write your code here
    int arrFibonacci[n];
    arrFibonacci[0] = 0;
    arrFibonacci[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arrFibonacci[i] = arrFibonacci[i - 1] + arrFibonacci[i - 2];
    }
    return arrFibonacci[n];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;

    // std::cout << fibonacci_naive(n) << '\n';
    // test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}


/*
--------------------------------------------
-- Explanation of the Fibonacci Program
--------------------------------------------
The goal is to compute the nth Fibonacci number:
F(0) = 0, F(1) = 1, and F(n) = F(n−1) + F(n−2)

This program shows two methods:
1️) Naive recursive method
2️) Fast iterative method

--------------------------------------------
-- 1. Naive Method (fibonacci_naive)
--------------------------------------------
- Uses recursion directly based on the definition:
    F(n) = F(n−1) + F(n−2)
- Recomputes many values multiple times.
- Very slow for large n (e.g., n = 40 takes several seconds).

Example:
  F(5) = F(4) + F(3)
  F(4) = F(3) + F(2)
  Notice F(3) is calculated twice → redundant work

⏱ Time Complexity:  O(2^n)
💾 Space Complexity: O(n)  (due to recursive call stack)

--------------------------------------------
-- 2. Fast Method (fibonacci_fast)
--------------------------------------------
- Uses iteration and stores results in an array.
- Each Fibonacci number is computed once using:
    F[i] = F[i−1] + F[i−2]
- Much more efficient and avoids redundant calculations.

Example:
  For n = 10:
  F(0)=0, F(1)=1, F(2)=1, F(3)=2, F(4)=3, ..., F(10)=55

⏱ Time Complexity:  O(n)
💾 Space Complexity: O(n)

--------------------------------------------
-- 3. Test Function (test_solution)
--------------------------------------------
- Uses assert() to automatically verify that
  fibonacci_fast() matches fibonacci_naive()
  for small test cases (0 ≤ n < 20).
- If any result is incorrect, the program stops.

--------------------------------------------
-- 4. Main Function
--------------------------------------------
- Reads the input number n from the user.
- Optionally test the naive version for small n.
- Finally prints the result of fibonacci_fast(),
  which works efficiently even for large inputs.

--------------------------------------------
-- Example
--------------------------------------------
Input:  10
Output: 55

--------------------------------------------
-- Summary of Efficiency
--------------------------------------------
| Method            | Time Complexity | Space Complexity | Speed        |
|-------------------|-----------------|------------------|--------------|
| Naive Recursive   | O(2^n)          | O(n)             | Very slow    |
| Iterative (Fast)  | O(n)            | O(n)             | Very fast ✅ |
--------------------------------------------
*/
