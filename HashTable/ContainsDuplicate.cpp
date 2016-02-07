class Solution {
public:
    set<int> mark;
    bool containsDuplicate(vector<int>& nums) {
        int sz = nums.size();
        for(int i = 0; i < sz; i++){
            if(mark.find(nums[i]) == mark.end()) mark.insert(nums[i]);
            else return true;
        }
        return false;
    }
};