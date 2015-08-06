int compare(string a, string b) {
    return a+b > b+a;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        string ret;
        vector<string> v;
        for (auto n:num) {
            v.push_back(to_string(n));
        }
        
        sort(v.begin(), v.end(), compare);
        for (int i=0; i<v.size(); ++i) {
            ret += v[i];
        }
        
        // Remove leading 0's
        while (ret[0] == '0' && ret.size() > 1)
            ret.erase(0, 1);
        
        return ret;
    }
};

