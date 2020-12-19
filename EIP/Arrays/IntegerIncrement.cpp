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

std::vector<int> PlusOne(std::vector<int> A) {
    A.back() += 1;
    for (int i = A.size() - 1; i > 0 && A[i] == 10; --i) {
        A[i] = 0; 
        A[i - 1] += 1;
    }

    if (A[0] == 10) {
        A[0] = 0;
        A.insert(A.begin(), 1);
    }

    return A;
}

int main() {
    std::vector<int> vec{9, 9, 9};
    auto res = PlusOne(vec);

    display(res);

    return 0;
}