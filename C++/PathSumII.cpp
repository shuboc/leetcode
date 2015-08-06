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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ret;
        vector<int> path;
        rec(root, sum, path, ret);
        return ret;
    }
    
    void rec(TreeNode *root, int sum, vector<int>& path, vector<vector<int>>& ret) {
        if (!root)
            return;
        
        if (sum == root->val && !root->left && !root->right) {
            vector<int> path_copy(path);
            path_copy.push_back(root->val);
            ret.push_back(path_copy);
            return;
        }
        
        path.push_back(root->val);
        rec(root->left, sum-root->val, path, ret);
        rec(root->right, sum-root->val, path, ret);
        path.pop_back();
    }
};