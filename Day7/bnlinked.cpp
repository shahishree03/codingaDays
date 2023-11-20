#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) : data(x), next(NULL) {}
};
Node* middle(Node* start, Node* last) {
    if (start == NULL) return NULL;
    Node* slow = start;
    Node* fast = start->next;

    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}
Node* binary_search(Node* head, int x) {
    Node* start = head;
    Node* last = NULL;

    while (last != start || last == NULL) {
        Node* mid = middle(start, last);
        if (mid == NULL) return NULL;

        if (mid->data == x) return mid;
        if (mid->data < x) start = mid->next;
        if (mid->data > x) last = mid;
    }

    return NULL;
}

Node* gettail(Node*& head) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}



int main() {
    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(7);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(10);

    int value = 7;
    if (binary_search(head, value) == NULL)
        cout << "Value not present" << endl;
    else
        cout << "Value is present" << endl;

    return 0;
}
