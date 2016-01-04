class Solution {
public:
    int uniquePaths(int m, int n) {
        int paths[m];
        for (int i = 0; i < m; ++i) {
            paths[i] = 1;
        }

        for (int j = 0; j < n - 1; ++j) {
            for (int i = 1; i < m; ++i) {
                paths[i] += paths[i-1];
            }
        }

        return paths[m-1];
    }
};