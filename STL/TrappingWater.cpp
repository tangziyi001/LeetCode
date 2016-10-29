// Monotonic Stack
class Solution {
public:
    stack<pair<int,int>> ss; // index, height
    int trap(vector<int>& height) {
        int sz = height.size();
        if(sz == 0) return 0;
        int sum = 0;
        for(int i = 0; i < sz; i++){
            pair<int,int> now = make_pair(i, height[i]);
            int cum = 0;
            int tmpHeight = 0;
            while(!ss.empty() && ss.top().second <= now.second){
                cum += (ss.top().second-tmpHeight)*(now.first-(ss.top().first+1));
                tmpHeight = ss.top().second;
                ss.pop();
            }
            if(!ss.empty()){
                cum += (now.second-tmpHeight)*(now.first-(ss.top().first+1));
            }
            ss.push(now);
            sum += cum;
        }
        return sum;
    }
};