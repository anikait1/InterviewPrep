#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <cmath>

using std::vector;
using std::string;
using std::priority_queue;
using std::function;

struct Star {
    double x, y, z;
    
    double distance() const { return std::sqrt(x * x + y * y + z * z); }

    bool operator<(const Star& that) const {
        distance() < that.distance();
    }
};

vector<Star> FindClosestKStars(const vector<Star>& stars, int k) {
    priority_queue<Star, vector<Star>> max_heap;

    for (auto& star : stars) {
        max_heap.emplace(star);
        
        if (max_heap.size() > k) {
            max_heap.pop();
        }
    }

    vector<Star> result;
    while (!max_heap.empty()) {
        result.emplace_back(max_heap.top());
        max_heap.pop();
    }
    
    return result;
} 

int main() {

    return 0;
}