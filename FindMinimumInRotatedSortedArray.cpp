class Solution {
public:
    int findMin(vector<int> &num) {
        int start = 0, end = num.size()-1, ret = num[0];
        while (start+1 < end) {
            int mid = start + (end-start)/2;

            if (num[start] < num[mid]) {
                ret = min(ret, num[start]);
                start = mid+1;
            } else if (num[mid] < num[end]) {
                ret = min(ret, num[mid]);
                end = mid-1;
            } else {
                start++;
            }
        }

        ret = min(ret, num[start]);
        ret = min(ret, num[end]);
        return ret;
    }
};