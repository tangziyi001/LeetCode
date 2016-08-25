/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
unordered_map<double, int> mm;
public:
    int maxPoints(vector<Point>& points) {
        int sz = points.size();
        if(sz == 0) return 0;
        int maxp = 0;
        for(int i = 0; i < sz; i++){
            int ol = 1; // number of overlap points
            int ver = 0; // keep track of verticle lines
            for(int j = i+1; j < sz; j++){
                if(points[j].y == points[i].y && points[j].x == points[i].x){
                    ol++;
                    continue;
                }
                if(points[j].x-points[i].x == 0){
                    ver++;
                    continue;
                }
                double slope = (double)(points[j].y-points[i].y)/(points[j].x-points[i].x);
                if(mm.count(slope) == 0) mm[slope] = 1;
                else {
                    mm[slope]++;
                }
            }
            maxp = max(maxp, ol + ver);
            for(auto it = mm.begin(); it != mm.end(); it++){
                maxp = max(maxp, (*it).second + ol);
            }
            mm.clear();
        }
        return maxp;
    }
};