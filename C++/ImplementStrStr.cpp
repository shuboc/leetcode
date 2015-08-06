class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (!haystack || !needle)
            return -1;
        int hlen = strlen(haystack), nlen = strlen(needle);
        if (hlen < nlen)
            return -1;
            
        for (int i = 0; i < hlen-nlen+1; ++i) {
            bool match = true;
            for (int j = 0; j < nlen; ++j) {
                if (haystack[i+j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                return i;
        }
    
        return -1;
    }
};