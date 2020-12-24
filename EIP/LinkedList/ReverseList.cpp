#include <iostream>

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

ListNode<int>* Reverse(ListNode<int>* node) {
    ListNode<int>* prev = nullptr;
    ListNode<int>* curr = node;

    while (curr) {
        ListNode<int>* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    ListNode<int>* L1 = new ListNode<int>(6);
    L1->next = new ListNode<int>(11);
    L1->next->next = new ListNode<int>(14);
    L1->next->next->next = new ListNode<int>(111);
    L1->next->next->next->next = new ListNode<int>(14);

    display(L1);
    L1 = Reverse(L1);
    display(L1);

    return 0;
}