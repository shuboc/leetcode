class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        rec(n, n, "", ret);
        return ret;
    }

    // remaining '(' and ')'
    void rec(int left, int right, string s, vector<string>& ret) {
        if (left == 0 && right == 0) {
            ret.push_back(s);
            return;
        }
        
        if (left > 0)
            rec(left-1, right, s + "(", ret);
            
        // '(' must be more than ')'
        if (right > left)
            rec(left, right-1, s + ")", ret);
    }
};