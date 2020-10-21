#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

template<typename T>
void display(T *container, std::size_t size) {
  std::cout << "[ ";
  for (std::size_t i = 0; i < size; ++i) {
    std::cout << container[i] << ' ';
  }
  std::cout << "]";
}

template<typename T>
void display(const std::vector<T> &vec) {
  std::cout << "[ ";
  for (const auto &num : vec) {
    std::cout << num << ' ';
  }
  std::cout << "]\n";
}

void countSort(std::vector<int> &vec) {
  std::array<int, 3> count{};
  
  for (auto num : vec) {
    count[num] += 1;
  }
  
  int index = 0;
  for (std::size_t i = 0; i < count.size(); ++i) {
    while (count[i] != 0) {
      vec[index++] = i;
      count[i] -= 1;
    }
  }
}



int main() {
  std::vector<int> vec{0, 1, 1, 2, 0, 2, 1};
  
  display(vec);
  countSort(vec);
  display(vec);
  
  return 0;
}
