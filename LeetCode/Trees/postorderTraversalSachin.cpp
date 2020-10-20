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

vector<int> postorderTraversal(TreeNode* root) {
    if(root == nullptr)
        return {};
  
    stack<TreeNode*> stk;
    vector<int> out;
    stk.push(root);
    while(!stk.empty()) {
        TreeNode* temp = stk.top();
        stk.pop();
        out.push_back(temp->val);
        if(temp->left != nullptr)
            stk.push(temp->left);
        if(temp->right != nullptr)
            stk.push(temp->right);
    }
    reverse(out.begin(), out.end());
    return out;
}

int main()
{

    return 0;
}
