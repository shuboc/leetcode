class Solution {
public:
    int sqrt(int x) {
        long long i = 0;
        long long j = x/2+1;
        while (i <= j) {
            long long mid = (i+j)/2;
            if (mid*mid == x)
                return mid;
            else if (mid*mid < x)
                i = mid+1;
            else 
                j = mid-1;
        }
        
        return j;
    }
};