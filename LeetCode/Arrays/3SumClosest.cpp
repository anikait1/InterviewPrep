#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

template <typename T>
void display(const std::vector<T> &vec) {
  std::cout << "[ ";
  for (const auto &val : vec) {
    std::cout << val << ' ';
  }
  std::cout << "]\n";
}

int threeSumClosest(std::vector<int> &vec, int target) {
  std::sort(vec.begin(), vec.end());
  int diff = std::numeric_limits<int>::max();
  int size = vec.size();

  for (int i = 0; i < size; ++i) {
    int lo = i + 1;
    int hi = size - 1;

    while (lo < hi) {
      int sum = vec[i] + vec[lo] + vec[hi];

      if (std::abs(target - sum) < std::abs(diff)) {
        diff = target - sum;
      }

      if (sum < target) {
        lo += 1;
      } else {
        hi -= 1;
      }
    }
  }

  return target - diff;
}

int main() {
  std::vector<int> vec{-1, 2, 1, -4};

  std::cout << threeSumClosest(vec, 1) << '\n';

  return 0;
}
