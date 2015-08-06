class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        if (strs.empty())
            return prefix;

        for (int i = 0; i < strs[0].size(); ++i) {
            char ch = strs[0][i];
            bool same = true;
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != ch)
                    same = false;
            }
            if (same)
                prefix += ch;
            else
                break;
        }
        
        return prefix;
    }
};