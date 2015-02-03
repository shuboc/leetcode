class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ret;
        sort(num.begin(), num.end());

        for (int i=0; i<num.size(); ++i) {
            for (int j=i+1; j<num.size(); ++j) {
                // Finding 2-Sum is O(n)
                int start = j+1, end = num.size()-1;
                while (start < end) {
                    if (num[start] + num[end] == target - num[i] - num[j]) {
                        vector<int> sol = {num[i], num[j], num[start], num[end]};
                        ret.push_back(sol);
                        start++;
                        end--;
                        
                        // To avoid duplication       
                        while (num[start] == num[start-1]) 
                            start++;
                        while (num[end] == num[end+1]) 
                            end--;
                    } else if (num[start] + num[end] < target - num[i] - num[j]) {
                        start++;
                    } else {
                        end--;
                    }
                }
                // To avoid duplication
                while (j<num.size()-1 && num[j] == num[j+1])
                    j++;
            }
            // To avoid duplication
            while (i<num.size()-1 && num[i] == num[i+1])
                i++;
        }
        
        return ret;
    }
};