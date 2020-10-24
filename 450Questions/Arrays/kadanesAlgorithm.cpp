#include <iostream>
#include <vector>
#include <algorithm>

// store the information regarding sub arrays
// start and end index along with max sum
struct IndexInfo
{
  int start;
  int end;
  int sum;

  IndexInfo(int start, int end, int sum)
      : start(start), end(end), sum(sum)
  {
    // constructor
  }

  IndexInfo()
  {
    // constructor
  }
};

template <typename T>
void display(const std::vector<T> &vec)
{
  std::cout << "[ ";
  for (const auto &val : vec)
  {
    std::cout << val << ' ';
  }
  std::cout << "]\n";
}

IndexInfo maximumIndexInfo(const std::vector<int> &vec)
{
  std::vector<IndexInfo> dp(vec.size());
  dp[0] = IndexInfo(0, 0, vec[0]);

  for (int i = 1; i < (int)vec.size(); ++i)
  {
    int sum = std::max(dp[i - 1].sum + vec[i], vec[i]);

    if (sum == vec[i])
    {
      dp[i] = IndexInfo(i, i, vec[i]);
    }
    else
    {
      dp[i] = IndexInfo(dp[i - 1].start, i, dp[i - 1].sum + vec[i]);
    }
  }

  auto maxIndexInfo = *std::max_element(dp.begin(), dp.end(), [](IndexInfo &s1, IndexInfo &s2) {
    return s1.sum < s2.sum;
  });

  return maxIndexInfo;
}

int main()
{
  std::vector<int> vec{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  // std::vector<int> vec {1, 2, 3, -2, 5};
  auto res = maximumIndexInfo(vec);
  std::cout << "Start: " << res.start << " End: " << res.end << " Sum: " << res.sum << '\n';

  return 0;
}

// [-2, 1, -3, 4, -1, 2, 1, -5, 4]