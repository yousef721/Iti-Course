#include <iostream>
#include <cstdlib>
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

long long MaxPairwiseProFast(const std::vector<int> &n) {
    
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

    while (true)
    {
        int length = (rand() % 10 + 2);
        std::vector<int> arr;
        for (int i = 0; i < length; i++)
        {
            arr.push_back(rand() % 100000);
        }
        for (int i = 0; i < length; i++)
        {
            std::cout << arr[i] << " ";
        }

        std::cout << std::endl;

        long long r1 = MaxPairwisePro(arr);
        long long r2 = MaxPairwiseProFast(arr);
        if (r1 != r2)
        {  
            std::cout << "Wrong answer R1: " << r1 << "  R2: " << r2 << std::endl;
            break;
        } else
        {
            std::cout << "OK" << std::endl;
        }
    }
    
    int length;
    std::cin >> length;
    std::vector<int> numbers(length);
    for (int i = 0; i < length; i++)
    {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProFast(numbers);
    std::cout << result << "\n";
    return 0;
}

/*
    Explanation of the wrong part:

    In the function `MaxPairwiseProFast`:
        The problem is in this line:
        ------------------------------------------------------
        if (n[i] != n[indexMax_1] && (indexMax_2 == -1 || n[i] > n[indexMax_2]))
        ------------------------------------------------------
        Here, you are checking if the *value* of n[i] is different from n[indexMax_1].
        But the goal is to make sure we are not using the *same index* twice.
        So if the array has duplicate maximum values (for example: [9, 9, 1]),
        the second maximum (the second 9) will be skipped because they are equal in value.
        As a result, the code picks a smaller number (like 1 or 3) as the second max,
        giving a wrong result.

    The correct condition should be:
        ------------------------------------------------------
        if (i != indexMax_1 && (indexMax_2 == -1 || n[i] > n[indexMax_2]))
        ------------------------------------------------------
        This ensures that we only skip the same index, not equal values.
*/ 