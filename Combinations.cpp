class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        rec(1, n, k, comb, ans);
        return ans;
    }
    
    void rec(int i, int n, int k, vector<int>& comb, vector<vector<int>>& ans) {
        if (i > n && comb.size() != k)
            return;
        
        if (comb.size() == k) {
            ans.push_back(vector<int>(comb));
            return;
        }
        
        rec(i+1, n, k, comb, ans);
        comb.push_back(i);
        rec(i+1, n, k, comb, ans);
        comb.pop_back();
    }
};