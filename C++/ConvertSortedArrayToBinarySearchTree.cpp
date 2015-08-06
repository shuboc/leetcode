/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int n=0;
        ListNode *cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }

        return rec(head, 0, n-1);
    }
    
    // How to do a recurse to a linked list!?
    TreeNode *rec(ListNode *&cur, int start, int end) {
        if (start > end)
            return NULL;
            
        int mid = (start+end)/2;
        TreeNode *left = rec(cur, start, mid-1);
        
        TreeNode *newNode = new TreeNode(cur->val);
        newNode->left = left;
        cur = cur->next;
        
        newNode->right = rec(cur, mid+1, end);
        return newNode;
    }
};