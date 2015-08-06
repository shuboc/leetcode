class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0;
        int max = INT_MIN;
        for (int i=0; i<n; ++i) {
            sum += A[i];
            if (sum > max)
                max = sum;
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
};