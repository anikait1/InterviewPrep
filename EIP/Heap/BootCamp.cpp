#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using std::vector;
using std::string;
using std::priority_queue;
using std::function;
using std::begin;
using std::end;

auto TopK(int k, vector<string>& stream) -> vector<string> {
    priority_queue<string, vector<string>, function<bool(string, string)>> min_heap(
        [](const string& a, const string& b) { return a.size() >= b.size(); }
    );

    std::for_each(begin(stream), end(stream), [&min_heap, &k](const string& s) {
        min_heap.emplace(s);

        if (min_heap.size() > k) {
            min_heap.pop();
        }
    });

    vector<string> result;
    while (!min_heap.empty()) {
        result.emplace_back(min_heap.top());
        min_heap.pop();
    }

    return result;
}

int main() {

    return 0;
}