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
    ListNode *detectCycle(ListNode *head) {
        // See http://www.cnblogs.com/hiddenfox/p/3408931.html
        // head: X, cycle start: Y, meet: Z, 2*(XY+YZ) = XY+YZ+ZY+YZ (The distance of fast is twice of that of slow)

        // => ZY = XY. All we need is starting from Z and X respectively, and two pointers will meet at Y.
        if (!head || !head->next) return NULL;

        ListNode *slow = head->next, *fast = head->next->next;
        while (fast && fast != slow) {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }

        if (!fast) return NULL;

        ListNode *cur = head;
        while (cur != slow) {
            slow = slow->next;
            cur = cur->next;
        }

        return cur;
    }
};