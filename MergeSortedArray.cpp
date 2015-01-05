class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Compare the last elements of the two arrays
        // and put the larger one to the buttom
        int i = m - 1, j = n - 1, next = n + m - 1;
        while (i >= 0 || j >= 0) {
            if (i >= 0 && j >= 0) {
                if (A[i] > B[j]) {
                    A[next] = A[i];
                    --i;
                } else {
                    A[next] = B[j];
                    --j;
                }
                --next;
            } else if (i >= 0) {
                // Done; do nothing
                break;
            } else if (j >= 0) {
                A[next] = B[j];
                --j;
                --next;
            }
        }
    }
};