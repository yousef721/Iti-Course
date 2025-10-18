#include <iostream>
#include <vector>

int MaxPairwisePro(const std::vector<int> &n) {
    int result = 0;
    for (int i = 0; i < n.size(); i++)
    {
        for (int j = i + 1; j < n.size(); j++)
        {
            if(((int)n[i]) * n[j] > result)
            {
                result = ((int)n[i]) * n[j];
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

    int result = MaxPairwisePro(numbers);
    std::cout << result << "\n";
    return 0;
}

/*
    Failed case #3/18: (Wrong answer)

    Input:
    2
    100000 90000

    Your output:
    410065408

    Correct output:
    9000000000
    (Time used: 0.00/1.10, memory used: 24920064/536870912.)

    Explanation:
    - The multiplication (100000 * 90000 = 9,000,000,000) is larger than what 'int' can store.
    - In C++, 'int' can only hold values up to about 2,147,483,647.
    - When the result exceeds this limit, it causes an integer overflow.
    - Overflow makes the value wrap around to an incorrect smaller number.
    - That’s why the program printed 410065408 instead of 9000000000.
    - To fix this, use 'long long' for 'result' and the multiplication.

    Solution in next step -> (Step02)
*/