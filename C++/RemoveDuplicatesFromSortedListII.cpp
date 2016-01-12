// Internet version
// Without handling the special cases for head and tail
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;

        ListNode dummy(0);
        dummy.next = head;

        ListNode *cur = &dummy;

        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int val = cur->next->val;
                while (cur->next && cur->next->val == val) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }

        return dummy.next;
    }
};

// My version
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;

        ListNode dummy(0);
        dummy.next = head;

        // append cur to end if cur->val != lastVal and cur->next->val
        // Note the special cases of head and tail
        ListNode *end = &dummy, *cur = head;
        int lastVal;
        while (cur) {
            if ((!cur->next || cur->val != cur->next->val) && (cur == head || cur->val != lastVal)) {
                end->next = cur;
                end = cur;
            }

            lastVal = cur->val;
            cur = cur->next;
        }

        end->next = NULL;
        return dummy.next;
    }
};