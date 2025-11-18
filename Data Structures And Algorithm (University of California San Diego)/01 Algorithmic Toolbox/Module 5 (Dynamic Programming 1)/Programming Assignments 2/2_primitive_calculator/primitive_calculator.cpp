#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
    std::vector<int> minOps(n + 1);
    std::vector<int> prev(n + 1); 

    minOps[1] = 0;
    for (int i = 2; i <= n; i++) {
        minOps[i] = minOps[i - 1] + 1;
        prev[i] = i - 1;

        if (i % 2 == 0 && minOps[i / 2] + 1 < minOps[i]) {
            minOps[i] = minOps[i / 2] + 1;
            prev[i] = i / 2;
        }

        if (i % 3 == 0 && minOps[i / 3] + 1 < minOps[i]) {
            minOps[i] = minOps[i / 3] + 1;
            prev[i] = i / 3;
        }
    }

    vector<int> sequence;
    for (int i = n; i >= 1; i = prev[i]) {
        sequence.push_back(i);
        if (i == 1) break;
    }

    std::reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    return 0;
}
