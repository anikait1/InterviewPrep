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

bool CanReachEnd(const std::vector<int>& max_advance_steps) {
    int furthest_reach_end = 0;

    for (int i = 0; i < max_advance_steps.size(); ++i) {
        if (i > furthest_reach_end || furthest_reach_end >= max_advance_steps.size()) {
            break;
        }
        furthest_reach_end = std::max(furthest_reach_end, i + max_advance_steps[i]);
    }

    return furthest_reach_end >= max_advance_steps.size(); 
}

int main() {

    return 0;
}