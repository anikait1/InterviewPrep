#include <iostream>
#include <vector>
#include <algorithm>

struct SubArray {
  int start;
  int end;
  int sum;

  SubArray(int start, int end, int sum)
    : start(start), end(end), sum(sum)
  {
    // constructor
  }

  SubArray()
  {
    // constructor
  }
};

template <typename T>
void display(const std::vector<T> &vec) {
  std::cout << "[ ";
  for (const auto &val : vec) {
    std::cout << val << ' ';
  }
  std::cout << "]\n";
}

SubArray maximumSubArray(const std::vector<int> &vec) {
  std::vector<SubArray> dp(vec.size());
  dp[0] = SubArray(0, 0, vec[0]);

  for (int i = 1; i < (int)vec.size(); ++i) {
    int sum = std::max(dp[i - 1].sum + vec[i], vec[i]);

    if (sum == vec[i]) {
      dp[i] = SubArray(i, i, vec[i]);
    } else {
      dp[i] = SubArray(dp[i - 1].start, i, dp[i - 1].sum + vec[i]);
    }
  }

  auto maxSubArray = *std::max_element(dp.begin(), dp.end(), [](SubArray &s1, SubArray &s2) {
    return s1.sum < s2.sum;
  });

  return maxSubArray;
}

int main() {
  // std::vector<int> vec{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::vector<int> vec {1, 2, 3, -2, 5};
  auto res = maximumSubArray(vec);
  std::cout << "Start: " << res.start << " End: " << res.end << " Sum: " << res.sum << '\n';

  return 0;
}