#include <iostream>
#include <unordered_set>

template<typename T>
struct ListNode {
    T data;
    ListNode* next;

    ListNode(T data)
        : data(data), next(nullptr)
    {
        // constructor
    }
};

template <typename T>
void display(ListNode<T>* node) {
    std::cout << "[ ";
    while (node) {
        std::cout << node->data << ' ';
        node = node->next;
    }
    std::cout << "]\n";
}

bool IsOverlappingNodes(ListNode<int>* L1, ListNode<int>* L2) {
    std::unordered_set<ListNode<int>*> nodes;

    while (L1) {
        nodes.insert(L1);
        L1 = L1->next;
    }

    while (L2) {
        if (nodes.find(L2) != nodes.end()) {
            return true;
        } else {
            nodes.insert(L2);
        }

        L2 = L2->next;
    }

    return false;
}

int main() {

    return 0;
}