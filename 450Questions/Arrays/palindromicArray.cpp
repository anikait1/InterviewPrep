#include <iostream>
#include <vector>

int n_operations(std::vector<int> &vec) {
  int it_start = 0;
  int it_end = vec.size() - 1;
  int count = 0;

  while (it_start <= it_end) {
    if (vec[it_start] == vec[it_end]) {
      it_start += 1;
      it_end -= 1;
    } else if (vec[it_start] < vec[it_end]) {
      vec[it_start + 1] += vec[it_start];
      it_start += 1;
      count += 1;
    } else {
      vec[it_end - 1] += vec[it_end];
      it_end -= 1;
      count += 1;
    }
  }
  
  return count;
}

int main() {
  std::vector<int> vec{5, 3, 3, 4};
  auto count = n_operations(vec);
  
  std::cout << count << '\n';


  return 0;
}
