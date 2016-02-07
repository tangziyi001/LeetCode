// Usage of hash map to store indices
class Solution {
public:
    unordered_map<int,int> mp;
    vector<int> re;
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        for(int i = 0; i < sz; i++){
            if(mp.find(target-nums[i]) != mp.end()){
                re.push_back(mp[target-nums[i]]+1);
                re.push_back(i+1);
                return re;
            }
            mp[nums[i]] = i;
        }
        return re;
    }
};