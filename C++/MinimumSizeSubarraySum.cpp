// Time: O(n), extrac space: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        size_t m = nums.size();
        int len = INT_MAX, left = 0, right = 0, sum = 0;

        while (right < m) {
            while (sum < s && right < m) {
                sum += nums[right++];
            }

            while (sum >= s) {
                len = min(len, right-left);
                sum -= nums[left++];
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};

// Time: O(n^2), extra space: O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        size_t m = nums.size();

        int sum[m] = {0};
        for (int l = 0; l < m; ++l) {
            for (int i=0; i+l<m; ++i) {
                sum[i] += nums[i+l];
                if (sum[i] >= s) return l+1;
            }
        }

        return 0;
    }
};