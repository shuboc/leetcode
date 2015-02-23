class Solution {
public:
    int sqrt(int x) {
        if (x == 0)
            return 0;
        
        // Newton's method
        double last = 0, res = 1;
        while (last != res) {
            last = res;
            res = (res + x/res) / 2; // (res*res + x) / (2*res) will be TLE! Don't know why?
        }
        
        return int(res);
    }
};