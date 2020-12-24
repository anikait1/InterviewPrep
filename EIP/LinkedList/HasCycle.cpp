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

bool HasCycle(ListNode<int>* node) {
    std::unordered_set<ListNode<int>*> nodes;

    while (true && node != nullptr) {
        if (nodes.find(node) != nodes.end()) {
            return true;
        } else {
            nodes.insert(node);
        }

        node = node->next;
    }

    return false;
}

bool HasCycleLoop(ListNode<int>* node) {
    ListNode<int>* slow = node;
    ListNode<int>* fast = node;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {

    return 0;
}