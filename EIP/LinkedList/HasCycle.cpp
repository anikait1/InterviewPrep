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

bool HasCycle(ListNode<int>* node) {
    std::unordered_set<ListNode<int>*> nodes;

    while (true && node != nullptr) {
        if (nodes.find(node) != nodes.end()) {
            return true;
        } else {
            nodes.insert(node);
        }

        node = node->next;
    }

    return false;
}

ListNode<int>* DetectLoop(ListNode<int>* node) {
    ListNode<int>* slow = node;
    ListNode<int>* fast = node;
    bool hasCycle = false;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle) {
        fast = node;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    } else {
        return nullptr;
    }
}

int CycleLength(ListNode<int>* node) {
    ListNode<int>* startCycle = DetectLoop(node);

    if (startCycle) {
        ListNode<int>* trav = startCycle;
        int length = 1;

        while (trav->next != startCycle) {
            ++length;
            trav = trav->next;
        }

        return length;
    } else {
        return 0;
    }
}

void RemoveCycle(ListNode<int>* node) {
    ListNode<int>* startCycle = DetectLoop(node);

    if (startCycle) {
        ListNode<int>* trav = startCycle;

        while (trav->next != startCycle) {
            trav = trav->next;
        }
        trav->next = nullptr;
    } else {
        return;
    }
}

int main() {

    return 0;
}