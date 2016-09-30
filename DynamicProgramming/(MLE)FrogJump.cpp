typedef long long ll;
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int sz = stones.size();
        cout << sz << endl;
        vector<vector<int>> dp(sz+1, vector<int>(1120,0));
        dp[0][0] = 1;
        for(int i = 1; i < sz; i++){
            int now  = stones[i];
            for(int j = i-1; j >= 0; j--){
                int pre = stones[j];
                int diff = now-pre;
                if(diff > 1110) break;
                dp[i][diff] |= dp[j][diff-1];
                dp[i][diff] |= dp[j][diff];
                dp[i][diff] |= dp[j][diff+1];
            }
        }
        int re = 0;
        for(int i = 0; i <= 1100; i++){
            re |= dp[sz-1][i];
        }
        return re;
    }
};