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

ListNode<int>* RemoveKthLast(ListNode<int>* node, int k) {
    auto dummy_head = new ListNode<int>(0);
    dummy_head->next = node;

    ListNode<int>* first = dummy_head->next;
    while (k--) {
        first = first->next;
    }

    auto second = dummy_head;
    while (first) {
        second = second->next;
        first = first->next;
    }
    second->next = second->next->next;
    return dummy_head->next;
}

int main() {

    return 0;
}