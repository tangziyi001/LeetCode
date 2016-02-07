// Extend the window from the right side. When the sum >= s, shrink the window from the left side.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        int idx1 = 0;
        int idx2 = 0;
        int sum = nums[0];
        int minp = (int)1E9;
        while(idx1 < sz){
            if(sum >= s) {
                while(idx2 < idx1 && sum-nums[idx2] >= s){
                    sum -= nums[idx2];
                    idx2++; 
                }
                minp = min(minp, idx1-idx2+1);
            }
            idx1++;
            sum+=nums[idx1];
        }
        if(minp == (int)1E9) return 0;
        else return minp;
    }
};