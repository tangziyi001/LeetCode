// DP Divide and Conquer
// Or Catalan Number
typedef long long ll;
class Solution {
public:
    // int numTrees(int n) {
    //     vector<ll> dp(n+1,0);
    //     dp[0] = 1;
    //     for(ll i = 1; i <= n; i++){
    //         dp[i] = (4*i-2)*dp[i-1]/(i+1);
    //     }
    //     return dp[n];
    // }
    int numTrees(int n) {
        vector<ll> dp(n+1,0);
        dp[1] = dp[0] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};