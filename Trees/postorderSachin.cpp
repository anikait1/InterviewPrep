#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<int> postorder(Node* root) {
        if(root == nullptr)
            return {};
        stack<Node*> stk;
        vector<int> out;
        stk.push(root);
        while(!stk.empty()) {
            Node* child = stk.top();
            stk.pop();
            out.push_back(child->val);
            for(auto node : child->children) {
                if(node != nullptr)
                    stk.push(node);
            }
        }
        reverse(out.begin(), out.end());
        return out;
    }


int main()
{

    return 0;
}