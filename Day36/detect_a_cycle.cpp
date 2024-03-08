class Sol{

bool isCycle(Node* head)
{
Node* slow = head;
Node* fast =fast->next;
while(fast!=nullptr && fast->next!=nullptr)
  {
slow=slow->next;
    fast=fast->next->next;//fast kuch jyada hi aage rhega
    if(slow==fast) return true
    
  }
  return false;
}

};
