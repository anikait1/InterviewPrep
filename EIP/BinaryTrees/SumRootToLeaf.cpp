#include <iostream>

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int x)
        : data(x), left(nullptr), right(nullptr)
        {

        }
};

void Sum(BinaryTreeNode* node, int partialSum, int* sum) {
    if (node) {
        partialSum = partialSum * 2 + node->data;

        if (!node->left && !node->right) {
            *sum += partialSum;
        }

        Sum(node->left, partialSum, sum);
        Sum(node->right, partialSum, sum);
    }
}

int main() {
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(0);
    root->left->left = new BinaryTreeNode(0);
    root->left->right = new BinaryTreeNode(1);

    root->right = new BinaryTreeNode(1);
    root->right->left = new BinaryTreeNode(0);
    root->right->right = new BinaryTreeNode(1);

    int sum = 0;
    Sum(root, 0, &sum);
    std::cout << sum << '\n';




    return 0;
}