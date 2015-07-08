class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int> > ans;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, comb, ans);
        return ans;
    }
    
    void helper(vector<int>& candidates, int start, int target, vector<int>& comb, vector<vector<int>>& ans) {
        if (target < 0 || start >= candidates.size() && target != 0) {
            return;
        }
        
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            comb.push_back(candidates[i]);
            helper(candidates, i + 1, target - candidates[i], comb, ans);
            comb.pop_back();
        }
    }
};