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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        
        // Find the lengths of the two lists
        int lenA = 0, lenB = 0;
        ListNode *node = headA;
        while (node) {
            ++lenA;
            node = node->next;
        }
        node = headB;
        while (node) {
            ++lenB;
            node = node->next;
        }
        
        // Traverse ||A|-|B|| nodes on the longer list
        ListNode *nodeA = headA, *nodeB = headB;
        int steps = 0;
        if (lenA > lenB) {
            steps = lenA - lenB;
            while (steps) {
                nodeA = nodeA->next;
                --steps;
            }
        } else {
            steps = lenB - lenA;
            while (steps) {
                nodeB = nodeB->next;
                --steps;
            }
        }
        
        // Traverse both lists step by step.
        // The two lists should both traverse min(|A|, |B|) nodes before reach the ends
        // or the commmon intersection in advance.
        while (nodeA && nodeB) {
            if (nodeA == nodeB)
                return nodeA;
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        
        return NULL;
    }
};