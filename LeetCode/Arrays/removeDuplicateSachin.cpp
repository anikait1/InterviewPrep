#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
        
    int len = 1, dup = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        
        if(nums[i] != dup) {
            dup = nums[i];
            nums[len++] = dup;
        }
    }

    return len;
}

int main()
{

    return 0;
}