class Solution {
public:
    void rec(vector<int>& can, vector<vector<int>>& re, vector<int>& tmp, int idx, int target, int sz, int sum){
        if(idx == sz && sum == target){
            re.push_back(tmp);
            return ;
        } else if(idx == sz) return ;
        if(sum > target) return ;
        rec(can, re, tmp, idx+1, target, sz, sum);
        tmp.push_back(can[idx]);
        rec(can, re, tmp, idx, target, sz, sum+can[idx]);
        tmp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> re;
        int sz = candidates.size();
        vector<int> tmp(0,0);
        rec(candidates, re, tmp , 0, target, sz, 0);
        return re;
    }
};