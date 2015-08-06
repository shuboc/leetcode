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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        vector<TreeNode *> nodes;
        if (root) nodes.push_back(root);
        bool reverse = false;
        
        while (!nodes.empty()) {
            vector<TreeNode *> tmpNodes;
            vector<int> level;
            for (TreeNode *n : nodes) {
                level.push_back(n->val);
                if (n->left) tmpNodes.push_back(n->left);
                if (n->right) tmpNodes.push_back(n->right);
            }

            if (reverse) std::reverse(level.begin(), level.end());

            ans.push_back(level);
            nodes = tmpNodes;
            reverse = !reverse;
        }
        
        return ans;
    }
};