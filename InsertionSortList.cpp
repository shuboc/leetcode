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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return NULL;
        
        ListNode *dummy = new ListNode(INT_MIN);
        
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            
            ListNode *prev = dummy;
            while (prev->next && cur->val >= prev->next->val)
                prev = prev->next;
            
            cur->next = prev->next;
            prev->next = cur;
            
            cur = next;
        }

        return dummy->next;
    }
};