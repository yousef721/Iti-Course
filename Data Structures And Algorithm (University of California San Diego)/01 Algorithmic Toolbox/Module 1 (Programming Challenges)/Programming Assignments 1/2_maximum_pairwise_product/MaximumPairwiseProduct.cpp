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
        if (i != indexMax_1 && (indexMax_2 == -1 || n[i] > n[indexMax_2]))
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
    Good job! (Max time used: 0.04/1.10, max memory used: 26587136/536870912.)
*/