class Solution {
public:
    string convert(string s, int nRows) {

        if (s.empty() || nRows == 1)
            return s;

        string ret;
        for (int i = 0; i < nRows; ++i) {
            for (int j = i; j < s.size(); j += 2*nRows-2) {
                ret += s[j];
                if (i > 0 && i < nRows-1 && j+2*nRows-2-2*i < s.size())
                    ret += s[j+2*nRows-2-2*i];
            }
        }

        return ret;
    }
};