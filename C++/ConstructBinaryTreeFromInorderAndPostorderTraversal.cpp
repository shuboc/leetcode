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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int, int> inorder_idx; // O(1) look-up for position of current root in inorder list
        for (int i=0; i<inorder.size(); ++i) {
            inorder_idx[inorder[i]] = i;
        }
        
        // The current root is the last unvisited element in the postorder list
        int cur_idx = postorder.size();
        return rec(0, inorder.size()-1, inorder, postorder, inorder_idx, cur_idx);
    }
    
    // Recursive construct the binary tree
    TreeNode *rec(int start, int end, const vector<int>& inorder, const vector<int>& postorder, unordered_map<int, int>& inorder_idx, int& cur_idx) {
        if (start > end)
            return NULL;
        
        int rootVal = postorder[--cur_idx];
        TreeNode *newRoot = new TreeNode(rootVal);
        
        int root_idx = inorder_idx[rootVal];
        // Construct the right subtree first since we reversely traverse the postorder list.
        newRoot->right = rec(root_idx+1, end, inorder, postorder, inorder_idx, cur_idx); 
        newRoot->left = rec(start, root_idx-1, inorder, postorder, inorder_idx, cur_idx);
        return newRoot;
    }
};