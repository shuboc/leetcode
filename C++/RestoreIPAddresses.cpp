class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        rec(0, 0, "", s, ans);
        return ans;
    }
    
    void rec(int i, int segment, string ip, const string& s, vector<string>& ans) {
        // Do not keep recursing when there are 4 segments
        if (segment == 4) {
            if (i == s.size())
                ans.push_back(ip);
            return;
        }
        
        for (int len=1; len<=3 && i+len<=s.size(); len++) {
            string subip = s.substr(i, len);
            if (isValidNum(subip)) {
                string newip = ip + subip;
                if (segment < 3) newip.append(".");
                rec(i+len, segment+1, newip, s, ans);
            }
        }
    }
    
    
    bool isValidNum(string s) {
        if (s.empty() || s.size() > 3)
            return false;
            
        int ret = stoi(s);
        if (ret > 255 || ret < 0)
            return false;
            
        // Prevent leading 0 like '012'
        if (s[0] == '0' && s.size() > 1)
            return false;
            
        return true;
    }
    
};