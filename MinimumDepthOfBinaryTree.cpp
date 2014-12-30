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
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;

        int depth = INT_MAX;
        if (root->left) {
            int lDepth = minDepth(root->left);
            if (lDepth > 0 && lDepth < depth)
                depth = lDepth;
        }
        if (root->right) {
            int rDepth = minDepth(root->right);
            if (rDepth > 0 && rDepth < depth)
                depth = rDepth;
        }

        return depth + 1;
    }
};