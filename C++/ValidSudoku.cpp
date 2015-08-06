class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        
        for (int i=0; i<9; ++i) {
            bool hasNum[9] = {false};
            for (int j=0; j<9; ++j) {
                char num = board[i][j];
                if (num != '.') {
                    if (hasNum[num-49])
                        return false;
                    hasNum[num-49] = true;
                }
            }
        }
        
        for (int i=0; i<9; ++i) {
            bool hasNum[9] = {false};
            for (int j=0; j<9; ++j) {
                char num = board[j][i];
                if (num != '.') {
                    if (hasNum[num-49])
                        return false;
                    hasNum[num-49] = true;
                }
            }
        }

        for (int k=0; k<9; k+=3) {
            for (int l=0; l<9; l+=3) {
                bool hasNum[9] = {false};
                for (int i=0; i<3; ++i) {
                    for (int j=0; j<3; ++j) {
                        char num = board[i+k][j+l];
                        if (num != '.') {
                            if (hasNum[num-49])
                                return false;
                            hasNum[num-49] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};