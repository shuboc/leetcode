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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root)
            return ret;

        queue<TreeNode *> cur;
        queue<TreeNode *> next;
        cur.push(root);

        while (cur.size() > 0) {
            // Traverse the current level and put the next level in a queue
            vector<int> row;
            while (cur.size() > 0) {
                TreeNode *parent = cur.front();
                if (parent->left)
                    next.push(parent->left);
                if (parent->right)
                    next.push(parent->right);
                row.push_back(parent->val);
                cur.pop();
            }

            // Set the next level as the current level
            ret.push_back(row);
            swap(cur, next);
        }

        // Reverse the order
        vector<vector<int> > rev_ret;
        for (int i = ret.size() - 1; i>=0; --i)
            rev_ret.push_back(ret[i]);
        return rev_ret;
    }
};
