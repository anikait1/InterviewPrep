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

void MedianOfRunningData(const vector<int>& data) {
    priority_queue<int, vector<int>, std::greater<>> min_heap; // larger half
    priority_queue<int, vector<int>, std::less<>> max_heap; // smaller half

    for (const auto& val : data) {
        if (min_heap.empty()) {
            min_heap.push(val);
        } else {
            if (val >= min_heap.top()) {
                min_heap.push(val);
            } else {
                max_heap.push(val);
            }
        }

        if (min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else if (max_heap.size() > min_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        std::cout << (min_heap.size() == max_heap.size() 
        ? 0.5 * (min_heap.top() + max_heap.top())
        : min_heap.top())
        << '\n';
    }

}

int main() {

    return 0;
}