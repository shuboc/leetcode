class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        size_t m = obstacleGrid.size();
        if (m == 0) return 0;
        size_t n = obstacleGrid[0].size();
        vector<int> paths(n, 0);

        // Initialization
        if (obstacleGrid[0][0]) return 0;
        else paths[0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j]) {
                    paths[j] = 0;
                } else {
                    if (j > 0) paths[j] += paths[j-1];
                }
            }
        }

        return paths[n-1];
    }
};