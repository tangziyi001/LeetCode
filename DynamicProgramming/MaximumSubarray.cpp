// Don't use Kadane's algorithm: the subarray cannot be empty.
// DP: continues with the previous element or start at this element.
// dp[i] = max(nums[i], nums[i]+dp[i-1]);
class Solution {
public:
    vector<int> dp;
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        int maxp = -(int)1E9;
        dp.assign(sz,0);
        dp[0] = nums[0];
        if(sz == 1) return dp[0];
        maxp = dp[0];
        for(int i = 1; i < sz; i++){
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
            maxp = max(maxp, dp[i]);
        }
        return maxp;
    }
};