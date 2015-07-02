class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = searchLowerBound(nums, target);
        int right = searchUpperBound(nums, target);
        
        vector<int> range;
        range.push_back(left);
        range.push_back(right);
        return range;
    }
    
    int searchLowerBound(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                end = mid - 1; // Keep searching to see if more targets are found at the left side
            }
        }
        
        if (start >= 0 && start < nums.size() && nums[start] == target) return start;
        return -1;
    }
    
    int searchUpperBound(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1; // Keep searching to see if more targets are found at the right side
            }
        }
        
        if (end >= 0 && end < nums.size() && nums[end] == target) return end;
        return -1;
    }
};