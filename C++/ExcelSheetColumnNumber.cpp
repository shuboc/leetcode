class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            ret *= 26;
            ret += s[i] - 64;
        }
        
        return ret;
    }
};