class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> ans;
        unordered_map<string, vector<string>> m;
        
        for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (m.find(str) == m.end()) {
                m[str] = vector<string>(1, strs[i]);
            } else {
                m[str].push_back(strs[i]);
            }
        }
        
        for (unordered_map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it) {
            if (it->second.size() > 1) {
                ans.insert(ans.end(), it->second.begin(), it->second.end());
            }
        }

        return ans;
    }
};