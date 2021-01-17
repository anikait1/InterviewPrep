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

int Height(TreeNode* node, bool* flag) {
    if (node == nullptr) {
        return -1;
    }

    auto leftHeight = Height(node->left, flag);
    auto rightHeight = Height(node->right, flag);
    node->height = std::max(leftHeight, rightHeight) + 1;

    if (std::abs(leftHeight - rightHeight) > 1) {
        *flag = false;
    }

    return node->height;
}

bool isBalanced(TreeNode* node) {
    bool flag = true;
    auto _ = Height(node, &flag);
    return flag;
}

int main() {

    TreeNode* node = new TreeNode(100);
    node->left = new TreeNode(20);
    node->left->left = new TreeNode(102);
    node->left->right = new TreeNode(241);
    node->left->right->left = new TreeNode(1520);

    node->right = new TreeNode(2121);
    node->right->right = new TreeNode(421);

    auto height = isBalanced(node);

    return 0;
}