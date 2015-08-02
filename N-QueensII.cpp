class Solution {
public:
    // Fastest solution so far
    // See N-Queens for details
    int MASK;

    int totalNQueens(int n) {
        if (n < 1) return 0;

        MASK = (1 << n) - 1;
        return helper(0, 0, 0);
    }

    int helper(int row, int rd, int ld) {
        if (row == MASK) return 1;

        int solCount = 0;
        int placeable = ~(row | rd | ld) & MASK;
        while (placeable > 0) {
            int p = (~placeable + 1) & placeable;
            solCount += helper(row | p, (rd | p) >> 1, (ld | p) << 1);
            placeable -= p;
        }

        return solCount;
    }
};

class Solution {
public:
    int N;
    vector<int> colOfQueenAtRow;

    int totalNQueens(int n) {
        if (n < 1) return 0;

        N = n;
        colOfQueenAtRow = vector<int>(n, -1);
        return helper(0);
    }

    int helper(int row) {
        if (row == N) {
            return 1;
        }

        int solCount = 0;
        for (int col = 0; col < N; ++col) {
            if (isValid(row, col)) {
                colOfQueenAtRow[row] = col;
                solCount += helper(row + 1);
            }
        }

        return solCount;
    }

    bool isValid(int row, int col) const {
        for (int r = 0; r < row; ++r) {
            if (col == colOfQueenAtRow[r] || abs(row - r) == abs(col - colOfQueenAtRow[r])) {
                return false;
            }
        }

        return true;
    }
};