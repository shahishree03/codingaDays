#include<iostream>
using namespace std;
class Node{
    public:
int data;
Node* next;
Node(int val) : data(val), next(nullptr) {}
};
class circular1{
    Node* head;
    public:
    circular1(): head(nullptr) {}
    ~circular1()
    {
        if(head==nullptr){ return;}
        Node* temp = head->next;
        head->next =nullptr;
     while(temp!= nullptr)
    {
        Node* current = temp;
        temp = temp->next;
        delete current;
    }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
    void insert(int value)
    {
        Node* n = new Node(value);
        if(head == nullptr)
        {
            head= n;
            head ->next = head;
        }
        else 
        {
            Node* temp = head;
            while(temp->next != head)
            {
                temp= temp->next;
            }
            temp->next = n;
            n->next =temp;
        }
        
    }
    void display()
    {
        if(isEmpty()){
            cout<<"CIrcular Linked list"<<endl;
        }

        Node* temp = head;
        do{

cout<<temp->data<<" ";
temp = temp->next;
        }while (temp!=head);
        cout<<endl;
    }
};

class circular{
Node* tail;

public:
circular(): tail(nullptr) {}

~circular()
{
    if(tail == nullptr)
    {
        return;
    }

    Node* temp = tail->next;
    tail->next = nullptr;

    while(temp!= nullptr)
    {
        Node* current = temp;
        temp = temp->next;
        delete current;
    }

}
bool isEmpty()
{
    return tail == nullptr;
}

void insert(int value)
{
    Node* n = new Node(value);
    if(tail == nullptr)
    {
        tail = n;
        tail ->next = tail;
    }
    else{
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }
}

void display()
{
    if(isEmpty())
    {
        cout<<"Circular Linked list is empty......"<<endl;
        return;
    }
    Node* temp = tail->next;
    do{
        cout<<temp->data<<" ";
        temp= temp->next;
    }while(temp != tail->next);
    cout<<endl;

}
};
int main()
{ 
 circular cll;
    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.insert(4);
    cll.insert(5);

    cout << "Circular Linked List: ";
    cll.display();

 
}