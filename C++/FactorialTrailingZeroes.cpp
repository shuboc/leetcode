class Solution {
public:
    int trailingZeroes(int n) {
        int z = 0;
        int five = 5;

        // Find the number of 5 in n!
        while (five <= n) {
            int cur = five;
            while (cur % 5 == 0) {
                ++z;
                cur /= 5;
            }
            five += 5;
        }

        return z;
    }
};