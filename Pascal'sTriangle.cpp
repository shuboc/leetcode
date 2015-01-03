class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> tri;
        for (int i=0; i<numRows; ++i) {
            vector<int> row;
            if (i == 0) 
                row.push_back(1);
            else {
                for (int j=0; j<=i; ++j) {
                    if (j == 0)
                        row.push_back(tri[i-1][0]);
                    else if (j == i)
                        row.push_back(tri[i-1].back());
                    else 
                        row.push_back(tri[i-1][j-1] + tri[i-1][j]);
                }
            }
            tri.push_back(row);
        }
        
        return tri;
    }
};