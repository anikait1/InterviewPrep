#include <iostream>
#include <utility>
#include <limits>
#include <cstdlib>

template<typename T>
void display(T *container, std::size_t size) {
  std::cout << "[ ";
  for (std::size_t i = 0; i < size; ++i) {
    std::cout << container[i] << ' ';
  }
  std::cout << "]";
}

std::pair<int, int> minmax(int *container, std::size_t size) {
  // first -> minimum, second -> maximum
  std::pair<int, int> res{ std::numeric_limits<int>::max(), std::numeric_limits<int>::min() };

  for (std::size_t i = 0; i < size; ++i) {
    if (container[i] < res.first) {
      res.first = container[i];
    }

    if (container[i] > res.second) {
      res.second = container[i];
    }
  }

  return res;
}

int main() {
  int *container = new int[5];

  for (int i = 0; i < 5; ++i) {
    container[i] = rand() % 5000;
  }

  display(container, 5);

  auto ans = minmax(container, 5);
  std::cout << ans.first << ' ' << ans.second << '\n';

  return 0;
}
