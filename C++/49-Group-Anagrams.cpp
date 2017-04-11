class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        typedef unordered_map<string, vector<string>> Map;
        Map m;
        for (int i = 0; i < strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            m[key].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (Map::iterator i = m.begin(); i != m.end(); ++i) {
            res.push_back(i->second);
        }

        return res;
    }
};
