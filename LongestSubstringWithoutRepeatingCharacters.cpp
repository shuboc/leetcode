class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int used[128];
        memset(used, -1, sizeof(used));
        
        int maxLen = INT_MIN, len = 0, start = 0;
        for (int i=0; i<s.size(); ++i) {
            if (used[s[i]] >= start) {
                maxLen = max(maxLen, i-start);
                //len = i - used[s[i]];
                start = used[s[i]] + 1;
            }
            
            used[s[i]] = i;
        }
        
        maxLen = max(maxLen, (int)s.size() - start);
        return maxLen;
    }
};