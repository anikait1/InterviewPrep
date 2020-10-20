#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val)
    : val(val), left(nullptr), right(nullptr)
  {

  }
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> vec;
    stack<TreeNode*> stk;
    TreeNode* t = root;
    while(t != nullptr || !stk.empty()) {
        if(t != nullptr) {
            stk.push(t);
            t = t->left;
        }
        else {
            t = stk.top(); stk.pop();
            vec.push_back(t->val);
            t = t->right;
        }
    }
    return vec;
}

int main()
{

    return 0;
}