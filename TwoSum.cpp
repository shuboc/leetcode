class Solution {
public:
    // ~O(n) in time (unordered_map)
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        for (int i=0; i<numbers.size(); ++i) {
            m[numbers[i]] = i;
        }

        for (int i=0; i<numbers.size(); ++i) {
            int j = m[target-numbers[i]];
            if (j > 0 && j != i) {
                vector<int> ret;
                ret.push_back(i+1);
                ret.push_back(j+1);
                return ret;
            }
        }
    }
};