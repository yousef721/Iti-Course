#include <iostream>
#include <vector>

long long MaxPairwisePro(const std::vector<int> &n) {
    
    int indexMax_1 = -1;
    for (int i = 0; i < n.size(); i++)
    {
        if (indexMax_1 == -1 || n[i] > n[indexMax_1])
        {
            indexMax_1 = i;
        }
    }

    int indexMax_2 = -1;
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] != n[indexMax_1] && (indexMax_2 == -1 || n[i] > n[indexMax_2]))
        {
            indexMax_2 = i;
        }
    }

    return ((long long)(n[indexMax_1])) * n[indexMax_2];
}

int main() {
    int length;
    std::cin >> length;
    std::vector<int> numbers(length);
    for (int i = 0; i < length; i++)
    {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwisePro(numbers);
    std::cout << result << "\n";
    return 0;
}

/*
    Failed case #5/18: Wrong answer (Time used: 0.02/1.10, memory used: 23580672/536870912.)

    Explanation:
    - The lab doesn't explain the reason.
    - we'll try to find out the reason with a stress test.
*/