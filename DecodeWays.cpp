// DP: Pay attention to the leading 0.
// The transition equations are:
// dp[i] += dp[i-1] if the char is not 0
// dp[i] += dp[i-2] if the the previous char is not 0 and the combined number is between 1 and 26
class Solution {
public:
    vector<int> dp;
    int numDecodings(string s) {
        int sz = s.size();
        if(sz == 0) return 0;
        if(sz == 1) return (s[0] >= '1');
        dp.assign(sz+1,0);
        dp[0] = 1;
        dp[1] = (s[0] >= '1' ? 1 : 0);
        for(int i = 2; i < sz+1; i++){
            dp[i] = (s[i-1] == '0' ? 0 : dp[i-1]); // Single Digit
            int combine = (int)s[i-1]-(int)'0'+10*((int)s[i-2]-(int)'0');
            if(combine <= 26 && combine > 0 && s[i-2] != '0'){
                dp[i]+=dp[i-2];
            }
        }
        return dp[sz];
    }
};