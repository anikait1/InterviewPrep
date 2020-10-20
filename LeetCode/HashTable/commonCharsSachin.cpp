#include <bits/stdc++.h>

using namespace std;

vector<string> commonChars(vector<string>& A) {
    vector<int> v(26, INT_MAX);
    for(int i = 0; i < A.size(); i++) {
        vector<int> count(26,0);
        for(int j = 0; j < A[i].length(); j++) {
            count[A[i][j] - 'a'] += 1;
        }
        for(int k = 0; k < 26; k++) {
            if(count[k] < v[k])
                v[k] = count[k];
            }
        }
    vector<string> res;
    for(int i = 0; i < 26; i++) {
        char val = 'a' + i;
        std::string out;
        out += val;
        for(int j = 0; j < v[i]; j++)
            res.push_back(out);
    }
    return res;
} 

int main()
{

    return 0;
}