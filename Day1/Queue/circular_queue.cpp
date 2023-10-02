#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularQueue {
private:
    Node* front;
    Node* rear;
    Node* current;
    int maxSize;
    int currSize;

public:
    CircularQueue(int size) : front(nullptr), rear(nullptr), current(nullptr), maxSize(size), currSize(0) {}

    ~CircularQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return currSize == 0;
    }

    bool isFull() {
        return currSize == maxSize;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
            current = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        rear->next = front; // Circular link: rear points to front
        currSize++;
        cout << "Enqueued: " << value << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Returning -1 to indicate an error condition
        }

        int value = front->data;
        Node* temp = front;

        if (front == rear) {
            // Only one element in the queue
            front = nullptr;
            rear = nullptr;
            current = nullptr;
        } else {
            front = front->next;
            rear->next = front; // Circular link: rear points to front
            current = front;
        }

        delete temp;
        currSize--;
        cout << "Dequeued: " << value << endl;
        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = current;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != current);

        cout << endl;
    }
};

int main() {
    CircularQueue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.dequeue();
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6); // This will print an error message because the queue is full
    queue.display();
    return 0;
}
