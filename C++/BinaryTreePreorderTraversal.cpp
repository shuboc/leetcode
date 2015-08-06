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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;

        vector<TreeNode *> queue;
        if (root)
            queue.push_back(root);
            
        while (queue.size() > 0) {
            TreeNode *cur = queue.back();
            queue.pop_back();
            ret.push_back(cur->val);
            if (cur->right)
                queue.push_back(cur->right);
            if (cur->left)
                queue.push_back(cur->left);
        }

        return ret;
    }
};