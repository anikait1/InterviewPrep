#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <deque>

template<typename T>
void display(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const T& val : vec) {
        std::cout << val << ' ';
    }
    std::cout << "]\n";
}

// [1, 218]
std::vector<int> GeneratePrimes(int n) {
    std::vector<int> primes;
    std::deque<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < n; ++i) {
        if (is_prime[i]) {
            primes.emplace_back(i);

            for (int j = i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

int main() {

    return 0;
}