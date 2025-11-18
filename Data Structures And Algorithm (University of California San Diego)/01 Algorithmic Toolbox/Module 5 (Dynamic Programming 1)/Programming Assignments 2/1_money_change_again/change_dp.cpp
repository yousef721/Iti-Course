#include <iostream>
#include <vector>
#include <algorithm>

int get_change(int m) {
    std::vector<int> coins = {1, 3, 4};
    std::vector<int> minCoins(m + 1, 10000);
    minCoins[0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int coin : coins) {
            if (i >= coin) {
                minCoins[i] = std::min(minCoins[i], minCoins[i - coin] + 1);
            }
        }
    }

    return minCoins[m];
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
    return 0;
}
