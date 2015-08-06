class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> ans;
        vector<int> subset;
        rec(0, S, subset, ans);
        return ans;
    }
    
    void rec(int i, const vector<int>& S, vector<int> subset, vector<vector<int>>& ans) {
        if (i == S.size()) {
            ans.push_back(vector<int>(subset));
            return;
        }
        
        int num = 1;
        while (i+num < S.size() && S[i] == S[i+num]) num++;
        
        // 0~k of S[i]
        rec(i+num, S, subset, ans);
        for (int k=0; k<num; ++k) {
            subset.push_back(S[i]);
            rec(i+num, S, subset, ans);
        }
        
        for (int k=0; k<num; ++k) {
            subset.pop_back();
        }
    }
};