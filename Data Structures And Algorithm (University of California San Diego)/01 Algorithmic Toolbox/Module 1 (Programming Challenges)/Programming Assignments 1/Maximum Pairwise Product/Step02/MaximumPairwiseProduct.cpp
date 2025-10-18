#include <iostream>
#include <vector>

long long MaxPairwisePro(const std::vector<int> &n) {
    long long result = 0;
    for (int i = 0; i < n.size(); i++)
    {
        for (int j = i + 1; j < n.size(); j++)
        {
            if(((long long)n[i]) * n[j] > result)
            {
                result = ((long long)n[i]) * n[j];
            }
        }
    }
    return result;
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
    Failed case #4/18: time limit exceeded (Time used: 2.99/1.10, memory used: 24875008/536870912.)

    Explanation:
    - This algorithm becomes too slow when working with very large datasets.
    - The maximum input size for this problem is around 10⁵ (100,000 numbers).
    - The algorithm checks *all possible pairs* of numbers (using two nested loops).
    - That means it performs roughly n² operations.
    - When n = 10⁵, the total number of operations is about 10¹⁰ (10 billion).
    - Modern computers can only perform around 10⁹ (1 billion) basic operations per second.
    - Therefore, this algorithm exceeds the time limit for large inputs.

    Solution:
    - We don’t actually need to compare every pair to find the maximum product.
    - The maximum pairwise product is always formed by the (two largest numbers) in the sequence.
    - So we can design a faster algorithm that finds the two largest numbers.

    See next step -> (Step03)

*/ 