// Sort all intervals and compare each interval's start point with the previous end point
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
typedef pair<int,int> pi;
typedef vector<pi> vpi;
class Solution {
public:
    priority_queue<pi, vpi, greater<pi>> all;
    bool canAttendMeetings(vector<Interval>& intervals) {
        int sz = intervals.size();
        if(sz == 0) return true;
        for(int i = 0; i < sz; i++){
            all.push(make_pair(intervals[i].start,intervals[i].end));
        }
        int prev = 0;
        while(!all.empty()){
            pi now = all.top();all.pop();
            if(now.first < prev) return false;
            prev = now.second;
        }
        return true;
    }
};