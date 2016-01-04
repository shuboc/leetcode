class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t m = grid.size();
        if (m == 0) return 0;
        size_t n = grid[0].size();
        if (n == 0) return 0;

        // Initialization - use n+1 places to avoid processing boundary conditions
        vector<int> sum(n+1, INT_MAX);
        sum[1] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n+1; ++j) {
                sum[j] = grid[i][j-1] + min(sum[j], sum[j-1]);
            }
        }

        return sum[n];
    }
};