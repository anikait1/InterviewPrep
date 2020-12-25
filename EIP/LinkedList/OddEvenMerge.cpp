#include <iostream>
#include <array>

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

ListNode<int>* EvenOdd(ListNode<int>* head) {
    ListNode<int>* even = new ListNode<int>(0);
    ListNode<int>* odd = new ListNode<int>(0);
    std::array<ListNode<int>*, 2> tails{ even, odd };

    int turn = 0;
    while (head) {
        tails[turn]->next = head;
        tails[turn] = tails[turn]->next;
        turn ^= 1;
        head = head->next;
    }

    tails[1]->next = nullptr;
    tails[0]->next = odd->next;

    return even->next;
}

int main() {

    return 0;
}