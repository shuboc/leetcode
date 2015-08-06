class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        int patterns[1<<20] = {0}; // Use built-in array is faster than map!
        
        for (int i=0; i+9<s.size(); ++i) {
            string p = s.substr(i, 10);
            if (1 == patterns[hash(p)]++) 
                ret.push_back(p);
        }
        
        return ret;
    }
    
    // Customized hash function (length is only 10 and 4 letters (2 bits for a letter) => only need 20 bits)
    int hash(string s) {
        int ret = 0;
        for (int i=0; i<s.size(); ++i) {
            int bits;
            switch (s[i]) {
                case 'A':
                    bits = 0;
                    break;
                case 'T':
                    bits = 1;
                    break;
                case 'C':
                    bits = 2;
                    break;
                case 'G':
                    bits = 3;
                    break;
            }
            ret = (ret << 2) + bits;
        }

        return ret;
    }
};