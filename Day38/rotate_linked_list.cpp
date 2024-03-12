/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     if (!head || k == 0) return head;
    Node* tail = head;
    int taillen=1;
    while(tail->next!=nullptr)
    {
         tail= tail->next;
         taillen++;
    }
    k=k%taillen;
    if(k==0) return head;
    taillen = taillen-k-1;
    Node* temp = head;
    for(int i=0;i<taillen;i++){
            temp= temp->next;
    }
Node* newnode=temp->next;
tail->next=head;
temp->next=nullptr;
return newnode;
}
