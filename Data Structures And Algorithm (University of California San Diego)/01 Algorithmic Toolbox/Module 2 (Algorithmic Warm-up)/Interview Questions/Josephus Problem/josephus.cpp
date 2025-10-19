#include <iostream>  

// Function to find the position of the last survivor (Josephus position)
int Josephus(int n, int k)
{
    // Base case:
    // If only one person is left, the survivor’s position is 0
    if (n == 1) return 0;

    // Recursive formula:
    // Josephus(n, k) = (Josephus(n - 1, k) + k) % n
    //
    // This means:
    // - Find the survivor position when there are (n-1) people
    // - Then shift it by k positions (since every k-th person is killed)
    // - Use modulo n to wrap around the circle correctly
    return (Josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;  // n = number of people, k = step size (every k-th person dies)

    // Read inputs from the user
    std::cin >> n;
    std::cin >> k;

    // Print the final survivor position (starting from index 0)
    std::cout << "The survivor is at position: " << Josephus(n, k) << '\n';

    return 0;
}

/*
---------------------------------------------
--Example:

Input:
7 3

Step-by-step elimination:
People: 0 1 2 3 4 5 6
1) Count 3 → person 2 is killed
Remaining: 0 1 3 4 5 6
2) Count 3 → person 5 is killed
Remaining: 0 1 3 4 6
3) Count 3 → person 1 is killed
Remaining: 0 3 4 6
4) Count 3 → person 6 is killed
Remaining: 0 3 4
5) Count 3 → person 4 is killed
Remaining: 0 3
6) Count 3 → person 0 is killed
--> Survivor = person 3

Output:
The survivor is at position: 3
---------------------------------------------
*/
