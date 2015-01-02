class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
            
        string str = countAndSay(n-1);
        string ret;

        char num = str[0];
        int count = 1, idx = 1;
        while (1) {
            if (idx >= str.size()) {
                ret += to_string(count) + num;
                break;
            } else if (str[idx] != num) {
                ret += to_string(count) + num;
                num = str[idx];
                count = 1;
            } else {
                ++count;
            }
            
            ++idx;
        }
        
        return ret;
    }
};