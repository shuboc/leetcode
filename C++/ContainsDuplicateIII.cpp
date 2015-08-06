class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0 || k < 1)
            return false;

        // Unlike similar problems, we need to iterate over the whole dictionary
        // to check if |nums[i] - nums[j]| <= t, which is of O(k) time complexity

        // To reduce complexity, note our aim is to find |nums[i] - nums[j]| <= t,
        // |nums[i]/t - nums[j]/t| <= 1, which also implies
        // |floor(nums[i]/t) - floor(nums[j]/t)| <= 1,
        // -1 + floor(nums[j]/t) <= floor(nums[i]/t) <= 1 + floor(nums[j]/t)

        // The equivalent statement is:
        // -1 + floor(nums[j]/t) > floor(nums[i]/t) or floor(nums[i]/t) > 1 + floor(nums[j]/t)
        // <=> |nums[i] - nums[j]| > t

        // The above statement means if we use floor(nums[j]/t) as key and nums[j] as value,
        // values with keys outside [-1 + floor(nums[j]/t), 1 + floor(nums[j]/t)]
        // will make |nums[i] - nums[j]| > t
        // We only need to check values with keys between [-1 + floor(nums[j]/t), 1 + floor(nums[j]/t)]
        // O(k) can be reduced to O(1)

        // Ref: http://bookshadow.com/weblog/2015/06/03/leetcode-contains-duplicate-iii/

        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int key = nums[i] / max(t, 1);
            for (int j = -1; j <= 1; ++j) {
                if (m.find(key + j) != m.end()) {
                    // Check |nums[i] - nums[j]| <= t; note it may overflow
                    if (abs((double) nums[i] / max(t, 1) - (double) m[key + j] / max(t, 1)) <= (t > 0 ? 1 : 0)) {
                        return true;
                    }
                }
            }

            m[key] = nums[i];
            if (i - k >= 0) {
                m.erase(nums[i - k] / max(t, 1));
            }
        }

        return false;
    }
};

// A shorter (but slower) solution
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0 || k < 1)
            return false;

        set<long long> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - k - 1 >= 0) {
                s.erase(nums[i - k - 1]);
            }

            // |x - nums[i]| <= t
            // -t + nums[i] <= x <= t + nums[i]
            // To find x in the current set, use -t + nums[i] as val of lower_bound
            // Note lower_bound(val) finds the first element whose value is greater than or equals val
            set<long long>::iterator it = s.lower_bound((long long)nums[i] - (long long)t);
            if (it != s.end() && abs(nums[i] - (*it)) <= t) {
                return true;
            }

            s.insert(nums[i]);
        }

        return false;
    }
};