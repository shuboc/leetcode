class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Recursively fill every cell
        solveSudokuRecursive(board, 0, 0);
    }
    
    bool solveSudokuRecursive(vector<vector<char>>& board, int i, int j) {
        // Switch to the next row if this row is completed
        if (j >= 9) {
            return solveSudokuRecursive(board, i + 1, 0);
        }
        
        // Last column => the whole board is completed; return
        if (i >= 9) {
            return true;
        }
        
        // Switch to the cell in the next column
        if (board[i][j] != '.') {
            return solveSudokuRecursive(board, i, j + 1);
        }

        for (char c = '1'; c <= '9'; ++c) {
            board[i][j] = c;
            if (isValidSudoku(board, i, j)) {
                // Switch to the the cell in the next column
                if (solveSudokuRecursive(board, i, j + 1)) {
                    return true;
                }
            }
            board[i][j] = '.';
        }
        
        return false;
    }

    bool isValidSudoku(vector<vector<char> > &board, int r ,int c) {
        // Check the same column
        for (int i = 0; i < 9; ++i) {
            if (i != r && board[i][c] == board[r][c]) {
                return false;
            }
        }
        
        // Check the same row
        for (int j = 0; j < 9; ++j) {
            if (j != c && board[r][j] == board[r][c]) {
                return false;
            }
        }

        // Check the same block
        int k = (r / 3) * 3, l = (c / 3) * 3;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                if ((k + i != r || l + j != c) && board[k + i][l + j] == board[r][c]) {
                    return false;
                }
            }
        }

        return true;
    }
};