/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode *root) {
        pushMin(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size() > 0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = s.top();
        s.pop();
        pushMin(cur->right);
        return cur->val;
    }
    
    void pushMin(TreeNode *node) {
        while (node) {
            s.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */