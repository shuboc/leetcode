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
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
    
    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode *> trees;
        if (start > end) {
            trees.push_back(NULL);
            return trees;
        }
        
        for (int i=start; i<=end; ++i) {
            vector<TreeNode *> leftTrees = generateTrees(start, i-1);
            vector<TreeNode *> rightTrees = generateTrees(i+1, end);
            
            for (TreeNode *l : leftTrees) {
                for (TreeNode *r : rightTrees) {
                    TreeNode *newNode = new TreeNode(i);
                    newNode->left = l;
                    newNode->right = r;
                    trees.push_back(newNode);
                }
            }
        }
        
        return trees;
    }
};