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

        // The idea is simple. A stack keeps track of visited nodes and print them if they are visited twice.

        // A stack to keep track of visited nodes. The value will 
        // be printed when a node is visited twice.
        vector<TreeNode *> visited;
            
        // Traverse the tree until leaf is reached and the stack is empty, 
        // which means all nodes are visited twice)
        TreeNode *cur = root;
        while (cur || !visited.empty()) {
            if (cur) {
                // Keep travering to the left child while pushing visited nodes onto the stack.
                visited.push_back(cur);
                cur = cur->left;
            } else {
                // Reach leaf. Print the parent value (last item in the stack) and traverse its right child.
                cur = visited.back();
                visited.pop_back();
                ret.push_back(cur->val);
                
                cur = cur->right;
            }
        } 
            
        return ret;
    }
};