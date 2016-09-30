class Solution {
public:
    static bool mycomp(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second){
            return a.first <= b.first;
        }
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> all;
        sort(nums.begin(), nums.end());
        int count = 1;
        int now = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == now){
                count++;
            } else {
                all.push_back(make_pair(now, count));
                now = nums[i];
                count = 1;
            }
        }
        all.push_back(make_pair(now,count));
        sort(all.begin(), all.end(), mycomp);
        vector<int> re;
        for(int i = 0; i < k; i++){
            re.push_back(all[i].first);
        }
        return re;
    }
};