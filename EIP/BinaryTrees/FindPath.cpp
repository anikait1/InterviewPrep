#include <iostream>
#include <vector>

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int x)
        : data(x), left(nullptr), right(nullptr)
        {

        }
};

void preorder(BinaryTreeNode* node) {
    if (node) {
        std::cout << node->data << '\n';
        preorder(node->left);
        preorder(node->right);
    }
}

void FindPath(BinaryTreeNode* node, std::vector<int> path ,int key) {
    if (node) {
        if (node->data == key) {
            path.push_back(node->data);
            std::cout << "[ ";
            for (auto val : path) {
                std::cout << val << ' ';
            }
            std::cout << "]\n";
            return;
        }
        path.push_back(node->data);
        FindPath(node->left, path, key);
        FindPath(node->right, path, key);
    }
}

int main() {
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(7);
    root->left->left = new BinaryTreeNode(5);
    root->right = new BinaryTreeNode(9);
    root->right->right = new BinaryTreeNode(13);
    root->right->left = new BinaryTreeNode(11);
    root->right->left->right = new BinaryTreeNode(14);

    std::vector<int> v;
    FindPath(root, v, 11);


    return 0;
}