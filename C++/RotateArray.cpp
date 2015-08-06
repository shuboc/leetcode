class Solution {
public:
    void rotate(int nums[], int n, int k) {
        int copy[n];
        for (int i = 0; i < n; ++i) {
            copy[(i + k) % n] = nums[i];
        }
        
        for (int i = 0; i < n; ++i) {
            nums[i] = copy[i];
        }
    }
};