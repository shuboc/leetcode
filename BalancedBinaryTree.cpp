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
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        int d = depth(root);
        return (d >= 0);
    }
    
    int depth(TreeNode *root) {
        if (!root) 
            return 0;
        int l = depth(root->left);
        if (l < 0)
            return -1;
        int r = depth(root->right);
        if (r < 0)
            return -1;
        if (l-r > 1 || l - r < -1)
            return -1;
        return l > r ? l+1 : r+1;
    }
};