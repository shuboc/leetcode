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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        ListNode *curl1 = l1;
        ListNode *curl2 = l2;
        
        while (cur) {
            int val = cur->val;
            if (curl1) {
                val += curl1->val;
                curl1 = curl1->next;
            }

            if (curl2) {
                val += curl2->val;
                curl2 = curl2->next;
            }
            
            if (val) {
                cur->val = val % 10;
            }
            
            // Create a new node if there will be a next digit
            if (val > 9 || curl1 || curl2) {
                cur->next = new ListNode(val/10);
            }
            
            cur = cur->next;
        }

        return head;
    }
};