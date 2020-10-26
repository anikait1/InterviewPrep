#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

std::vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
  std::vector<int> vec;

  int it_A = 0;
  int it_B = 0;
  int it_C = 0;

  while (it_A < n1 && it_B < n2 && it_C < n3) {
    if (A[it_A] == B[it_B] && A[it_A] == C[it_C]) {
      if (vec.size() == 0) { 
        vec.push_back(A[it_A]); 
        } else {
        if (*vec.rbegin() != A[it_A]) {
          vec.push_back(A[it_A]);
        }
      }

      it_A += 1;
      it_B += 1;
      it_C += 1;
    
    } else if (A[it_A] <= B[it_B] && A[it_A] <= C[it_C]) {
      it_A += 1;
    } else if (B[it_B] <= A[it_A] && B[it_B] <= C[it_C]) {
      it_B += 1;
    } else {
      it_C += 1;
    }
  }

  return vec;
}

int main()
{
  int A[] = {1, 5, 10, 20, 40, 80};
  int B[] = {6, 7, 20, 80, 100};
  int C[] = {3, 4, 15, 20, 30, 70, 80, 120};

  auto res = commonElements(A, B, C, 6, 5, 8);

  for (auto val : res) {
    std::cout << val << '\n';
  }

  return 0;
}
