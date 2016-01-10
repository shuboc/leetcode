class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();

        int end = 1; // The index of the last element of the non-duplicate subarray
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[end] || nums[i] != nums[end-1]) {
                nums[++end] = nums[i];
            }
        }

        return end + 1;
    }
};