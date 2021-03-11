#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using std::vector;
using std::string;
using std::priority_queue;
using std::function;

struct IteratorCurrentAndEnd {
    bool operator>(const IteratorCurrentAndEnd& that) const {
        return *current > *that.current;
    }

    vector<int>::const_iterator current;
    vector<int>::const_iterator end;
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
    priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>, std::greater<>> min_heap;

    for (auto& sorted_array : sorted_arrays) {
        min_heap.emplace(
            IteratorCurrentAndEnd{sorted_array.cbegin(), sorted_array.cend()});
    }

    vector<int> result;
    while (!min_heap.empty()) {
        auto smallest_num = min_heap.top();
        min_heap.pop();

        if (smallest_num.current != smallest_num.end) {
            result.emplace_back(*smallest_num.current);
            min_heap.emplace(IteratorCurrentAndEnd{
                std::next(smallest_num.current), smallest_num.end});
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> vec{
        {1, 2, 3, 4, 9, 18, 21},
        {4, 11, 12, 18, 18},
        {100, 101, 241},
        {141, 241}
    };

    auto r = MergeSortedArrays(vec);

    std::cout << "[ ";
    for (auto val : r) {
        std::cout << val << ' ';
    }
    std::cout << "]\n";

}