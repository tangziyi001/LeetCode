// Use vector erase. Keep a loop counter. 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        if(sz == 1) return 1;
        if(sz == 2) return 2;
        int loop = 2;
        int length = sz;
        for(int i = 2; i < sz && loop < sz; i++){
            if(nums[i] == nums[i-2]){
                nums.erase(nums.begin()+i);
                length--;
                i--;
            }
            loop++;
        }
        return length;
    }
};