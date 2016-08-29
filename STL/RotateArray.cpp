class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        if(sz == 0) return ;
        k = k%sz;
        vector<int> tmp(nums.begin()+(sz-k), nums.end());
        nums.erase(nums.begin()+(sz-k), nums.end());
        nums.insert(nums.begin(), tmp.begin(), tmp.end());
    }
};