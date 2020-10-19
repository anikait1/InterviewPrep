#include <iostream>
#include <vector>
#include <array>
#include <limits>
#include <algorithm>
#include <set>

// [-4, 1, 3, 2, 5, 6, 4]
// min = 1
// [1, 2, 3, 4, 5, 6]

int findSmallestPositiveNumber(std::vector<int> &nums) {
  std::array<bool, 301> elements{};
  int minPositive = std::numeric_limits<int>::max();

  for (auto num : nums) {
    if (num > 0 && num < 301) {
      elements[num] = true;
    }

    if (num > 0 && num < minPositive) {
      minPositive = num;
    }
  }

  if (minPositive != 1) { return 1; }

  for (int i = 1; i < (int)elements.size(); ++i) {
    if (elements[i] != true) {
      return i;
    }
  }

  return minPositive;
}

void display(const std::vector<int> &nums) {
  std::cout << "[ ";
  for (const auto &num : nums) {
    std::cout << num << ' ';
  }
  std::cout << "]\n";
}

int main() {
  std::vector<int> nums{1, 2, 0};
  std::cout << findSmallestPositiveNumber(nums) << '\n';
  display(nums);

  return 0;
}