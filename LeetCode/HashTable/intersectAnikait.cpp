#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
  std::unordered_map<int, int> count;
  std::vector<int> common;

  for (auto num : nums1) {
    if (count.find(num) != count.end()) {
      count[num] += 1;
    } else {
      count.insert({num, 1});
    }
  }

  for (auto num : nums2) {
    if (count.find(num) != count.end() && count[num] != 0) {
      common.push_back(num);
      count[num] -= 1;
    }
  }

  return common;
}

int main()
{

  return 0;
}