#include <iostream>
#include <vector>
#include <algorithm>

void display(int arr[], int size) {
  std::cout << "[ ";
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << "]\n";
}

// Input: [-1, 2, 4, -4, 1]
// Modified: [-1, -4, 2, 4, 1]
int partition(int arr[], int size) {
  int index = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] < 0) {
      std::swap(arr[i], arr[index++]);
    }
  }
  std::cout << "Index: " << index << '\n';
  return index;
}

void alternateSignNumbers(int arr[], int size) {
  int pIndex = partition(arr, size);
  int itr = 0;

  // all numbers are positive
  // early return
  if (pIndex == 0) {
    return;
  }

  while (pIndex < size) {
    std::swap(arr[pIndex], arr[itr]);

    pIndex += 1;
    itr += 2;
  }
  
}

int main() {
  const int size = 5;
  int arr[] = {-2, 3, 4, 5, -6};
  
  display(arr, size);
  alternateSignNumbers(arr, size);
  display(arr, size);

  return 0;
}
