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
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy1 = new ListNode(INT_MIN), *dummy2 = new ListNode(INT_MIN);
        ListNode *cur1 = dummy1, *cur2 = dummy2, *cur = head;
        
        while (cur) {
            ListNode *next = cur->next;
            cur->next = NULL; // Don't forget to do this
            if (cur->val < x) {
                cur1->next = cur;
                cur1 = cur1->next;
            } else {
                cur2->next = cur;
                cur2 = cur2->next;
            }
            cur = next;
        }
        
        cur1->next = dummy2->next;
        return dummy1->next;
    }
};