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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head || !head->next)
            return NULL;
        
        // Use two pointers and make one of them goes first by n times
        ListNode *remove = head, *tail = head, *prev = NULL;
        for (int i=0; i<n; ++i) {
            tail = tail->next;
        }
        
        // Move the two pointers forward simultaneously until one reaches the end of the list
        while (tail != NULL) {
            tail = tail->next;
            prev = remove;
            remove = remove->next;
        }
        
        // Take care of the links
        if (remove == head) {
            ListNode *newHead = remove->next;
            delete remove;
            return newHead;
        } else {
            prev->next = remove->next;
            delete remove;
            return head;
        }
    }
};