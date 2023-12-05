#include<iostream>
using namespace std;

class Node {
public:  
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    
    static void insertionatbegin(Node*& head, int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    static void insertatend(Node*& head, int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
};

Node* partition(Node* start, Node* end) {
    if (start == end || start == nullptr || end == nullptr)
        return start;

    Node* pivot_prev = start;
    Node* curr = start;
    int pivot = end->data;

    while (start != end) {
        if (start->data < pivot) {
            swap(curr->data, start->data);
            curr = curr->next;
        }
        start = start->next;
    }

    swap(curr->data, end->data);
    
    return pivot_prev;
}

void Quicksort(Node* start, Node* end) {
    if (start == end || start == nullptr || end == nullptr || start == end->next)
        return;

    Node* pivot_prev = partition(start, end);

    if (pivot_prev != nullptr && pivot_prev == start)
        Quicksort(pivot_prev->next, end);
    else if (pivot_prev != nullptr && pivot_prev->next != nullptr)
        Quicksort(pivot_prev->next->next, end);
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

void mergesort(Node*& head) {
    if (!head || head->next == nullptr)
        return;

    Node* fast = head->next;
    Node* middle = head;

    while (fast) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            middle = middle->next;
        }
    }

    Node* left = head;
    Node* right = middle->next;

    middle->next = nullptr;
    mergesort(left);
    mergesort(right);
    head = merge(left, right);
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertionsort(Node*& head) {
    if (!head || head->next == nullptr) {
        return head;
    }

    Node* sorted = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* j = sorted;
        Node* prev = nullptr;

        while (j != nullptr && j->data < curr->data) {
            prev = j;
            j = j->next;
        }

        if (prev != nullptr) {
            prev->next = curr;
        } else {
            sorted = curr;
        }

        Node* temp = curr->next;
        curr->next = j;
        curr = temp;
    }

    return sorted;
}

int main() {
    Node* head = nullptr;
    Node::insertionatbegin(head, 11);
    Node::insertionatbegin(head, 60);
    Node::insertatend(head, 15);
    Node::insertatend(head, 12);
    Node::insertatend(head, 1);

    cout << "Original List: ";
    display(head);

    cout << "\nAfter MergeSort: ";
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    mergesort(head);
    display(head);

    cout << "\nAfter QuickSort: ";
    Quicksort(head, tail);
    display(head);

    cout << "\nAfter InsertionSort: ";
    head = insertionsort(head);
    display(head);

    return 0;
}
