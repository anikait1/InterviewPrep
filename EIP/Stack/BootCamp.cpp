#include <iostream>
#include <stack>

struct Node {
    int data;
    Node* next;

    Node(int data)
        : data(data)
    {
        // constructor
    }
};

void PrintLinkedListReverse(Node* head) {
    std::stack<int> nodes;

    while (head) {
        nodes.push(head->data);
        head = head->next;
    }

    while (!nodes.empty()) {
        std::cout << nodes.top() << '\n';
        nodes.pop();
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(15);

    PrintLinkedListReverse(head);

    return 0;
}