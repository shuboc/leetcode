class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Find k such that sum(k, n) > 0
        int left = 0, start = 0, diff = 0;
        for (int i=0; i<gas.size(); ++i) {
            diff += gas[i] - cost[i];
            left += gas[i] - cost[i];
            if (left < 0) {
                left = 0;
                start = i+1;
            }
        }
        
        if (diff < 0) // Impossible to find a route
            return -1;
        else
            return start;
        
    }
};