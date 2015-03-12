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
        ListNode *cur = head, *last = NULL, *next, *begin, *end; // begin, end is the begin and end of reversed part
        
        int pos = 1;
        
        while (pos <= n) {
            if (pos == m-1 && pos > 0) { // The (m-1)-th element
                last = cur;
            }
            
            if (pos == m) {
                begin = end = cur;
            }
            
            next = cur->next;

            if (pos > m) {
                cur->next = begin;
                end->next = next;
                begin = cur;
            }
            
            cur = next;
            ++pos;
        }
        
        if (last) {
            last->next = begin;
            return head;
        } else {
            return begin;
        }
    }
};