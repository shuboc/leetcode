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
    ListNode *sortList(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return head;
        
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *head2 = slow->next;
        slow->next = NULL;
        ListNode *newHead1 = sortList(head);
        ListNode *newHead2 = sortList(head2);
        return merge(newHead1, newHead2);
    }
    
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummy = new ListNode(0), *cur = dummy, *cur1 = head1, *cur2 = head2; 
        while (cur1 && cur2) {
            if (cur1->val < cur2->val) {
                cur->next = cur1;
                cur1 = cur1->next;
            } else {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        
        if (!cur1)
            cur->next = cur2;

        if (!cur2)
            cur->next = cur1;
        
        return dummy->next;
    }
};