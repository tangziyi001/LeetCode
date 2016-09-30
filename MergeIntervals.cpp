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
        int start = -1;
        int right = -1;
        vector<pair<int,int>> pi;
        for(int i = 0; i < intervals.size(); i++){
            pi.push_back(make_pair(intervals[i].start, intervals[i].end));
        }
        vector<Interval> re;
        sort(pi.begin(), pi.end());
        for(int i = 0; i < pi.size(); i++){
            if(pi[i].first > right){
                if(start != -1 && right != -1){
                    re.push_back(Interval(start, right));
                }
                start = pi[i].first;
                right = pi[i].second;
            } else {
                right = max(right, pi[i].second);
            }
        }
        if(start != -1 && right != -1)
            re.push_back(Interval(start, right));
        return re;
    }
};