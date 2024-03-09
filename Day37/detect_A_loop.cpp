/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   
public:
    ListNode *detectCycle(ListNode *head) {
       if(!head||!head->next) return nullptr;

      // ListNode* temp = head;
       ListNode* fast = head;
      ListNode* slow = head;
      ListNode* entry = head;
      while(fast->next!=nullptr&& fast->next->next!=nullptr)
      {
          fast=fast->next->next;
          slow=slow->next;
          if(slow==fast) {
     while(slow!=entry)
     {
         slow=slow->next;
         entry=entry->next;
     }
      return slow;
          }
      

    }
    return nullptr;
    }
};
