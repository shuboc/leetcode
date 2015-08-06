class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int next = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != elem) {
                A[next] = A[i];
                ++next;
            }
        }
        
        return next;
    }
};