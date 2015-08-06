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
    ListNode* reverseList(ListNode* head) {
        ListNode *last = NULL, *cur = head;
        while (cur) {
            ListNode *nxt = cur->next;
            cur->next = last;
            last = cur;
            cur = nxt;
        }

        return last;
    }
};