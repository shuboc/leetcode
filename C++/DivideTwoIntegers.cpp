class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        
        long long ans = 0;
        // Use long long to prevent overflow
        long long ldividend = abs((long long) dividend), ldivisor = abs((long long) divisor);
        
        long long remain = ldividend;
        while (remain >= ldivisor) {
            // Find temp so that temp is the largest number which is by right shifting (*2) ans is smaller than remain
            long long shift = 0;
            long long temp = ldivisor;
            while (temp < remain && (temp << 1) <= remain) {
                temp <<= 1;
                ++shift;
            }

            remain -= (ldivisor << shift);
            ans += ((long long) 1 << shift); // This is tricky! I have to cast 1 to long long
        }
        
        if ((dividend > 0) != (divisor > 0))
            ans = -ans;
            
        if (ans > INT_MAX || ans < INT_MIN) // Overflow
            return INT_MAX;

        return ans;
    }
};