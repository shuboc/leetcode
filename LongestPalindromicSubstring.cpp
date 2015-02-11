class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> centers;
        // odd lengths
        for (int i=0; i<s.size(); ++i)
            centers.push_back(i);
       
        int R = 1;
        string maxStr = s.substr(0, 1);
        while (centers.size() > 0) {
            vector<int> newCenters;
            for (int i : centers) {
                if (i-R >= 0 && i+R < s.size() && s[i-R] == s[i+R]) {
                    newCenters.push_back(i);
                }
            }
           
            if (newCenters.size() > 0) {
                maxStr = s.substr(newCenters[0]-R, 2*R+1);
                R++;
            }
            centers = newCenters;
        }

        // even length
        centers.clear();
        for (int i=0; i<s.size()-1; ++i) {
            if (s[i]==s[i+1]) {
                centers.push_back(i);
            }
        }
        if (centers.empty())
            return maxStr;
        
        string evenMaxStr = s.substr(centers[0], 2);
        R = 1;
        while (centers.size() > 0) {
            vector<int> newCenters;
            for (int i : centers) {
                if (i-R >= 0 && i+1+R < s.size() && s[i-R] == s[i+1+R]) {
                    newCenters.push_back(i);
                }
            }

            if (newCenters.size() > 0) {
                if (2*R+2 > maxStr.size())
                    evenMaxStr = s.substr(newCenters[0]-R, 2*R+2);
                R++;
            }
            centers = newCenters;
        }

        return maxStr.size() > evenMaxStr.size() ? maxStr : evenMaxStr;
    }
};