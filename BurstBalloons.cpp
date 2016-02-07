// Divide and Conquer. Thinking in a reverse way.
#define MAXN 505
class Solution {
public:
    vector<int> all;
    int dp[MAXN][MAXN];
    int sz;
    int rec(int l, int r){
        if(dp[l][r] != -1)
            return dp[l][r];
        if(l + 1 == r){
            return 0;
        }
        int maxp = -(int)1E9;
        for(int i = l+1; i <= r-1; i++){
                int gain = all[i]*all[l]*all[r];
                maxp = max(maxp, gain + rec(l,i) + rec(i,r));
        }
        return dp[l][r] = maxp;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        sz = nums.size();
        all.push_back(1);
        for(int i = 0; i < sz; i++){
            all.push_back(nums[i]);
        }
        all.push_back(1);
        int re = rec(0,sz+1);
        return re;
    }
};