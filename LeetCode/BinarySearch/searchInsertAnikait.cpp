#include <vector>
#include <iostream>

template<typename T>
void display(const std::vector<T> &vec) {
  std::cout << "[ ";
  for (const auto &val : vec) {
    std::cout << val << ' ';
  }
  std::cout << "]\n";
}

int searchInsert(const std::vector<int> &nums, int target) {
  int low = 0;
  int high = nums.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) low = mid + 1;
    else high = mid - 1;
  }

  return low;
}

int main() {
  std::vector<int> vec{1, 3, 5, 6};
  std::cout << searchInsert(vec, 7) << '\n';
  std::cout << std::distance(vec.begin(), vec.end()) << '\n';
  return 0;
}