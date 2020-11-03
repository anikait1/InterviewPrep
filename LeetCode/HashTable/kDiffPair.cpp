#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

// [3, 1, 4, 1, 5], k = 2
// [1, 1, 3, 4, 5]
// [1, 2, 3, 4, 5] k = 1 ([1, 2], [2, 3], [3, 4], [4, 5])
// [0, 1, 2, 2, 3, 3, 3, 4, 4, 9] k = 3, ([0, 3], )
// [-5, -2, -1] -2 + 5
int findPairs(std::vector<int> &nums, int k) {
  std::sort(nums.begin(), nums.end());
  int left = 0;
  int right = 1;
  int count = 0;
  int prev = std::numeric_limits<int>::min();

  while (right < nums.size()) {
    int diff = nums[right] - nums[left];

    if (diff < k) {
      right += 1;
    } else if (diff == k) {
      if (nums[left] != prev) {
        count += 1;
      }
      prev = nums[left++];
    } else {
      prev = nums[left++];
    }

    if (left == right) right += 1;
  }

  return count;
}

int main() {

  return 0;
}
