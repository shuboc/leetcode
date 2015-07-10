class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int num = 1;
        
        for (int start = 0; start < (n+1)/2; ++start) {
            for (int j = start; j < n - start; ++j) {
                ans[start][j] = num++;
            }
            
            for (int i = start + 1; i < n - 1 - start; ++i) {
                ans[i][n - 1 - start] = num++;
            }
            
            if (n - 1 - start > start) { // In case there is only one row
                for (int j = n - 1 - start; j >= start; --j) {
                    ans[n - 1 - start][j] = num++;
                }
            }
            
            for (int i = n - 2 - start; i > start; --i) {
                ans[i][start] = num++;
            }
        }
        
        return ans;
    }
};