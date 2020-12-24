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

ListNode<int>* ReverseSubList(ListNode<int>* node, int s, int f) {
    ListNode<int>* prev = nullptr;
    ListNode<int>* curr = node;

    while (s > 1) {
        prev = curr;
        curr = curr->next;
        s--;
        f--;
    }

    ListNode<int>* con = prev;
    ListNode<int>* tail = curr;
    while (f > 0) {
        ListNode<int>* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        f--;
    }

    if (con != nullptr) {
        con->next = prev;
    } else {
        node = prev;
    }

    tail->next = curr;
    return node;
}

int main() {


    return 0;
}