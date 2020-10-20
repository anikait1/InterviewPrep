#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

std::vector<std::string> commonChars(const std::vector<std::string> &A) {
  std::unordered_map<char, std::vector<int>> charCount;
  std::vector<std::string> res;

  for (int i = 0; i < A.size(); ++i) {
    for (char c : A[i]) {
      if (charCount.find(c) != charCount.end()) {
        charCount[c][i] += 1;
      } else {
        charCount.insert({c, std::vector<int>(A.size(), 0)});
        charCount[c][i] = 1;
      }
    }
  }

  for (auto p : charCount) {
    int minCount = *std::min_element(p.second.begin(), p.second.end());
    if (minCount != 0) {
      res.push_back(std::string(1, p.first));
    }
  }

  return res;
}

int main()
{
  std::vector<std::string> vec{"bella", "label", "roller"};
  auto res = commonChars(vec);

  return 0;
}