class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty())
            return;
        int height = board.size(), width = board[0].size();
        
        // Add 'O's which are at the boundaries.
        queue<int> qx, qy;
        for (int i=0; i<height; ++i) {
            if (board[i][0] == 'O') {
                qx.push(0);
                qy.push(i);
            }
            if (board[i][width-1] == 'O') {
                qx.push(width-1);
                qy.push(i);
            }
        }
        for (int i=0; i<width; ++i) {
            if (board[0][i] == 'O') {
                qx.push(i);
                qy.push(0);
            }
            if (board[height-1][i] == 'O') {
                qx.push(i);
                qy.push(height-1);
            }
        }
        
        // BFS to find all connected 'O's and mark them as 'Y'
        while (qx.size() > 0) {
            int x = qx.front(), y = qy.front();
            qx.pop();
            qy.pop();
            board[y][x] = 'Y';
            if (!isBoundary(x+1, y, board) && board[y][x+1] == 'O') {
                qx.push(x+1);
                qy.push(y);
            }
            if (!isBoundary(x-1, y, board) && board[y][x-1] == 'O') {
                qx.push(x-1);
                qy.push(y);
            }
            if (!isBoundary(x, y+1, board) && board[y+1][x] == 'O') {
                qx.push(x);
                qy.push(y+1);
            }
            if (!isBoundary(x, y-1, board) && board[y-1][x] == 'O') {
                qx.push(x);
                qy.push(y-1);
            }
        }
        
        // The 'O's left are not connected to any boundaries, i.e., surrounded by 'X's.
        // The 'Y's are the 'X's which are not surrounded by 'X's and should be restored.
        for (int i=0; i<height; ++i) {
            for (int j=0; j<width; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i=0; i<height; ++i) {
            for (int j=0; j<width; ++j) {
                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
        
    }
    
    bool isBoundary(int x, int y, vector<vector<char>>& board) {
        int height = board.size(), width = board[0].size();
        if (x >= width-1 || x <= 0 || y >= height -1 || y <= 0)
            return true;
        return false;
    }
};