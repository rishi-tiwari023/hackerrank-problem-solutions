#include <bits/stdc++.h>
using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
    explicit SinglyLinkedListNode(int nodeData) : data(nodeData), next(nullptr) {}
};

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* reversedHead = nullptr;
    while (head != nullptr) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(head->data);
        node->next = reversedHead;
        reversedHead = node;
        head = head->next;
    }
    return reversedHead;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    SinglyLinkedListNode* head = nullptr;
    SinglyLinkedListNode* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        SinglyLinkedListNode* node = new SinglyLinkedListNode(x);
        if (head == nullptr) head = tail = node; else { tail->next = node; tail = node; }
    }

    SinglyLinkedListNode* rh = reverse(head);
    bool first = true;
    for (SinglyLinkedListNode* cur = rh; cur != nullptr; cur = cur->next) {
        if (!first) cout << ' ';
        cout << cur->data;
        first = false;
    }
    cout << "\n";
    return 0;
}


