class Solution {
public:
    int countDigitOne(int n) {
        
        // We calculate the ones at every digit of n

        // m = 100
        // n = 12034, a = 120, b = 34
        // The ones at the digit of 100: (120 / 10) * 100,
        // since every 1000 has 100 of ones.
        
        // n = 12134, a = 121, b = 34
        // The ones at the digit of 100: (120 / 10) * 100 + (34 + 1).
        // The additional (34 + 1) ones come from the digit of 100 of 12100 ~ 12134
        // comparing to the first case.
        
        // n = 12534, a = 125, b = 34
        // The ones at the digit of 100: (125 / 10) * 100
        // The additional 100 ones come from the digit of 100 of 12100 ~ 12199
        // comparing to the first case.
        
        int count = 0;
        // long type to avoid overflow
        for (long m = 1; m <= n; m *= 10) {
            int a = n / m, b = n % m;
            if (a % 10 == 0) count += (a / 10) * m;
            else if (a % 10 == 1) count += (a / 10) * m + b + 1;
            else count += (a / 10 + 1) * m;
        }
        
        return count;
    }
};