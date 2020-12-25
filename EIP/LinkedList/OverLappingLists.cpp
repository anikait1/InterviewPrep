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

bool IsOverlappingNodes(ListNode<int>* L1, ListNode<int>* L2) {
    std::unordered_set<ListNode<int>*> nodes;

    while (L1) {
        nodes.insert(L1);
        L1 = L1->next;
    }

    while (L2) {
        if (nodes.find(L2) != nodes.end()) {
            return true;
        } else {
            nodes.insert(L2);
        }

        L2 = L2->next;
    }

    return false;
}

ListNode<int>* OverLappingNodes(ListNode<int>* L1, ListNode<int>* L2) {
    int len_L1 = Length(L1);
    int len_L2 = Length(L2);

    AdvanceListByK(std::abs(len_L1 - len_L2), len_L1 > len_L2 ? &L1 : &L2);

    while (L1 && L2 && L1 != L2) {
        L1 = L1->next;
        L2 = L2->next;
    }

    return L1;
}

void AdvanceListByK(int k, ListNode<int>** L1) {
    while (k--) {
        *L1 = (*L1)->next;
    }
}

int Length(ListNode<int>* node) {
    int len = 0;
    while (node) {
        node = node->next;
        ++len;
    }
    return len;
}

int main() {

    return 0;
}