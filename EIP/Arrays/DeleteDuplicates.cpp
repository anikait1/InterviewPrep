#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void display(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const T& val : vec) {
        std::cout << val << ' ';
    }
    std::cout << "]\n";
}

// [1, 1, 1, 2, 3, 3, 4, 4, 4, 11, 11, 13]
// [1, 2, 3, 4, 11, 13]
int DeleteDuplicates(std::vector<int>* A_ptr) {
    std::vector<int>& A = *A_ptr;

    if (A.empty()) {
        return 0;
    }

    int write_index = 1;
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] != A[write_index - 1]) {
            A[write_index++] = A[i];
        }
    }
    return write_index;
}

int VariantRemoveGivenKey(std::vector<int>* A_ptr, int key) {
    std::vector<int>& A = *A_ptr;

    int write_index = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] != key) {
            A[write_index++] = A[i];
        }
    }

    return write_index;
}

int VariantRemoveDuplicates2(std::vector<int>* A_ptr);

int main() {

    return 0;
}