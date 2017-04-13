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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        vector<int> left = postorderTraversal(root->left);
        res.insert(res.end(), left.begin(), left.end());

        vector<int> right = postorderTraversal(root->right);
        res.insert(res.end(), right.begin(), right.end());

        res.push_back(root->val);

        return res;
    }
};

// Iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode *> s;
        s.push(root);

        while (s.size()) {
            TreeNode *node = s.top();
            if (!node->left && !node->right) {
                s.pop();
                res.push_back(node->val);
            }

            if (node->right) {
                s.push(node->right);
                node->right = NULL;
            }

            if (node->left) {
                s.push(node->left);
                node->left = NULL;
            }
        }

        return res;
    }
};
