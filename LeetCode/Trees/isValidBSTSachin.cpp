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

TreeNode* m;

bool is(TreeNode* root)
{
    if(root != NULL) {
        if(is(root->left)==false)return false;
        
        if(m == NULL) m = root;  
        else {
            if(root->val <= m->val) return false;
            else m = root;
        }
            
        return is(root->right);
    }
    else return true;
}
    
bool isValidBST(TreeNode* root) {
    m = NULL;
    return is(root);
}


int main()
{

    return 0;
}