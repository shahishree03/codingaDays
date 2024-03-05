#include<iostream>
using namespace std;
class Node{
private:
int data;
Node* next;

public:
Node(int data)
{
this->data=data;
  this->next = nullptr;
}
Node* insertion(int data)
{
Node* newNode= new Node(data);
  if(this->next==nullptr) {
    this->next=newNode;
}
  else{
  Node* temp = this;
  while(temp->next!=nullptr)
  {
temp=temp->next;
  }
    temp->next= newNode;
    return this;
    
  }

  int getEnd() const{
  const Node* tail= this;
    int count_last_node=0;
    while(tail!=nullptr)
      {
tail=tail->next;
        count_last_node++;
      }
    return count_last_node;
  }

  void print() {
const Node* temp = this;
    while(temp!=nullptr)
      {
cout<<temp->data<<" ";
        temp=temp->next;
      }
  }

  friend Node* removeEndNthNode(Node*& head, int count);

};

Node* removeEndNthNode(Node*& head, int count)
{
if(!head) return nullptr;
  int end_node=head->getEnd();
  int nth=end_node- count;
//if targett index is head then 
  if(nth==0)
  {
Node* temp = head;
    head= head->next;
    delete temp;
    return head;
  }

  Node* prev= nullptr;
  Node* curr= head;
  
}
for(int i=0;i<nth, curr!=nullptr;i++)
{
prev=curr;
  curr=curr->next;
}

if(curr=nullptr) return head;//no node is there then return 
prev->next= curr->next;
delete  curr;

return head;
int main()
{
Node* head;
  head= new Node(1);
  head->insertion(2);
  head->insertion(3);
  head->insertion(4);
  head->insertion(5);
cout<<"Before./n";
  head->print();
  head= removeEndNthNode(head, 3);
  cout<<"After...../n";
}
