// DP on colors. Maintain two min costs. For each house, choose color with the 
const int INF = (int)1E9;
class Solution {
public:
    vector<int> dp;
    int minCostII(vector<vector<int>>& costs) {
        int rsz = costs.size();
        if(rsz == 0) return 0;
        int csz = costs[0].size();
        if(csz == 1) return costs[0][0];
        dp.assign(csz,0);
        int min1,min2;
        for(int i = 0; i < rsz; i++){
            int minp1 = (i == 0 ? 0 : min1);
            int minp2 = (i == 0 ? 0 : min2);
            min1 = INF;
            min2 = INF;
            for(int j = 0; j < csz; j++){
                if(dp[j] != minp1 || minp1 == minp2){
                    dp[j] = minp1 + costs[i][j];
                }else{
                    dp[j] = minp2 + costs[i][j];
                }
                // Update min1 and min2
                if(min1 <= dp[j]){
                    min2 = min(min2, dp[j]);
                }
                else{
                    min2 = min1;
                    min1 = dp[j];
                }
            }
        }
        return min1;
    }
};