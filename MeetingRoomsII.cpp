// Loop over start and end points in order. Keep a counter.
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
typedef pair<double,int> pi;
class Solution {
public:
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int minMeetingRooms(vector<Interval>& intervals) {
        int sz = intervals.size();
        for(int i = 0; i < sz; i++){
            Interval now = intervals[i];
            pq.push(make_pair(now.start,0));
            pq.push(make_pair(now.end-0.01,1));
        }
        int cont = 0;
        int maxp = 0;
        while(!pq.empty()){
            pi tmp = pq.top(); pq.pop();
            if(tmp.second == 0)
                cont++;
            else{
                cont--;
            }
            maxp = max(maxp, cont);
        }
        return maxp;
    }
};