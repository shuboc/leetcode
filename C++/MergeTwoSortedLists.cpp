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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode *cur, *head, *i, *j;
        if (l1->val < l2->val) {
            head = cur = l1;
            i = l1->next;
            j = l2;
        } else {
            head = cur = l2;
            i = l1;
            j = l2->next;
        }
        
        while (i && j) {
            if (i->val < j->val) {
                cur->next = i;
                cur = i;
                i = i->next;
            } else {
                cur->next = j;
                cur = j;
                j = j->next;
            }
        }
        
        if (!i) {
            cur->next = j;
        } else if (!j) {
            cur->next = i;
        }
        
        return head;
    }
};