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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;
        
        if (root->left)
            ret = inorderTraversal(root->left);
        
        if (root)
            ret.push_back(root->val);
        
        if (root->right) {
            vector<int> right = inorderTraversal(root->right);
            for (int i = 0; i < right.size(); ++i) {
                ret.push_back(right[i]);
            }
        }
            
        return ret;
    }
};