class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix[0].size();

        // Save the zero-ing information for the first row and column
        bool emptyFirstRow = false, emptyFirstColumn = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                emptyFirstColumn = true;
            }
        }

        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                emptyFirstRow = true;
            }
        }

        // In place: reuse by setting 0 to the first row and column to record a column-/row-wise zero-ing
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // Zero-ing
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j) matrix[i][j] = 0;
            }
        }

        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i) matrix[i][j] = 0;
            }
        }

        // Empty the first row and column
        if (emptyFirstColumn) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }

        if (emptyFirstRow) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};