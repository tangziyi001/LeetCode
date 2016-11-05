// Greedy replacement when scanning increasing sequence
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 3) return false;
        vector<int> gd;
        for(int i = 0; i < sz; i++){
            if(gd.size() == 0){
                gd.push_back(nums[i]);
            } else if(gd.size() == 1){
                if(nums[i] > gd[0]) gd.push_back(nums[i]);
                else gd[0] = nums[i];
            } else {
                if(nums[i] > gd[1]) return true;
                else if(nums[i] < gd[0]) gd[0] = nums[i];
                else if(nums[i] > gd[0] && nums[i] < gd[1]) gd[1] = nums[i];
            }
        }
        return false;
    }
};