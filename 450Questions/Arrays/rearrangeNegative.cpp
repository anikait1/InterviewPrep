#include <iostream>
#include <vector>

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

void rearrage(std::vector<int> &vec)
{
  int index = 0;

  for (int i = 0; i < vec.size(); ++i)
  {
    if (vec[i] < 0)
    {
      std::swap(vec[index++], vec[i]);
    }
  }
}

int main()
{
  std::vector<int> vec{-12, 11, -13, -5, 6, -7, 5, -3, -6};
  display(vec);
  rearrage(vec);
  display(vec);
  return 0;
}
