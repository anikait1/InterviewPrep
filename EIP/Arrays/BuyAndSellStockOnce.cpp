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
        max_profit = std::max(price - min_price_so_far, max_profit);
        min_price_so_far = std::min(min_price_so_far, price);
    }

    return max_profit;
}

int main() {

    return 0;
}