#include <iostream>
#include <vector>

int binary_search(const std::vector<int> &vec, int lo, int hi, int target) {
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;

    if (vec[mid] == target)
      return mid;
    else if (vec[mid] < target)
      lo = mid + 1;
    else
      hi = mid - 1;
  }

  return -1;
}

std::vector<int> searchRange(std::vector<int> &nums, int target) {
  int N = nums.size() - 1;
  int first = -1;
  int last = -1;

  int index = binary_search(nums, 0, N, target);
  int left = binary_search(nums, 0, index - 1, target);
  int right = binary_search(nums, index + 1, N, target);

  while (true) {
    if (left != -1) {
      first = left;
      left = binary_search(nums, 0, left - 1, target);
    }
    else { break; }
  }

  while (true) {
    if (right != -1) {
      last = right;
      right = binary_search(nums, right + 1, N, target);
    }
    else { break; }
  }

  if (first == -1) {
    first = index;
  }

  if (last == -1) {
    last = index;
  }

  return std::vector<int>{first, last};
}

int main() {
  return 0;
}
