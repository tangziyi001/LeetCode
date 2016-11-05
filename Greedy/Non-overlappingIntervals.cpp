/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// Greedy Interval Problem
class Solution {
public:
    static bool mycomp(Interval a, Interval b){
        if(a.start == b.start)
            return a.end < b.end;
        return a.start < b.start;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        int maxp = 1;
        int i = 1;
        sort(intervals.begin(), intervals.end(), mycomp);
        int right = intervals[0].end;
        while(i < intervals.size()){
            if(intervals[i].end < right)
                right = intervals[i].end;
            else if(intervals[i].start >= right){
                right = intervals[i].end;
                maxp++;
            }
            i++;
        }
        return intervals.size()-maxp;
    }
};