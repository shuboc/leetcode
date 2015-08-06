class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0)
            return 0;
        int num = A[0], i = 1, next = 1;
        while (i < n) {
            if (A[i] != num) {
                A[next] = A[i];
                num = A[i];
                ++next;
            }
            ++i;
        }
        
        return next;
    }
};