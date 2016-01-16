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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        
        for (Interval it : intervals) {
            if (it.end < newInterval.start) {
                ret.push_back(it);
            } else if (newInterval.end < it.start) {
                ret.push_back(newInterval);
                newInterval = it;
            } else {
                newInterval.start = min(newInterval.start, it.start);
                newInterval.end = max(newInterval.end, it.end);
            }
        }
        
        ret.push_back(newInterval);
        
        return ret;
    }
};