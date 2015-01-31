class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Record min values for row i, column j with 1-Dim vector
        // Values of row i+1 are no longer needed after calculating row i
        vector<int> min4Col(triangle.back());
        for (int i=triangle.size()-2; i>=0; --i) {
            for (int j=0; j<triangle[i].size(); ++j) {
                min4Col[j] = triangle[i][j] + min(min4Col[j], min4Col[j+1]);
            }
        }
        
        return min4Col[0];
    }
    
    /*
    //Too slow. Why?
    vector<vector<int>> dp;
    int minimumTotal(vector<vector<int> > &triangle) {
        dp = vector<vector<int>>(triangle.size()+1, vector<int>(triangle.size()+1, -1));
        return minimumTotal(triangle, 0, 0);
    }
    
    int minimumTotal(vector<vector<int> > &triangle, int level, int i) {
        if (dp[level][i] > 0)
            return dp[level][i];
        
        if (level == triangle.size())
            return 0;

        return dp[level][i] = triangle[level][i] + min(minimumTotal(triangle, level+1, i),
            minimumTotal(triangle, level+1, i+1));
    }*/
};