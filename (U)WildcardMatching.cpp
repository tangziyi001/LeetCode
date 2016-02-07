/*
	1). if(p[j-1]!='*') f(i, j) = f(i-1, j-1) && (s[i-1]==p[j-1] || p[j-1]=='?')

	2). if(p[j-1]=='*') f(i, j) = f(i, j-1) || f(i-1, j)
*/

typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
    vvi dp;
    bool isMatch(string s, string p) {
         int ssz = s.size();
         int psz = p.size();
         if(ssz > 4000) return false;
         vi ttmp;
         ttmp.assign(psz+1,0);
         dp.assign(ssz+1,ttmp);
         dp[0][0] = 1;
         for(int j = 1; j <= psz; j++){
             dp[0][j] = dp[0][j-1] & (p[j-1] == '*');
         }
         for(int j = 1; j <= psz; j++){
             for(int i = 1; i <= ssz; i++){
                 if(s[i-1] == p[j-1] | p[j-1] == '?'){
                     dp[i][j] = dp[i-1][j-1];
                 }
                 else if(p[j-1] == '*'){
                     dp[i][j] = dp[i-1][j-1] | dp[i-1][j] | dp[i][j-1];
                 }
             }
         }
         if(dp[ssz][psz] == 1)
            return true;
         else
            return false;
    }
};