#include <vector>
#include <stack>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val)
      : val(val), left(nullptr), right(nullptr)
  {
  }
};

std::vector<int> preorderTraversal(TreeNode *root) {
  std::vector<int> result;
  std::stack<TreeNode *> stack;
  TreeNode *curr = root;

  // TO DO

  return result;
}

int main()
{
  return 0;
}