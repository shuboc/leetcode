class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        for (int i=0; i<gas.size(); ++i) {
            int left = 0;
            bool success = true;
            for (int j=0; j<gas.size(); ++j) {
                int idx = i+j % gas.size();
                left += gas[idx];
                if (left < cost[idx]) {
                    success = false;
                    break;
                }
                left -= cost[idx];
            }
            
            if (success)
                return i;
        }
        
        return -1;
    }
};