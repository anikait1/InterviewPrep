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

vector<int> SortKIncreasingDecreasingArray(const vector<int>& A) {
    vector<vector<int>> sorted_subarrays;
    typedef enum { INCREASING, DECREASING } SubarrayType;
    SubarrayType subarray_type = INCREASING;
    int start_idx = 0;
    for (int i = 1; i <= A.size(); ++i) {
        if (i == A.size() || 
            (A[i - 1] < A[i] && subarray_type == DECREASING) ||
            (A[i - 1] >= A[i] && subarray_type == INCREASING)) {
            
            if (subarray_type == INCREASING) {
                sorted_subarrays.emplace_back(A.cbegin() + start_idx, A.cbegin() + i);
            } else {
                sorted_subarrays.emplace_back(A.crbegin() + A.size() - i, 
                                              A.crbegin() + A.size() - start_idx);
            }

            start_idx = i;
            subarray_type = (subarray_type == INCREASING ? DECREASING : INCREASING);
        }
    }

    return MergeSortedArrays(sorted_subarrays);
}

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
    return 0;
}