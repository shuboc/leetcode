class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        if (strs.empty())
            return prefix;

        prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            string temp;
            while (j < strs[i].size() && j < prefix.size()) {
                if (strs[i][j] == prefix[j])
                    temp += strs[i][j];
                else
                    break;
                ++j;
            }
            prefix = temp;
        }
        
        return prefix;
    }
};