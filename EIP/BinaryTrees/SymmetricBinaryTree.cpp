#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int val)
        : data{val}, left{nullptr}, right{nullptr}
        {
            // constructor
        }
};

bool CheckSymmetric(TreeNode* A, TreeNode* B) {
    if (A == nullptr && B == nullptr) {
        return true;
    } else if (A != nullptr && B != nullptr) {
        return (A->data == B->data && 
        CheckSymmetric(A->left, B->right) && 
        CheckSymmetric(A->right, B->left));
    } else {
        return false;
    }
}

bool IsSymmetric(TreeNode* node) {
    return node == nullptr || CheckSymmetric(node->left, node->right);
}

int main() {

    return 0;
}