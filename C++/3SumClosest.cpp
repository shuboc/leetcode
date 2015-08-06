class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());

        int sum, cur_diff = INT_MAX;
        for (int i=0; i<num.size(); ++i) {
            int start = i+1, end = num.size()-1;
            while (start < end) {
                int diff = abs(num[i] + num[start] + num[end] - target);
                if (diff < cur_diff) { 
                    sum = num[i] + num[start] + num[end];
                    cur_diff = diff;
                }

                if (num[i] + num[start] + num[end] > target)
                    end--;
                else if (num[i] + num[start] + num[end] < target)
                    start++;
                else
                    return target;
            }
        }

        return sum;
    }
};