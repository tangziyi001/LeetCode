class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int> &nums) {
        dp.push_back(0);
        int sz = nums.size();
        for(int i = 0; i < sz; i++){
            int tmp = dp[i];
            dp.push_back(nums[i]+tmp);
        }
    }

    int sumRange(int i, int j) {
        return dp[j+1]-dp[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
