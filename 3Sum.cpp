class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ret;
        sort(num.begin(), num.end());
        
        for (int i=0; i<num.size(); ++i) {
            int start = i+1, end = num.size()-1;
            while (start < end) {
                if (num[start] + num[end] == -num[i]) {
                    vector<int> triple = {num[i], num[start], num[end]};
                    ret.push_back(triple);
                    start++;
                    end--;
                    // To avoid non-unique answers.
                    while (start < end && num[start] == num[start-1]) start++;
                    while (start < end && num[end] == num[end+1]) end--;
                } else if (num[start] + num[end] > -num[i]) {
                    end--;
                } else {
                    start++;
                }
            }
            
            // To avoid non-unique answers.
            while (i<num.size()-1 && num[i] == num[i+1])
                i++;
        }
        
        return ret;
    }
};