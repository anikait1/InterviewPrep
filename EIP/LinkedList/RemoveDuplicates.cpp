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

ListNode<int>* RemoveDuplicates(ListNode<int>* node) {
    ListNode<int>* dummy_head = new ListNode<int>(0);
    dummy_head->next = node;

    ListNode<int>* one = node;
    ListNode<int>* two = node->next;

    while (one && two) {
        if (one->data == two->data) {
            two = two->next;
        } else {
            one->next = two;
            one = two;
            two = two->next;
        }
    }
    one->next = nullptr;
    return dummy_head->next;
}

// [1 1 1 2 3 4 5 5 6] -> [2 3 4 6]
ListNode<int>* OnlyDistinct(ListNode<int>* node) {
    ListNode<int>* dummy_head = new ListNode<int>(0);
    dummy_head->next = node;
    ListNode<int>* prev = dummy_head;

    while (node) {
        if (node->next && node->data == node->next->data) {
            while (node->next && node->data == node->next->data) {
                node = node->next;
            }
            prev->next = node->next;
        } else {
            prev = prev->next;
        }

        node = node->next;
    }

    return dummy_head->next;
}

int main() {
    ListNode<int>* node = new ListNode<int>(1);
    node->next = new ListNode<int>(1);
    node->next->next = new ListNode<int>(1);
    node->next->next->next = new ListNode<int>(2);
    node->next->next->next->next = new ListNode<int>(3);
    node->next->next->next->next->next = new ListNode<int>(3);
    node->next->next->next->next->next->next = new ListNode<int>(4);

    display(node);
    node = OnlyDistinct(node);
    display(node);



    return 0;
}