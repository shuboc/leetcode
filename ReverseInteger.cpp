#include <cmath>

class Solution {
public:
    int reverse(int x) {
        
        //Eliminate trailing zeros, e.g. 123000 -> 123 <-> 321
        while(x > 0 && x % 10 == 0) {
            x = x / 10;
        }
        
        //Find max digit in terms of power of 10
        int exp = 10;
        while (exp > 0 && x / (int) pow(10, exp) == 0) {
            --exp;
        }
        
		//Reverse digit-by-digit
        int ret = 0;
        for (int i = exp; i >= 0; --i) {
            ret += (x / (int) pow(10, i)) * (int) pow(10, exp - i);
            x = x % (int) pow(10, i);
        }
        return ret;
    }
};