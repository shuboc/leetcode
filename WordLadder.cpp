class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        vector<string> v = {start};
        int len = 0;

        while (v.size() > 0) {
            len++;
            vector<string> next;
            for (string s : v) {
                if (canTransform(s, end))
                    return len + 1;

                for (string newS : enumTransformation(s)) {
                    if (dict.find(newS) != dict.end()) {
                        next.push_back(newS);
                        dict.erase(newS); // No need to check again in the future
                    }
                }
               
            }
            
            v = next;
        }
       
        return 0;
    }
   
    bool canTransform(string a, string b) {
        if (a == b)
            return false;

        int diff = 0;
        for (int i=0; i<a.size(); ++i) {
            if (a[i] != b[i])
                diff++;
            if (diff > 1)
                return false;
        }
       
        return diff == 1;
    }
   
    vector<string> enumTransformation(string s) {
        vector<string> ret;
        for (int i=0; i<s.size(); ++i) {
            for (char c='a'; c <= 'z'; c++) {
                string newS = s;
                if (newS[i] != c) {
                    newS[i] = c;
                    ret.push_back(newS);
                }
            }
        }

        return ret;
    }
};