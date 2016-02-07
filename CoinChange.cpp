typedef vector<int> vi;
class Solution {
public:
    vi dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount+1,0);
        int sz = coins.size();
        if(sz == 0) return 0;
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            int minp = (int)1E9;
            for(int j = 0; j < sz; j++){
                if(i-coins[j] >= 0) minp = min(minp, 1+dp[i-coins[j]]);
            }
            dp[i] = minp;
        }
        return dp[amount] == (int)1E9 ? -1 : dp[amount];
    }
};