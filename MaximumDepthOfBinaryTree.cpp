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
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->right && !root->left) return 1;
        int l = 0;
        int r = 0;
        if (root->left) l = maxDepth(root->left);
        if (root->right) r = maxDepth(root->right);
        if (l > r) return l + 1;
        else return r + 1;
    }
};