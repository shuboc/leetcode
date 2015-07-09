class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> comb;
        vector<bool> visited(nums.size(), false);
        helper(nums, visited, comb, ans);

        return ans;
    }
    
    void helper(vector<int>& nums, vector<bool>& visited, vector<int>& comb, vector<vector<int>>& ans) {
        if (comb.size() == nums.size()) {
            ans.push_back(comb);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                comb.push_back(nums[i]);
                helper(nums, visited, comb, ans);
                comb.pop_back();
                visited[i] = false;
            }
        }
    }
};

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> ans;
        if (num.empty()) return ans;
        
        ans.push_back(vector<int>(1, num[0]));
        
        for (int i = 1; i < num.size(); ++i) {
            // Add an element once at a time to existing permutations
            int toInsert = num[i];
            int lastSize = ans.size(); // new permutations will change size of ans so we should keep it in advance
            for (int j = 0; j < lastSize; ++j) {
                for (int k = 0; k < ans[j].size(); ++k) {
                    vector<int> comb = ans[j];
                    comb.insert(comb.begin() + k, toInsert);
                    ans.push_back(comb);
                }
                
                ans[j].push_back(toInsert);
            }
        }
        
        return ans;
    }
};