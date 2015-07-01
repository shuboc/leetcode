class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return;
        
        // Find the last increasing pair, which is the position to perform permutation.
        // After this position, all numbers are descending-ordered.
        int swapIdx1 = -1;
        for (int i = size-1; i-1 >= 0; --i) {
            if (nums[i-1] < nums[i]) {
                swapIdx1 = i - 1;
                break;
            }
        }
        
        int left, right;
        if (swapIdx1 < 0) { 
            // Special cases where all elements are descending ordered like [3, 2, 1] or [1, 1]
            // Just reverse the whole vector in those cases.
            left = 0;
            right = size - 1;
        } else {
            // Find the smallest number among all numbers larger than nums[swapIdx1] in swapIdx+1:size-1
            // [2, 4, 3, 1] as example, 3 should be swapped with 2 for the next permutation.
            int swapIdx2, toSwap = INT_MAX;
            for (int i = size - 1; i >= swapIdx1 + 1; --i) {
                if (nums[i] > nums[swapIdx1] && nums[i] < toSwap) {
                    swapIdx2 = i;
                    toSwap = nums[i];
                }
            }

            swap(nums[swapIdx1], nums[swapIdx2]);
            
            // After swap, numbers between swapIdx+1:size-1 are descending ordered.
            // We should reverse the order as elements in swapIdx+1:size-1 is ascending-ordered in the next permutation
            left = swapIdx1 + 1;
            right = size-1;
        }

        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
};