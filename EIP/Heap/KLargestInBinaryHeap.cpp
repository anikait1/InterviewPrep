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

vector<int> KLargestInBinaryHeap(const vector<int>& vec, int k) {
    using HeapEntry = std::pair<int, int>;
    priority_queue<HeapEntry, vector<HeapEntry>, 
                  function<bool(HeapEntry, HeapEntry)>> 
    max_heap([](const HeapEntry& a, const HeapEntry& b) { 
        return a.second < b.second; 
    });

    vector<int> result;
    max_heap.emplace(HeapEntry{0, vec[0]});

    for (int i = 0; i < k; ++i) {
        HeapEntry top = max_heap.top();
        max_heap.pop();
        result.push_back(top.second);

        auto left_child_idx = 2 * top.first + 1;
        auto right_child_idx = 2 * top.first + 2;

        if (left_child_idx < vec.size()) {
            max_heap.emplace(HeapEntry{left_child_idx, vec[left_child_idx]});
        }

        if (right_child_idx < vec.size()) {
            max_heap.emplace(HeapEntry{right_child_idx, vec[right_child_idx]});
        }
    }

    return result;
}

int main() {

    return 0;
}