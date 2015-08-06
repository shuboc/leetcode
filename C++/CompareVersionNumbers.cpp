class Solution {
public:
    int compareVersion(string version1, string version2) {
        char *cstr1 = new char[version1.size()+1], *cstr2 = new char[version2.size()+1];
        strcpy(cstr1, version1.c_str());
        strcpy(cstr2, version2.c_str());
        
        vector<int> a, b;
        char *tok1 = strtok(cstr1, ".");
        while (tok1) {
            a.push_back(atoi(tok1));
            tok1 = strtok(NULL, ".");
        }
        
        char *tok2 = strtok(cstr2, ".");
        while (tok2) {
            b.push_back(atoi(tok2));
            tok2 = strtok(NULL, ".");
        }
        
        int i = 0, j = 0;
        while (i < a.size() || j < b.size()) {
            int v1 = 0, v2 = 0;
            if (i < a.size())
                v1 = a[i];
            if (j < b.size())
                v2 = b[j];
            if (v1 > v2)
                return 1;
            if (v1 < v2)
                return -1;
            ++i;
            ++j;
        }

        return 0;
    }
};