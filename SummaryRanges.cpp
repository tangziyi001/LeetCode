// Corner Case: the last number
class Solution {
public:
    vector<string> re;
    vector<string> summaryRanges(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return re;
        if(sz == 1) {
            re.push_back(to_string(nums[0]));
            return re;
        }
        int idx = 0;
        for(int i = 1; i < sz; i++){
            if(nums[i] != nums[i-1] + 1){
                string tmp = "";
                tmp += to_string(nums[idx]);
                if(i != idx+1){
                    tmp += "->";
                    tmp += to_string(nums[i-1]);
                }
                re.push_back(tmp);
                idx = i;
            }
        }
        if(idx == sz-1){
            string tmp = "";
            tmp += to_string(nums[idx]);
            re.push_back(tmp);
        }
        if(idx != sz-1){
            string tmp = "";
            tmp += to_string(nums[idx]);
            tmp += "->";
            tmp += to_string(nums[sz-1]);
            re.push_back(tmp);
        }
        return re;
    }
};
