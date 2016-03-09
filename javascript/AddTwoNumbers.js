/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    head = new ListNode(0)
    cur = head, p1 = l1, p2 = l2
    while (cur) {
        if (p1) {
            cur.val += p1.val
            p1 = p1.next
        }
        if (p2) {
            cur.val += p2.val
            p2 = p2.next
        }
        carry = cur.val / 10 | 0
        cur.val %= 10
        if (carry || p1 || p2) cur.next = new ListNode(carry)
        cur = cur.next
    }

    return head
};
