class Solution {
public:
    vector<int> colOfQueenAtRow;

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n < 1) return ans;
        
        BOARD_LEN = n;
        vector<string> board(n, string(n, '.'));
        colOfQueenAtRow = vector<int>(n, -1);
        helper(0, board, ans);
        return ans;
    }
    
    void helper(int row, vector<string>& board, vector<vector<string> >& ans) {
        if (row == BOARD_LEN) {
            ans.push_back(board);
            return;
        }
        
        for (int col = 0; col < BOARD_LEN; ++col) {
            if (isValid(row, col, board)) {
                board[row][col] = 'Q';
                colOfQueenAtRow[row] = col;
                helper(row + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }
    
    bool isValid(int row, int col, const vector<string>& board) const {
        for (int i = 0; i < row; ++i) {
            // Check other rows and diagnostics
            // The same row does not need checking since we place only one queen per row
            if (colOfQueenAtRow[i] == col || abs(row - i) == abs(col - colOfQueenAtRow[i]))
                return false;
        }
        
        return true;
    }
    
private:
    int BOARD_LEN;
};

// The fastest solution
class Solution {
private:
    vector<vector<string> > res;
    int MASK;
public:
    vector<vector<string> > solveNQueens(int n) {
        MASK = (1 << n) - 1; // n of 1's
        vector<string> board(n, string(n, '.'));
        vector<vector<string> > ans;
        helper(0, 0, 0, board, ans, 0);

        return ans;
    }
    
    // row, ld and rd are bits representation for forbidden cells of the current row 
    // restricted by previous rows, left diagnotics and right diagnotics
    
    // The forbidden bits of ld shift a bit to the left after moving the next row, 
    // while rd shift a bit to the right
    // See http://www.cnblogs.com/TenosDoIt/p/3801621.html

    void helper(int row, int ld, int rd, vector<string> &board, vector<vector<string> > &ans, int curRow) {
        // Every row is filled with a queen => a solution found
        if (row == MASK) {
            ans.push_back(board);
            return;
        }
        
        int placeable = ~(row | ld | rd) & MASK;
        while (placeable) {
            // Find the rightmost bit, e.g., 101010 => 000010
            int rightmost = placeable & (~placeable + 1);
            
            // Add queens to the current row and search solution in next row recursively
            board[curRow][posToCol(rightmost)] = 'Q';
            helper(row | rightmost, (ld | rightmost) << 1, (rd | rightmost) >> 1, board, ans, curRow + 1);
            board[curRow][posToCol(rightmost)] = '.';
            
            // Remove the rightmost bit and move on to the next rightmost bit
            placeable -= rightmost;
        }
    }
    
    int posToCol(int pos) const {
        int col = 0;
        while (!(pos & 1)) {
            pos >>= 1;
            ++col;
        }
        return col;
    }
};