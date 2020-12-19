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

std::vector<int> Multiply(std::vector<int> num1, std::vector<int> num2) {
    const int sign = num1.front() < 0 ^ num2.front() < 0;
    num1.front() = std::abs(num1.front()), num2.front() = std::abs(num2.front());

    std::vector<int> result(num1.size() + num2.size(), 0);
    for (int i = num1.size() - 1; i >= 0; --i) {
        for (int j = num2.size() - 1; j >= 0; --j) {
            result[i + j + 1] += num1[i] * num2[j];
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }

    result = {
        std::find_if_not(std::begin(result), std::end(result), [](int a) { return a == 0; }),
        std::end(result)};
    
    if (result.empty()) {
        return {0};
    }

    result.front() *= sign;
    return result;
}

int main() {
    int num1 = -4;
    int num2 = 5;
    int val = num1 < 0 ^ num2 < 0;

    std::cout << val  << '\n';

    return 0;
}