class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (!s) 
            return 0;
        int before = false;
        int i = 0;
        int l = 0;
        while (s[i] != '\0') {
            if (s[i] == ' ') {
                before = true;
            } else if (s[i] != ' ' && before) {
                before = false;
                l = 1;
            } else {
                ++l;
            }
            ++i;
        }
        
        return l;
    }
};