#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> intersection(const std::vector<int> &numsOne, const std::vector<int> &numsTwo) {
  std::unordered_set<int> set(numsOne.begin(), numsOne.end());
  std::vector<int> common;

  for (auto num : numsTwo) {
    if (set.count(num) != 0) {
      common.push_back(num);
      set.erase(num);
    }
  }

  return common;
}

int main() {

  return 0;
}