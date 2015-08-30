class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty())
            return 1;

        // For each iteration, swap to let nums[i] = i+1, e.g., [4, 1, 0, 2] => [2, 1, 0, 4] => [1, 2, 0, 4]
        // (i = 0, nums[i] = 1)
        // Stop swapping if i not in [1, N-1] or two swapping element are the same (to avoid infinity loop)
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != i+1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i+1) {
                // The first missing element!
                return i+1;
            }
        }

        return nums.size() + 1;
    }
};