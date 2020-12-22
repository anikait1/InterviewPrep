#include <iostream>

template<typename T>
struct ListNode {
    T data;
    ListNode* next;
};

ListNode<int>* SearchList(ListNode<int>* L, int key) {
    while (L && L->data != key) {
        L = L->next;
    }

    return L;
}

// [1 -> 2 -> 3], N = 4
// [1 -> 2 -> 4 -> 3]
void InsertAfter(ListNode<int>* node, ListNode<int>* new_node) {
    new_node->next = node->next;
    node->next = new_node;
}

void DeleteAfter(ListNode<int>* node) {
    ListNode<int>* temp_node = node->next;
    node->next = node->next->next;

    delete temp_node;
}

int main() {

    return 0;
}