#include <iostream>
#include <vector>
#include <unordered_set>

void zeroSumSubArray(const std::vector<int> &vec) {
  std::unordered_set<int> sums;
  std::vector<int> prefixSum(vec.size());
  
  prefixSum[0] = vec[0];
  sums.insert(prefixSum[0]);
  
  for (int i = 1; i < vec.size(); ++i) {
    prefixSum[i] = vec[i] + prefixSum[i - 1];
    
    if (sums.count(prefixSum[i]) > 0 || prefixSum[i] == 0) {
      std::cout << "Yes\n";
      return;
    } else {
      sums.insert(prefixSum[i]);
    }
  }
  
  std::cout << "No\n";
}

int main()
{
  std::size_t T;
  std::cin >> T;

  while (T--)
  {
    std::size_t n;
    std::cin >> n;

    std::vector<int> vec(n);
    for (std::size_t i = 0; i < n; ++i)
    {
      std::cin >> vec[i];
    }

    zeroSumSubArray(vec);
  }

  return 0;
}
