class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while (i >=0 || j >= 0 || carry) {
            int bit = 0;
            if (i >= 0 && a[i] == '1') 
                ++bit;
            if (j >= 0 && b[j] == '1') 
                ++bit;
            if (carry) 
                ++bit;

            carry = bit / 2;
            ret = ((bit % 2) ? "1" : "0") + ret;

            --i;
            --j;
        }
        
        return ret;
    }
};