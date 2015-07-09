class Solution {
public:
    double myPow(double x, int n) {
        // This solution is based on this result:
        // -(-2147483648) = -2147483648,
        // -2147483648 / 2 = -1073741824,
        // -(-1073741824) = 1073741824,
        // and so on.
        if (n < 0) 
            return 1 / myPowPositive(x, -n); 
        else 
            return myPowPositive(x, n);
    }
    
    double myPowPositive(double x, int n) {
        if (n == 0)
            return 1;
            
        double p = myPowPositive(x, n/2);
        if (n % 2 == 0) {
            return p * p;
        } else {
            return p * p * x;
        }
    }
};