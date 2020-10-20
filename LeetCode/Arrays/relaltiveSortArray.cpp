#include <vector>
#include <algorithm>
#include <unordered_map>

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    std::unordered_map<int, int> sortOrder;

    for (int i = 0; i < arr2.size(); ++i)
    {
        sortOrder.insert({arr2[i], i});
    }

    auto it = std::partition(arr1.begin(), arr1.end(), [&sortOrder](int a) {
        return sortOrder.find(a) != sortOrder.end();
    });

    std::sort(arr1.begin(), it, [&sortOrder](int a, int b) {
        return sortOrder[a] < sortOrder[b];
    });

    std::sort(it, arr1.end());

    return arr1;
}

int main()
{
    return 0;
}
