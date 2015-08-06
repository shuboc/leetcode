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

        ListNode dummy(0);
        dummy.next = head;

        ListNode *cur = head, *prev = &dummy;
        int count = 1;
        while (cur) {
            ListNode *nxt = cur->next;
            if (count % k == 0) {
                // The last element of k-reversed-list will be prev for the next k-reversed-list
                prev = reverse(prev, cur->next);
            }
            ++count;
            cur = nxt;
        }

        return dummy.next;
    }

    // Reverse the list until reaching end (adjust to maintain the links of head and tail more easily)
    ListNode *reverse(ListNode *prev, ListNode *end) {
        ListNode *last = end, *head = prev->next, *cur = head;
        while (cur != end) {
            ListNode *nxt = cur->next;
            cur->next = last;
            last = cur;
            cur = nxt;
        }

        prev->next = last;

        // Return the last element
        return head;
    }
};