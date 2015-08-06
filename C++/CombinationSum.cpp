class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, combination, ans);
        return ans;
    }
    
    void helper(vector<int>& candidates, int pos, int target, vector<int>& combination, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(combination);
            return;
        }
        
        if (pos == candidates.size() || target < 0) return;
        
        combination.push_back(candidates[pos]);
        helper(candidates, pos, target-candidates[pos], combination, ans);
        combination.pop_back();
        
        helper(candidates, pos+1, target, combination, ans);
    }
};