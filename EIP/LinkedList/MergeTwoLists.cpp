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

ListNode<int>* MergedLists(ListNode<int>* L1, ListNode<int>* L2) {
    ListNode<int>* dummy_head = new ListNode<int>(0);
    auto tail = dummy_head;

    while (L1 && L2) {
        if (L1->data <= L2->data) {
            tail->next = L1;
            tail = L1;
            L1 = L1->next;
        } else {
            tail->next = L2;
            tail = L2;
            L2 = L2->next;
        }
    }

    tail->next = L1 ? L1 : L2;

    return dummy_head->next;
}


int main() {
    ListNode<int>* L1 = new ListNode<int>(6);
    L1->next = new ListNode<int>(11);
    L1->next->next = new ListNode<int>(14);

    ListNode<int>* L2 = new ListNode<int>(5);
    L2->next = new ListNode<int>(8);
    L2->next->next = new ListNode<int>(12);

    auto res = MergedLists(L1, L2);
    display<int>(res);

    return 0;
}