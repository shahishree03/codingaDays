class Sol{
public:
Node* reverseLinked(Node*& head){

  if(!head||!head->next) return head;
  Node* newhead= reverseLinked(head->next);
  head->next->next = head;
  head->next = nullptr;
  
}

bool isPallindrome(Node*& head int data){
if(!head||!head->next) return true;

Node* fast =head;
  Node* slow = head;
  while(fast!=nullptr && fast->nextt!=nullptr)
    {
     fast=fast->next;
      slow = slow->next;
    }

Node* first = head;
  Node* middhead= reverseLinked(slow->next);
  Node* second = slow;
  while(second!=nullptr)
    {
if(first->data!=second->data)
{
return false;
}
      

    }
  return true
  

}

};
