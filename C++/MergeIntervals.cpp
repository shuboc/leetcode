/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return intervals;
        
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        
        vector<Interval> ret(1, intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            Interval it = intervals[i];
            if (it.start > ret.back().end) {
                ret.push_back(it);
            } else if (it.end > ret.back().end) {
                ret.back().end = it.end;
            }
        }
        
        return ret;
    }
};