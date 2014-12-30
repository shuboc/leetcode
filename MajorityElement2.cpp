class Solution {
public:
    int majorityElement(vector<int> &num) {
        
        // Moore's majority vote algorithm
        int cand = 0, count = 0;
        for (int i=0; i<num.size(); ++i) {
            if (count == 0) {
                cand = num[i];
                count = 1;
            } else {
                (num[i] == cand) ? ++count : --count;
            }
        }
        
        return cand;
    }
};