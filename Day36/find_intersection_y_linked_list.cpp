#include<iostream>
using namespace std;

class Sol{

Node* intersection(Node* A, Node* B)
{
Node* d1 = A;
  Node* d2 = B;
  while(d1=d2)
    {
   d1=d1==NULL?headB:d1->next;
      d2=d2==NULL?headA:d2->next;
    }
  return d1;
}
};
