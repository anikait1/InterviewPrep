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

void postOrder(vector<int> &vec, TreeNode* root) {
    if(root != nullptr) {
        postOrder(vec, root->left);
        postOrder(vec, root->right);
        vec.push_back(root->val);
    }
}
    
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> vec;
    postOrder(vec, root);
    return vec;
}

int main()
{

    return 0;
}