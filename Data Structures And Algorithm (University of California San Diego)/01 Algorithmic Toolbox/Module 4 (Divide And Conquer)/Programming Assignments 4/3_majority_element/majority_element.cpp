#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left]; 

  int mid = left + (right - left) / 2;

  int left_major = get_majority_element(a, left, mid);
  int right_major = get_majority_element(a, mid, right);

  if (left_major == right_major) return left_major; 

  int left_count = 0;
  int right_count = 0;
  for (int i = left; i < right; i++) {
    if (a[i] == left_major) left_count++;
    if (a[i] == right_major) right_count++;
  }

  int half = (right - left) / 2;
  if (left_count > half) return left_major;
  if (right_count > half) return right_major;
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) std::cin >> a[i];
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
