class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return ;
        int p = 0;
        for(int i = 0; i < sz; i++){
            if(nums[i] != 0) nums[p++] = nums[i];
        }
        while(p < sz){
            nums[p++] = 0;
        }
        return ;
    }
};