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
    unordered_map<int, int> inorder_idx;
    vector<int> preorder, inorder;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        
        for (int i=0; i<this->inorder.size(); ++i) {
            this->inorder_idx[inorder[i]] = i;
        }
        
        int cur = 0;
        return rec(0, inorder.size()-1, cur);
    }
    
    TreeNode *rec(int start, int end, int& cur) {
        if (start > end)
            return NULL;
            
        int rootVal = preorder[cur++];
        int rootIdx = inorder_idx[rootVal];
        TreeNode *newRoot = new TreeNode(rootVal);
        newRoot->left = rec(start, rootIdx-1, cur);
        newRoot->right = rec(rootIdx+1, end, cur);
        
        return newRoot;
    }
};