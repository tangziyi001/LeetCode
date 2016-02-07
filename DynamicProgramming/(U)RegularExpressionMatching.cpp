/*  if p[j-1] =='*', then j must be larger than 1 (j>1) and
 *  checked[i][j-2] (i.e. p[j-2] cancelled by '*')
 *  || checked[i-1][j] && (s[i-1] ==p[j-2] || p[j-2] =='.') (s[i-1] matches with p[j-2] or '.', )
 *  if p[j-1] !='*', checked[i-1][j-1] && (s[i-1] ==p[j-1] || p[j-1] =='.')(i.e. s[i-1] matches with p[j-1] or '.')
 */
class Solution {
public:
    vector<vector<int> > dp;
    bool isMatch(string s, string p) {
        int ssz = s.size();
        int psz = p.size();
        dp.assign(ssz+1, vector<int>(psz+1, 0));
        dp[0][0] = 1;
        dp[0][1] = 0;
        for(int j = 2; j <= psz; j++){
            dp[0][j] = (dp[0][j-2] && (p[j-1] == '*'));
        }
        for(int i = 1; i <= ssz; i++){
            for(int j = 1; j <= psz; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = (j > 1) && (dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')));
                }else{
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[ssz][psz];
    }
};