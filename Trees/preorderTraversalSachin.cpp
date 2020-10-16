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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> out;
    stack<TreeNode*> stk;
    TreeNode* t = root;
    while(!stk.empty() || t != nullptr) {
        if(t != nullptr) {
            out.push_back(t->val);
            stk.push(t);
            t = t->left;
        }
        else {
            t = stk.top();
            stk.pop();
            t = t->right;
        }
    }
    return out;
}

int main()
{

    return 0;
}