#include <iostream>

template<typename T>
void display(T *container, std::size_t size) {
  std::cout << "[ ";
  for (std::size_t i = 0; i < size; ++i) {
    std::cout << container[i] << ' ';
  }
  std::cout << "]";
}

template<typename T>
void swap(T &valOne, T &valTwo) {
  T temp = valOne;
  valOne = valTwo;
  valTwo = temp;
}

template<typename T>
void reverse(T *container, std::size_t size) {
  std::size_t left = 0;
  std::size_t right = size - 1;

  while (left < right) {
    swap(container[left], container[right]);
    left += 1;
    right -= 1;
  }
}

int main() {
  int *container = new int[5];

  for (int i = 0; i < 5; ++i) {
    container[i] = i;
  }

  display(container, 5);
  reverse(container, 5);
  display(container, 5);

  return 0;
}
