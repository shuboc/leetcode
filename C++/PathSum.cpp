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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;

        bool ret = false;
        if (!root->left && !root->right)
            ret = (sum == root->val);
        if (root->left)
            ret |= hasPathSum(root->left, sum-root->val);
        if (root->right)
            ret |= hasPathSum(root->right, sum-root->val);
        return ret;
    }
};