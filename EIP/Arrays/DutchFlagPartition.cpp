#include <iostream>
#include <vector>

typedef enum { RED, WHITE, BLUE } Color;

template<typename T>
void display(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const T& val : vec) {
        std::cout << val << ' ';
    }
    std::cout << "]\n";
}

void DutchFlagPartition(int pivot_index, std::vector<int>& A_ptr) {
    std::vector<int>& A = A_ptr;
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

void DutchFlagPartition(int pivot_index, std::vector<Color>* A_ptr) {
    std::vector<Color>& A = *A_ptr;
    Color pivot = A[pivot_index];
    int smaller = 0, equal = 0, larger = A.size();

    while (equal < larger) {
        if (A[equal] < pivot) {
            std::swap(A[equal++], A[smaller++]);
        } else if (A[equal] == pivot) {
            equal++;
        } else {
            std::swap(A[equal], A[--larger]);
        }
    }

    display(A);
}


int main() {
    std::vector<int> A{1, 1, 0, 1, 0, 2, 1, 0, 1, 1, 2, 2, 0, 1};
    std::vector<Color> C{WHITE, BLUE, RED, BLUE, RED, WHITE, RED, WHITE, BLUE, BLUE, RED, RED, BLUE, WHITE};

    DutchFlagPartition(0, &C);

    return 0;
}