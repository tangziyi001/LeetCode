// DAG DP
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
class Solution {
public:
    vvi dp;
    int uniquePaths(int m, int n) {
        vi ttmp (n,0);
        dp.assign(m,ttmp);
        if(m == 0 || n == 0) return 0;
        if(m == 1 || n == 1) return 1;
        dp[m-1][n-1] = 0;
        for(int i = 0; i < n-1; i++){
            dp[m-1][i] = 1;
        }
        for(int i = 0; i < m-1; i++){
            dp[i][n-1] = 1;
        }
        dp[m-2][n-1] = 1;
        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >= 0; j--){
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        cout << dp[0][0] << endl;
        return dp[0][0];
    }
};