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

void DeleteNode(ListNode<int>* node) {
    int data = node->next->data;
    node->data = data;
    node->next = node->next->next;
}

int main() {
    ListNode<int>* node = new ListNode<int>(15);
    node->next = new ListNode<int>(511);
    display(node);
    DeleteNode(node);
    display(node);


    return 0;
}