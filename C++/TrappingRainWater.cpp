class Solution {
public:
    int trap(int A[], int n) {
        int ans = 0;
        int h = INT_MIN;
        int h_i = -1;
        for (int i = 0; i < n; ++i) {
            if(h < A[i]) {
                h = max(h, A[i]);
                h_i = i;
            }
        }
        
        int left_max = -1;
        for (int i = 0; i < h_i; ++i) {
            if (A[i] < left_max) {
                ans += left_max - A[i];
            } else if (A[i] > left_max) {
                left_max = A[i];
            }
        }
        
        int right_max = -1;
        for (int i = n-1; i > h_i; --i) {
            if (A[i] < right_max) {
                ans += right_max-A[i];
            } else if (A[i] > right_max) {
                right_max = A[i];
            }
        }
        
        return ans;
    }
};