class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int, int> map;
        for (int i=0; i<num.size(); ++i) {
            if (++map[num[i]] > num.size()/2)
                return num[i];
        }
    }
};