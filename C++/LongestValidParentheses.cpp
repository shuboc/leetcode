class Solution {
public:
    int longestValidParentheses(string s) {
        if (!s.size()) return 0;

        int maxLen = 0;
        stack<int> stk;
        // Record the index of parentheses

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (stk.size() > 0 && s[stk.top()] == '(') {
                    stk.pop();

                    // The top of the stack is the rightmost char
                    // which cannot form a valid parenthesis.
                    int len = stk.empty() ? (i + 1) : (i - stk.top());
                    maxLen = max(len, maxLen);
                } else {
                    stk.push(i);
                }
            }
        }

        return maxLen;
    }
};

// Too slow
class Solution {
public:
    int longestValidParentheses(string s) {
        if (!s.size()) return 0;

        int maxLen = 0;
        bool valid[s.size()] = {true};
        for (int l = 2; l < s.size(); l += 2) {
            for (int i = 0; i + l - 1 < s.size(); ++i) {
                if ((valid[i] && s[i+l-2] == '(' && s[i+l-1] == ')')
                    || (s[i] == '(' && valid[i+1] && s[i+l-1] == ')')) {
                        valid[i] = true;
                        maxLen = l;
                } else {
                    valid[i] = false;
                }
            }
        }

        return maxLen;
    }
};