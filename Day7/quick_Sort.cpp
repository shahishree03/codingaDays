#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* insert(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* cur = head;
    Node* tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            *newHead =  cur;
            prev = cur;
        } else {
            if (prev) prev->next = cur->next;
            else head = cur->next;
            tail->next = cur;
            tail = cur;
        }
        cur = cur->next;
    }

    if (!*newHead) *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) return head;

    Node* newHead = nullptr;
    Node* newEnd = nullptr;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    Node* tmp = newHead->next ? quickSortRecur(newHead, newEnd) : newEnd;
    tmp->next = pivot;
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

Node* quickSort(Node* head) {
    return quickSortRecur(head, nullptr);
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    head = insert(head, 10);
    head = insert(head, 4);
    head = insert(head, 7);
    head = insert(head, 12);

    cout << "Original Linked List: ";
    printList(head);

    head = quickSort(head);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}
