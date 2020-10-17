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


    
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root == nullptr) 
        return {};
    vector<vector<int>> out;
    queue<TreeNode*> q;
    q.push(root);
    int level = 1;
    while(!q.empty()) {
        int size = q.size();
        vector<int> v;
        while(size--) {
            TreeNode *temp = q.front();
            v.push_back(temp->val);
            q.pop();
                if(temp->left != nullptr)
                    q.push(temp->left);
                if(temp->right != nullptr)
                    q.push(temp->right);
        }
        if(level % 2 == 0) {
            reverse(v.begin(), v.end());       
        }
        out.push_back(v);
        level++;
    }
    return out;
}

int main()
{

    return 0;
}