class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t m = nums1.size(), n = nums2.size();
        if ((m+n) % 2 == 1) return getKth(nums1, nums2, (m+n)/2 + 1);
        else return (getKth(nums1, nums2, (m+n)/2 + 1) + getKth(nums1, nums2, (m+n)/2)) * 0.5;
    }

    double getKth(vector<int>& nums1, vector<int>& nums2, int k) {
        size_t m = nums1.size(), n = nums2.size();
        if (m > n) return getKth(nums2, nums1, k);

        int left = 0, right = m-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int j = k - 1 - mid;
            if (j < n && nums1[mid] >= nums2[j]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        int a = INT_MIN, b = INT_MIN;
        if (left >= 1) a = nums1[left-1]; // end of while loop, left == right + 1
        if (k-1-left >= 0) b = nums2[k-1-left];

        return max(a, b);
    }
};