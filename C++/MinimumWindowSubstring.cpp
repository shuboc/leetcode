class Solution {
public:
    string minWindow(string s, string t) {
        size_t m = s.size(), n = t.size();
        int toFind[256] = {0};
        int hasFound[256] = {0};

        for (char ch : t) ++toFind[ch];

        int found = 0; // The number of found chars
        int start = 0, minStart = 0, minLen = INT_MAX;
        for (int i = 0; i < m; ++i) {
            char ch = s[i];
            if (toFind[ch] > 0) {
                ++hasFound[ch];
                if (hasFound[ch] <= toFind[ch]) ++found;
                if (found == n) {
                    char startCh = s[start];
                    while (!toFind[startCh] || hasFound[startCh] > toFind[startCh]) {
                        --hasFound[startCh];
                        startCh = s[++start];
                    }

                    if (i - start + 1 < minLen) {
                        minStart = start;
                        minLen = i - start + 1;
                    }
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};