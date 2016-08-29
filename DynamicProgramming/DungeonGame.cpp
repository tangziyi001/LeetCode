typedef long long ll;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<ll>> dp(n, vector<ll>(m,0ll));
        int sta = 1;
        int ter = 1e8;
        while(sta <= ter){
            int mid = (sta+ter)/2;
            dp[0][0] = mid+dungeon[0][0];
            for(int i = 1; i < n; i++){
                dp[i][0] = dp[i-1][0] > 0 ? dp[i-1][0] + dungeon[i][0] : 0;
            }
            for(int j = 1; j < m; j++){
                dp[0][j] = dp[0][j-1] > 0 ? dp[0][j-1] + dungeon[0][j] : 0;
            }
            for(int i = 1; i < n; i++) for(int j = 1; j < m; j++){
                ll maxp = max(dp[i-1][j], dp[i][j-1]);
                if(maxp > 0)
                    dp[i][j] = maxp + dungeon[i][j];
                else dp[i][j] = 0;
            }
            if(dp[n-1][m-1] > 0)
                ter = mid-1;
            else
                sta = mid+1;
        }
        return sta;
    }
};