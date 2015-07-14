class Solution {
public:
    // Ref: http://bangbingsyb.blogspot.tw/2014/11/leetcode-permutation-sequence.html
    string getPermutation(int n, int k) {
        // Pre-calculated factorial numbers
        vector<int> fac(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            fac[i] *= fac[i-1] * i;
        }

        vector<char> nums(n, 1);
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = i + 1 + '0';
        }
        
        --k; // Starts from 1
        string ans;
        // Calculate each digit one at a time
        for (int i = n; i > 0; --i) {
            int kk = k % fac[i]; // Every i! numbers form a cycle; we found out k' = (k / i!) in a cycle
            int numIdx = kk / fac[i - 1]; // Every number repeats (i-1)! times; we found the index in the remaining numbers
            ans.push_back(nums[numIdx]);
            nums.erase(nums.begin() + numIdx); // Remove the number just used
        }
        
        return ans;
    }
};