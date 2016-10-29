class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int> > dp(prices.size()+1, vector<int>(5,-1e9));
        dp[0][0] = 0;
        for(int i = 1; i <= prices.size(); i++){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][1] = max(dp[i][1], dp[i-1][0] - prices[i-1]);
            dp[i][2] = dp[i-1][2];
            dp[i][2] = max(dp[i][2], dp[i-1][1] + prices[i-1]);
            dp[i][3] = dp[i-1][3];
            dp[i][3] = max(dp[i][3], dp[i-1][2] - prices[i-1]);
            dp[i][4] = dp[i-1][4];
            dp[i][4] = max(dp[i][4], dp[i-1][3] + prices[i-1]);
        }
        int maxp = 0;
        maxp = dp[prices.size()][0];
        maxp = max(dp[prices.size()][2], maxp);
        maxp = max(dp[prices.size()][4], maxp);
        return maxp;
    }
};