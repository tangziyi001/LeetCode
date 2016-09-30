class Solution {
public:
    void rec(int idx, vector<int>& candidates, int& target, int& sz, set<vector<int>>& re, vector<int>& tmp, int sum){
        if(idx == sz && sum == target){
            re.insert(tmp);
            return ;
        }
        if(idx == sz)
            return ;
        if(sum > target) return ;
        rec(idx+1, candidates, target, sz, re, tmp, sum);
        tmp.push_back(candidates[idx]);
        rec(idx+1, candidates, target, sz, re, tmp, sum+candidates[idx]);
        tmp.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sz = candidates.size();
        set<vector<int>> re;
        vector<int> tmp;
        rec(0, candidates, target, sz, re, tmp,0);
        vector<vector<int>> all;
        for(auto it = re.begin(); it != re.end(); ++it){
            all.push_back(*it);
        }
        return all;
    }
};