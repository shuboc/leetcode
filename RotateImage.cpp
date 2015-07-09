class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        //vector<vector<int>> newMatrix(n, vector<int>(n, 0));
        
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) { // This is amazing!
                //newMatrix[j][n-1-i] = matrix[i][j];
                swap(matrix[i][j], matrix[n-1-j][i]);
                swap(matrix[n-1-j][i], matrix[n-1-i][n-1-j]);
                swap(matrix[n-1-i][n-1-j], matrix[j][n-1-i]);
            }
        }
    }
};