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
        if (!root)
            return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode *leftEnd = root->left;
        while (leftEnd && leftEnd->right) {
            leftEnd = leftEnd->right;
        }
        
        if (leftEnd) {
            leftEnd->right = root->right;
            root->right = root->left;
            root->left = NULL; // To avoid runtime error
        }
    }
};