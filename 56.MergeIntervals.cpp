/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval& v1, const Interval& v2) {
       return v1.start == v2.start ? (v1.end > v2.end) : (v1.start < v2.start); 
       return v1.start < v2.start;}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.empty()) return result;
        
        sort(intervals.begin(), intervals.end(), cmp);
        Interval tmp = intervals[0];
        for (int i=1;i<intervals.size();i++) {
            if (intervals[i].start > tmp.end) {
                result.push_back(tmp);
                tmp = intervals[i];
            } else {
                tmp.end = max(tmp.end, intervals[i].end);
            }
        }
        result.push_back(tmp);
        return result;
    }
};