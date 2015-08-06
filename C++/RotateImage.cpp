class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        vector<vector<int>> newMatrix(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                newMatrix[j][n-1-i] = matrix[i][j];
            }
        }
        return newMatrix;
    }
};

// In-place solution
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) { // This is amazing!
                swap(matrix[i][j], matrix[n-1-j][i]);
                swap(matrix[n-1-j][i], matrix[n-1-i][n-1-j]);
                swap(matrix[n-1-i][n-1-j], matrix[j][n-1-i]);
            }
        }
    }
};

// Magical! 90-degree rotate = transpose + horizontal reverse
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }

            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};