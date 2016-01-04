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

// Linear Time
class Solution {
public:
    int uniquePaths(int m, int n) {
        // (m - 1) + (n - 1) steps needed to the goal, including (m - 1) steps downward
        // Calculate C(m+n-2, m-1)
        // Use ull to hold avoid overflow
        unsigned long long ret = 1;
        int N = m + n - 2;
        int K = min(m, n) - 1;

        for (int i = 1; i <= K; ++i, --N) {
            ret = ret * N / i;
        }

        return ret;
    }
};