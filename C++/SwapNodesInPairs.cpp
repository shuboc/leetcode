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
    ListNode *swapPairs(ListNode *head) {
        if (!head)
            return NULL;

        if (!head->next)
            return head;
        
           
        ListNode *cur = head, *prev = NULL, *ret = head->next;
        while (cur && cur->next) {
            ListNode *nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = cur;
            if (prev)
                prev->next = nxt;
                
            prev = cur;
            cur = cur->next;
        }
        
        return ret;
    }
};