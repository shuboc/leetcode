class Solution {
    vector<vector<string>> ret;
public:
    vector<vector<string>> partition(string s) {
        // DP approach
        vector<vector<string>> dp[s.size()];
        bool isPal[s.size()][s.size()];
        
        // Precalculated isPalindrome
        for (int i=0; i<s.size(); ++i) {
            for (int j=0; j+i<s.size(); ++j) {
                isPal[j][j+i] = (s[j] == s[j+i]) && ((i<2) || isPal[j+1][j+i-1]);
            }
        }
        
        // If s[j:i] is partible, s[0:i] is also partible.
        // Then, push s[j:i] to the existing solution set of s[0:j-1]
        vector<string> p;
        p.push_back(s.substr(0, 1));
        dp[0].push_back(p);
        
        for (int i=1; i<s.size(); ++i) {
            for (int j=0; j<=i; ++j) {
                string right = s.substr(j, i-j+1);
                if (isPal[j][i]) {
                    if (j == 0) {
                        vector<string> p;
                        p.push_back(right);
                        dp[i].push_back(p);
                    } else {
                        for (vector<string> p: dp[j-1]) {
                            vector<string> newP(p);
                            newP.push_back(right);
                            dp[i].push_back(newP);
                        }
                    }
                }
            }
        }
        
        return dp[s.size()-1];
    }
};