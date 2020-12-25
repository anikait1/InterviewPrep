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

ListNode<int>* CyclicRotate(ListNode<int>* node, int k) {
    int len = 1;
    ListNode<int>* tail = node;

    while (tail->next) {
        tail = tail->next;
        ++len;
    }

    k %= len;
    if (k == 0) { return node; }

    tail->next = node;
    int steps = len - k;

    while (steps--) {
        tail = tail->next;
    }
    auto new_head = tail->next;
    tail->next = nullptr;
    return new_head;
}

int main() {

    return 0;
}