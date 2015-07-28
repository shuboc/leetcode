class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for (int n : nums) {
            if (m.find(n) == m.end()) {
                m.insert(n);
            } else {
                return true;
            }
        }

        return false;
    }
};