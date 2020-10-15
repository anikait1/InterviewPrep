#include <bits/stdc++.h>

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    int l = 0, h = letters.size() - 1;
    int t = target + 1;
    
    while(l <= h) {
        int m = (l + h)/2;
        
        if(letters[m] == t) return letters[m];
        else if(letters[m] < t) l = m + 1;
        else h = m - 1;
    }

    return letters[l % letters.size()];
}

int main()
{

    return 0;
}