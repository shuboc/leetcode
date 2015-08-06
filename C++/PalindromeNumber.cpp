class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int temp = x, reverse = 0;
        while (temp) {
            reverse *= 10;
            reverse += temp % 10;
            temp /= 10;
        }
        
        return x == reverse;
        
        /*
        // WTF!!
        int div = 1, div2 = 1;
        while (x/div >= 10) {
            div *= 10;
        }
        
        while (div > div2) {
            int first = (x/div) % 10;
            int last = (x/div2) % 10;
            if (first != last)
                return false;
            
            div /= 10;
            div2 *= 10;
        }
        
        return true;
        */
    }
};