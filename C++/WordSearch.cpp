class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        size_t m = board.size();
        if (m == 0) return false;
        size_t n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (exist(board, visited, i, j, word, 0)) return true;
            }
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, const string& word, int pos) {
        if (pos == word.size()) return true;
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || visited[i][j]) return false;
        
        // Search for 4 directions
        if (board[i][j] == word[pos]) {
            visited[i][j] = true;
            if (exist(board, visited, i, j+1, word, pos+1)) return true;
            if (exist(board, visited, i, j-1, word, pos+1)) return true;
            if (exist(board, visited, i+1, j, word, pos+1)) return true;
            if (exist(board, visited, i-1, j, word, pos+1)) return true;
            visited[i][j] = false;
        }
        
        return false;
    }
};