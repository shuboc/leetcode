class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.find(s) != wordDict.end())
            return true;
            
        // b[i]: true if s[0:i] is breakable
        vector<bool> breakable(s.size(), false);
            
        for (int i = 0; i < s.size(); ++i) {
            // b[i] is true when s[0:i] is breakable
            if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
                breakable[i] = true;
                continue;
            }
            
            // b[i] is true when there exists j in [0:i]
            // such that b[j] is breakable and s[j+1:i] is also breakable
            for (int j = 0; j < i; ++j) {
                if (breakable[j] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end()) {
                    breakable[i] = true;
                    break;
                }
            }
        }
        
        return breakable[s.size() - 1];
    }
};