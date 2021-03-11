#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using std::vector;
using std::string;
using std::priority_queue;
using std::function;

vector<int> AlmostKSorted(const std::vector<int>& vec, int k) {
    priority_queue<int, std::vector<int>, std::greater<>> min_heap;

    for (int i = 0; i < k; ++i) {
        min_heap.emplace(vec[i]);
    }

    vector<int> result;
    for (int i = k; i < vec.size(); ++i) {
        min_heap.emplace(vec[i]);
        result.push_back(min_heap.top());
        min_heap.pop();
    }

    while (!min_heap.empty()) {
       result.push_back(min_heap.top());
       min_heap.pop();
    }
    
    return result;
}

int main() {

}