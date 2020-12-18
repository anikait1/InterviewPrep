#include <iostream>
#include <vector>

template<typename T>
void display(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const T& val : vec) {
        std::cout << val << ' ';
    }
    std::cout << "]\n";
}

typedef enum { RED, WHITE, BLUE } Color;

void DutchFlagPartition(int pivot_index, std::vector<int>* A_ptr) {
    std::vector<int>& A = *A_ptr;
    int pivot = A[pivot_index];

    // elements smaller than pivot to the start
    int smaller = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] < pivot) {
            std::swap(A[i], A[smaller++]);
        }
    }

    // elements larger than pivot to the end
    int larger = A.size() - 1;
    for (int i = A.size() - 1; i >= 0 && A[i] >= pivot; --i) {
        if (A[i] > pivot) {
            std::swap(A[i], A[larger--]);
        }
    }

    display(A);
}

// [1, 0, 1, 2, 1, 0, 2, 1, 2, 1]
// [0, 0, 1, 2, 1, 1, 2, ]

void DutchFlagPartition(int pivot_index, std::vector<int>* A_ptr) {
    std::vector<int>& A = *A_ptr;
    int pivot = A[pivot_index];

}


int main() {
    std::vector<int> A{1, 0, 1, 2, 1, 0, 2, 1, 2, 1};
    DutchFlagPartition(0, &A);

    return 0;
}