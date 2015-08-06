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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;
        if (k < 2) return head;

        ListNode dummy(-1);
        dummy.next = head;

        ListNode *cur = head, *beginPrev = &dummy, *begin = head;
        int count = 1;
        while (cur) {
            if (count % k == 0) {
                ListNode *nxt = cur->next;
                reverse(begin, cur->next);

                // Manage the new links of the two ends
                beginPrev->next = cur;
                begin->next = nxt;

                // Reset the cur after reversing
                cur = begin;

                // The new begin
                beginPrev = begin;
                begin = nxt;
            }

            ++count;
            cur = cur->next;
        }

        return dummy.next;
    }

    // Reverse the list until reaching end
    ListNode *reverse(ListNode *begin, ListNode *end) {
        ListNode *last = NULL, *cur = begin;
        while (cur != end) {
            ListNode *nxt = cur->next;
            cur->next = last;
            last = cur;
            cur = nxt;
        }

        // Return the new head
        return last;
    }
};