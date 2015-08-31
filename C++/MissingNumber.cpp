class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] < nums.size() && i != nums[i] && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i != nums[i]) {
                return i;
            }
        }

        return nums.size();
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            num ^= (nums[i] ^ (i+1));
        }

        return num;
    }
};