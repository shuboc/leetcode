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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if (!root) 
            return ret;
        
        vector<TreeNode *> nodes;
        nodes.push_back(root);
        
        while (nodes.size()) {
            vector<int> nums;
            vector<TreeNode *> tmpNodes;
            for (int i = 0; i < nodes.size(); ++i) {
                nums.push_back(nodes[i]->val);
                if (nodes[i]->left)  tmpNodes.push_back(nodes[i]->left);
                if (nodes[i]->right) tmpNodes.push_back(nodes[i]->right);
            }
            ret.push_back(nums);
            
            nodes.swap(tmpNodes);
        }
        
        return ret;
    }
};