class Solution {
public:
    int maxProduct(int A[], int n) {
        int ans = A[0];
        
        int pos = A[0], neg = A[0];
        for (int i=1; i<n; ++i) {
            pos = max(1, pos); // Handle 0 case
            
            if (A[i] > 0) {
                pos *= A[i];
                neg *= A[i];
            } else {
                int tmp = pos;
                pos = neg * A[i];
                neg = tmp * A[i];
            }

            ans = max(ans, pos);
        }

        return ans;
    }
};