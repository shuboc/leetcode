/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        vector<int> left = inorderTraversal(root->left);
        res.insert(res.end(), left.begin(), left.end());

        res.push_back(root->val);

        vector<int> right = inorderTraversal(root->right);
        res.insert(res.end(), right.begin(), right.end());

        return res;
    }
};

// Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode *> s; // Store visited (in-order) nodes, and visit them again later
        TreeNode *cur = root;
        while (cur || s.size() > 0) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                TreeNode* visited = s.top();
                s.pop();
                res.push_back(visited->val);
                cur = visited->right;
            }
        }

        return res;
    }
};
