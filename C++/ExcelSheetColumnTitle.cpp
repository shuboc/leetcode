class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while (n >= 1) {
            char ch = (n-1) % 26 + 65; //A-Z
            ret = ch + ret;
            n = (n-1) / 26;
        }
        
        return ret;
    }
};