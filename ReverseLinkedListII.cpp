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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode *cur = &dummy, *begin, *beginPrev, *end;
        int count = 0;
        while (cur) {
            // Record the begin
            if (count == m - 1) {
                beginPrev = cur;
                begin = cur->next;
            }

            // Reverse between [m, n]
            if (count == n) {
                ListNode *nxt = cur->next;
                ListNode *newBegin = reverse(begin, cur->next);

                // Manage the links of the (m-1)th and (n+1)th node
                // cur will be the mth node after reversing
                // begin will be the nth node after reversing
                beginPrev->next = cur;
                begin->next = nxt;
                break;
            }

            ++count;
            cur = cur->next;
        }

        return dummy.next;
    }

    // Reverse the list until reaching end and return the new head
    ListNode *reverse(ListNode *begin, ListNode *end) {
        ListNode *last = NULL, *cur = begin;
        while (cur != end) {
            ListNode *nxt = cur->next;
            cur->next = last;
            last = cur;
            cur = nxt;
        }

        // The new begin
        return last;
    }
};