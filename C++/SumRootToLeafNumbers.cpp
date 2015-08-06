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
    int sumNumbers(TreeNode *root) {
        return sumNumbers(root, 0);
    }

    int sumNumbers(TreeNode *root, int path) {
        if (!root)
            return 0;

        path = path*10 + root->val;
        
        if (!root->left && !root->right)
            return path;


        int ret = 0;
        ret += sumNumbers(root->left, path);
        ret += sumNumbers(root->right, path);
        return ret;
    }
};