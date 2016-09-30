class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int sz = nums.size();
        if(target == 0) return 0;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < sz; j++) {
                int now = nums[j];
                if(i-now < 0) continue;
                dp[i] += dp[i-now];
            }
        }
        return dp[target];
    }
};