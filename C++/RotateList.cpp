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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k < 1) return head;

        ListNode *cur = head;
        int n = 1;
        while (cur->next) {
            ++n;
            cur = cur->next;
        }

        // Connect tail to head
        cur->next = head;

        // Rotate to the right by k places, i.e., rotate to the left by n - k % n places
        int i = n - k % n;
        while (i > 0) {
            cur = cur->next;
            --i;
        }
        head = cur->next;
        cur->next = NULL;

        return head;
    }
};