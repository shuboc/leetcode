class Solution {
public:
    void sortColors(vector<int>& nums) {
        // One pass
        int i = 0, j = nums.size() - 1, next_zero = 0, next_two = nums.size() - 1;
        while (i <= next_two) {
            if (nums[i] == 0) {
                swap(nums[i], nums[next_zero]);
                ++next_zero;
                ++i; // either 0 or 1 after swapping; it's OK to move on i
            } else if (nums[i] == 1) {
                ++i;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[next_two]);
                --next_two; // May be 2; should check again without moving on i
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // counting sort
        int bucket[3] = {0};
        for (int i = 0; i < nums.size(); ++i) {
            ++bucket[nums[i]];
        }

        int idx = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < bucket[i]; ++j) {
                nums[idx++] = i;
            }
        }
    }
};