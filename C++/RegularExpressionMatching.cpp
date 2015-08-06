class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
    
    bool isMatch(const string &s, int i, const string &p, int j) {
        if (i == s.size() && j == p.size())
            return true;
            
        // A trailing *
        if (j+1 < p.size() && p[j+1] == '*') { 
            // Matches p[j] for 0 times
            if (isMatch(s, i, p, j+2)) return true; 
            // Matches p[j] for k times
            int k = 0;
            while (i+k < s.size()) {
                if (s[i+k] == p[j] || p[j] == '.') {
                    if (isMatch(s, i+k+1, p, j+2)) return true;
                } else {
                    return false;
                }
                ++k;
            }
        } else {
            // Matches s[i] with p[j]
            return (s[i] == p[j] || p[j] == '.') && isMatch(s, i+1, p, j+1);
        }
        
        return false;
    }
};