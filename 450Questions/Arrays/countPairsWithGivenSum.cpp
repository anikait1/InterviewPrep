#include <iostream>
#include <vector>
#include <unordered_map>

int getPairsCount(int arr[], int n, int k) {
  std::unordered_map<int, int> fCount;
  int pairCount = 0;

  for (int i = 0; i < n; ++i) {
    if (fCount.find(arr[i]) != fCount.end()) {
      fCount[arr[i]] += 1;
    } else {
      fCount.insert({arr[i], 1});
    }
  }

  for (int i = 0; i < n; ++i) {
    if (fCount.find(k - arr[i]) != fCount.end()) {
      fCount[arr[i]] -= 1;
      if (fCount[k - arr[i]] > 0) {
        pairCount += fCount[k - arr[i]];
      }
    }
  }

  return pairCount;
}

int main()
{
  int arr[] = {1, 5, 7, 1};

  std::cout << getPairsCount(arr, 4, 6) << '\n';

  return 0;
}
