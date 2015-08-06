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
        
        // Use a stack to store all previous nodes
        stack<ListNode *> s;
        ListNode *node = head;
        while (node) {
            s.push(node);
            node = node->next;
        }
        
        // Pop from the stack by n times
        ListNode *remove = s.top(), *next = NULL;
        while (n > 1) {
            next = s.top();
            s.pop();
            remove = s.top();
            --n;
        }
        
        // Take care of links
        s.pop();
        if (s.size() > 0) {
            ListNode *cur = s.top();
            cur->next = next;
            return head;
        } else {
            return next;
        }
    }
};