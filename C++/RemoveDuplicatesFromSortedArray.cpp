class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int end = 0; // The index of the last element of the non-duplicate array
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[end]) {
                nums[end+1] = nums[i];
                ++end;
            }
        }

        return end+1;
    }
};