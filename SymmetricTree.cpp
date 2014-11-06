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
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;

        return isMirror(root->left, root->right);
    }
    
    // Condition that two trees are symmetric
    // 1. left == right == NULL
    //   or
    // 2. left->val == right->val
    // 3. left->left is symmetric to right->right
    // 4. left->right is symmetric to right->left
    bool isMirror(TreeNode *left, TreeNode *right) {
        if (!left)
            return !right;
            
        if (!right)
            return !left;
            
        if (left->val != right->val)
            return false;

        if (!isMirror(left->left, right->right))
            return false;
            
        if (!isMirror(left->right, right->left))
            return false;
            
        return true;
    }
};