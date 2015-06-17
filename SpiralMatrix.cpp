class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int rows = matrix.size(), columns = rows > 0 ? matrix[0].size() : 0;
        vector<vector<bool> > visited(rows, vector<bool>(columns, false));
        
        int top = 0, left = 0, bot = rows, right = columns;
        while (left < right && top < bot) {
            // top 
            for (int i = left; i < right; ++i) {
                ret.push_back(matrix[top][i]);
            }
            
            // right
            for (int i = top + 1; i < bot - 1; ++i) {
                ret.push_back(matrix[i][right-1]);
            }
            
            // bottom
            if (top < bot - 1) {
                for (int i = right - 1; i >= left; --i) {
                    ret.push_back(matrix[bot-1][i]);
                }
            }

            // left
            if (left < right - 1) {
                for (int i = bot - 2; i > top; --i) {
                    ret.push_back(matrix[i][left]);
                }
            }
            
            ++left, ++top, --right, --bot;
        }
        
        return ret;
    }
};