/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      if (head == nullptr || head->next == nullptr)
            return true; // An empty list or a list with only one node is considered a palindrome

        // Find the length of the linked list
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        // Reverse the first half of the linked list
        ListNode* prev = nullptr;
        current = head;
        for (int i = 0; i < length / 2; i++) {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        // Adjust pointers for odd-length lists
        if (length % 2 != 0)
            current = current->next;

        // Compare the reversed first half with the second half of the list
        while (prev != nullptr && current != nullptr) {
            if (prev->val != current->val)
                return false;
            prev = prev->next;
            current = current->next;
        }

        return true;
    }
};
