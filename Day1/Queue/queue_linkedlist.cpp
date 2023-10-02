#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node* next;

Node(int val)
{
    data= val;
    next = NULL;
}
};
class Queue{
Node* front;
Node* rear;
int currsize, max_size;

public:
Queue(int max_size )
{
    (*this).max_size = max_size;
     front = nullptr;
     rear= nullptr;
     currsize = 0;
     max_size = max_size;
}
~Queue()
{
    while(front!= nullptr)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}
bool isFull()
{
    return currsize == max_size;
}

bool isEmpty()
{
    return front == nullptr;
}

void push(int value)
{
    if(isFull())
    {
        cout<<"It is full\nExiting\n";
        return;
    }

    Node* newNode = new Node(value);
    if(isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next =newNode;
        rear= newNode;
    }
    currsize++;
    cout<<"Pushed element at "<<value<<endl;
}

int pop()
{
    if(isEmpty())
    {
        cout<<"It is empty bro!!"<<endl;
        return -1;
    }
    int poppedValue = front->data;
    Node* temp = front;
    front = front->next;
    delete temp;
    currsize--;
    if(front==nullptr)
    {
        rear= nullptr;
    }

    return poppedValue;
}

int top()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
      return -1;
    }
    return front->data;

}

void display()
{
    if(isEmpty())
    {
        cout<<"how to dispaly its empty"<<endl;
    }
    Node* temp = front;
    while(temp!= nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int size()
{
    return currsize;
}
};
int main()
{
Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout<<"\nDisplay elements ..........\n";
    q.display();
    cout << "\nThe peek of the queue before deleting any element: " << q.top() << endl;
    cout << "The size of the queue before deletion: " << q.size() << endl;
    cout << "The first element to be deleted: " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element: " << q.top() << endl;
    cout << "The size of the queue after deleting an element: " << q.size() << endl;
      cout<<"\nDisplay elements ..........\n";
    q.display();
    return 0;
}