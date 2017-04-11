class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        typedef unordered_map<string, int> Map;
        Map m;
        string str = s.substr(0, 10);
        m[str] = 1;
        for (int i = 10; i < s.size(); ++i) {
            str = str.substr(1, 9) + s[i];
            if (m.find(str) == m.end()) {
                m[str] = 1;
            } else {
                m[str] += 1;
            }
        }

        vector<string> res;
        for (Map::iterator i = m.begin(); i != m.end(); ++i) {
            if (i->second > 1) {
                res.push_back(i->first);
            }
        }
        return res;
    }
};

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
