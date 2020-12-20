#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template<typename T>
void display(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const T& val : vec) {
        std::cout << val << ' ';
    }
    std::cout << "]\n";
}

double BuyAndSellStockOnce(const std::vector<double>& prices) {
    // [100, 120, 110, 140, 200]
    double min_price_so_far = std::numeric_limits<double>::max(), max_profit = 0;
    for (const double& price : prices) {
        min_price_so_far = std::min(min_price_so_far, price);
        max_profit = std::max(price - min_price_so_far, max_profit);
    }

    return max_profit;
}

int LongestSubArrayWithEqualElements(const std::vector<int>& vec) {
    int curr_len = 1, max_len = std::numeric_limits<int>::min();
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] != vec[i - 1]) {
            max_len = std::max(curr_len, max_len);
        } else {
            curr_len++;
        }
    }

    return std::max(curr_len, max_len);
}

int main() {

    return 0;
}