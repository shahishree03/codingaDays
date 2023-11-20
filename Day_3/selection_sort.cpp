#include<iostream>
using namespace std;
class Node
{
public:
 int data;
 Node* next;

 Node(int x)
 {
    data=x;
     next=nullptr;
 }
 void insertion(Node*& head, int data)
{
    Node* newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
};
void selection_ort(Node*& head)
{
    if(head==nullptr || head->next == nullptr)
    {
        return;
    }
   Node* curr;
   Node* next;
   int temp;
   for(curr=head;curr->next!=nullptr;curr=curr->next)
   {
   int min= curr->data;
    for(next=curr->next;next!=nullptr;next=next->next)
    {
        if(next->data < min)
        {
            temp=next->data;
            next->data = min;
            min =temp;
        }
        curr->data =min;
        
    }
   }

}
void printlist(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
 Node* head =NULL;
 Node h(10);
 h.insertion(head,10);
 h.insertion(head,4);
 h.insertion(head, 7);
 h.insertion(head,12);
 selection_ort(head);
 printlist(head);
}