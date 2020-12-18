/*
    Given an array, reorder it in such a manner that
    even numbers appear first
*/

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

std::vector<int> EvenOdd(std::vector<int>& A) {
    std::vector<int> ordered(A.size());
    int start = 0;
    int end = A.size() - 1;

    for (int num : A) {
        if (num % 2 == 0) {
            ordered[start++] = num;
        } else {
            ordered[end--] = num;
        }
    }

    return ordered;
}

void EvenOdd(std::vector<int>* A_ptr) {
    std::vector<int>& A = *A_ptr;
    int next_even = 0, next_odd = A.size() - 1;

    while (next_even < next_odd) {
        if (A[next_even] % 2 == 0) {
            next_even += 1;
        } else {
            std::swap(A[next_even], A[next_odd--]);
        }
    }

    std::cout << next_odd << ' ' << next_even << '\n';

    display(A);
}

int main() {
    std::vector<int> vec{1, 2, 5, 7, 9, 11, 4, 12, 14, 11};
    auto res = EvenOdd(vec);
    EvenOdd(&vec);

    display(res);

    return 0;
}