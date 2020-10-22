#include <iostream>
#include <unordered_set>
#include <vector>

int unionArr(std::vector<int> &nums1, std::vector<int> &nums2)
{
  std::unordered_set<int> common(nums1.begin(), nums1.end());

  for (auto num : nums2)
  {
    if (common.count(num) == 0)
    {
      common.insert(num);
    }
  }

  return common.size();
}

int main()
{
  std::size_t T;
  std::cin >> T;

  while (T--)
  {
    int n1, n2;
    std::cin >> n1 >> n2;

    std::vector<int> nums1(n1);
    std::vector<int> nums2(n2);

    for (int i = 0; i < n1; ++i)
    {
      std::cin >> nums1[i];
    }

    for (int i = 0; i < n2; ++i)
    {
      std::cin >> nums2[i];
    }

    std::cout << unionArr(nums1, nums2) << '\n';
  }
  return 0;
}
