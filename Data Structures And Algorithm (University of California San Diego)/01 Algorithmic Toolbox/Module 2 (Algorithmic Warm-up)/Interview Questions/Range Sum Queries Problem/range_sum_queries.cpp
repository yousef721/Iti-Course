#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Enter the length of the array: ";
    std::cin >> n;

    // Step 1: Create the array and take input from the user
    std::vector<int> arr(n);
    std::cout << "\nEnter elements of the array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "  Element " << i << ": ";
        std::cin >> arr[i];
    }

    // Step 2: Build the prefix sum array
    // prefix[i] stores the sum of elements from arr[0] to arr[i]
    std::vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Step 3: Read the range indices from the user
    int l, r;
    std::cout << "\nEnter the range indices (inclusive):\n";
    std::cout << "  From index l = ";
    std::cin >> l;
    std::cout << "  To index r = ";
    std::cin >> r;

    // Step 4: Validate the input range
    if (l < 0 || r >= n || l > r) {
        std::cout << "\nInvalid range. Please make sure 0 ≤ l ≤ r < " << n << ".\n";
        return 1;
    }

    // Step 5: Calculate the sum of the given range using prefix sum
    int result = (l == 0) ? prefix[r] : prefix[r] - prefix[l - 1];

    // Step 6: Print the result
    std::cout << "\nSum of range [" << l << ", " << r << "] = " << result << '\n';

    return 0;
}
