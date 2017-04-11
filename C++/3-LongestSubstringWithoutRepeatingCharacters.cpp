class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        typedef unordered_map<char, int> Map;
        Map m;
        int last = -1;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            Map::const_iterator it = m.find(s[i]);
            if ((it != m.end() && it->second > last)) {
                maxLen = max(maxLen, i - 1 - last);
                last = it->second;
            }
            m[s[i]] = i;
        }

        return max(maxLen, (int)s.size() - 1 - last);
    }
};

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
