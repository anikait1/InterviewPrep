#include <bits/stdc++.h>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    int i = 0, j = 0;
    while(i < nums1.size() && j < nums2.size()) {
        if(nums1[i] == nums2[j]) {
            if(res.size() == 0)
                res.push_back(nums1[i]);
            if(res[res.size() - 1] != nums1[i]) {
                res.push_back(nums1[i]);
            }
            i++; j++;
        }
        else if(nums1[i] < nums2[j]) i++;
        else j++;
    }
    return res;
}

int main()
{

    return 0;
}