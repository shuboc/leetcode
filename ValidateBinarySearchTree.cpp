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
    bool isValidBST(TreeNode *root) {
        return rec(root, LONG_MAX, LONG_MIN);
    }

    bool rec(TreeNode *root, long maxx, long minn) {
        if (!root)
            return true;

        if (root->val >= maxx || root->val <= minn)
            return false;

        if (root->left) {
            if (!rec(root->left, root->val, minn))
                return false;
        }

        if (root->right) {
            if (!rec(root->right, maxx, root->val))
                return false;
        }

        return true;
    }
};