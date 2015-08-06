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
    void flatten(TreeNode *root) {
        TreeNode *dummy = new TreeNode(-1);
        rec(root, dummy);
    }
    
    // Use pre to record the last traversed node (for both )
    void rec(TreeNode *root, TreeNode *&pre) {
        if (!root)
            return;
        
        TreeNode *right = root->right; // Remember it since root->left = root->right modified by children
        if (pre) {
            pre->right = root;
            pre->left = NULL;
        }
        
        pre = root;
        rec(root->left, pre); // After this call, pre will be the last element in the left subtree.
        rec(right, pre); 
    }
};