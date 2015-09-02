class Solution {
public:
    // When we meet '*', start to match s[i:] and p[j+1:]
    // If not matching, go back and match s[i+1:] and p[j+1:]
    // last_i and last_j are used to record the starting positions of matching
    bool isMatch(string s, string p) {
        int i = 0, j = 0, last_i = -1, last_j = -1;
        while (i < s.size()) {
            if (j < p.size() && p[j] == '*') {
                // Start matching the rest of s with p[j+1:]
                ++j;
                // Corner case:
                // trailing * in p => s matches p no matter what the remaining chars are
                if (j == p.size()) return true;
                last_i = i;
                last_j = j;
            } else if (j < p.size() && s[i] == p[j] || p[j] == '?') {
                ++i, ++j;
            } else if (last_i >= 0) {
                i = ++last_i;
                j = last_j;
            } else {
                return false;
            }
        }

        // Corner case:
        // s is at the end but p still has char => s matches p when remaining p are all '*'
        while (j < p.size() && p[j] == '*') ++j;
        return j == p.size();
    }
};