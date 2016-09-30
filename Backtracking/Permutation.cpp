class Solution {
public:
    vector<int> tmp;
    vector<int> mark;
    void rec(vector<vector<int>>& all, vector<int>& nums, int idx){
        if(idx == nums.size()){
            all.push_back(tmp);
            return ;
        }
        int sz = nums.size();
        for(int i = 0; i < sz; i++) if(mark[i] == 0){
            tmp.push_back(nums[i]);
            mark[i] = 1;
            rec(all, nums, idx+1);
            tmp.pop_back();
            mark[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all;
        mark.assign(nums.size(), 0);
        rec(all,nums, 0);
        return all;
    }
};