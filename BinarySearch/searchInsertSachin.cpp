#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int l = 0, h = nums.size() - 1;
    while(l <= h) {
        int m = (l + h)/2;
        if(nums[m] == target) return m;
        else if(nums[m] < target) l = m + 1;
        else h = m - 1;
    }
    return l;
}

int main()
{

    return 0;
}