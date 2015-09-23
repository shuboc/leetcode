class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;

        // Use cur to record the farest position I can reach within minSteps
        // Use next to record the farest position I can reach within (minSteps + 1)
        // When i > cur (current position is beyond reach), ++minSteps

        int cur = 0, next = 0, minSteps = 0;
        for (int i = 0; i < size; ++i) {
            if (i > cur) {
                cur = next;
                ++minSteps;
            }

            next = max(next, i + nums[i]);
        }

        return minSteps;
    }
};

// Time limit exceeded O(n^2) solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;

        vector<int> minSteps(size, std::numeric_limits<int>::max());
        minSteps[0] = 0;
        for (int i = 0; i < size; ++i) {
            int step = nums[i];
            for (int j = 1; j <= step && i + j < size; ++j) {
                minSteps[i + j] = min(minSteps[i + j], minSteps[i] + 1);
            }
        }

        return minSteps.back();
    }
};