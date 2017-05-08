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
        vector<Interval> ans;
        if(!intervals.size()) return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval pre = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            Interval& cur = intervals[i];
            if(cur.start <= pre.end) {
                pre.end = max(cur.end, pre.end);
            } else {
                ans.push_back(pre);
                pre = cur;
            }
        }
        ans.push_back(pre);
        return ans;
    }
    
private:
    static bool cmp(const Interval& a, const Interval& b) {
        return a.start < b.start || a.start == b.start && a.end < b.end; // important
    }
};
