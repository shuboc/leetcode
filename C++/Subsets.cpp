class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(S.begin(), S.end());
        rec(0, S, subset, ans);
        return ans;
    }
    
    void rec(int i, const vector<int>& S, vector<int>& subset, vector<vector<int>>& ans) {
        if (i == S.size()) {
            ans.push_back(subset);
            return;
        }
        
        subset.push_back(S[i]);
        rec(i+1, S, subset, ans);
        subset.pop_back();

        rec(i+1, S, subset, ans);
    }
};