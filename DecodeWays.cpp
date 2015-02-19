class Solution {
public:
    int dp[100000];

    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return rec(0, s);
    }
    
    int rec(int i, const string& s) {
        if (s.empty())
            return 0;
        
        if (i == s.size())
            return 1;
            
        if (dp[i] >= 0)
            return dp[i];

        if (s[i] == '0')
            return dp[i] = 0;

        int ret = 0;
        ret += rec(i+1, s);
        if (i+1 < s.size() && stoi(s.substr(i, 2)) < 27)
            ret += rec(i+2, s);

        return dp[i] = ret;
    }
};