class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        
        // Observe the pattern...
        for (int i=0; i<n; ++i) {
            int sz = ret.size();
            for (int j=sz-1; j>=0; --j) {
                ret.push_back(ret[j] + (1 << i));
            }
        }

        return ret;
    }
};