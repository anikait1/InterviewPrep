#include <iostream>
#include <vector>

template <typename T>
void display(const std::vector<T> &vec) {
  std::cout << "[ ";
  for (const auto &val : vec) {
    std::cout << val << ' ';
  }
  std::cout << "]\n";
}

std::vector<int> rotate(std::vector<int> &vec, int n_rotations) {
  std::vector<int> rotated_vec(vec.size());
  n_rotations %= vec.size();

  for (int i = 0; i < (int)vec.size(); ++i) {
    rotated_vec[(i + n_rotations) % vec.size()] = vec[i];
  }

  return rotated_vec;
}

int main() {
  std::vector<int> vec{3, 4, 5, 1};
  display(rotate(vec, 1));

  return 0;
}