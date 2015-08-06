class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        for (int i = 0; i <= rowIndex; ++i) {
            vector<int> tmp;
            
            tmp.push_back(1);
            if (i >= 2) {
                for (int j = 0; j < ret.size() - 1; ++j) {
                    tmp.push_back(ret[j] + ret[j+1]);
                }
            }

            if (i >= 1)
                tmp.push_back(1);
            ret = tmp;
        }
        
        return ret;
        // Note that k-th element of n row is C(n, k) (binomial coefficient)
    }
};