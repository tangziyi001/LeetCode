// Indices Memorization
class Solution {
public:
    vector<string> re;
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int sz = nums.size();
        int start = lower;
        for(int i = 0; i < sz; i++){
            int now = nums[i];
            if(now-start == 1){
                re.push_back(to_string(start));
            }
            else if(now-start>1){
                re.push_back(to_string(start)+"->"+to_string(now-1));
            }
            start = now+1;
        }
        if(upper - start == 0){
            re.push_back(to_string(start));
        }
        else if(upper - start >= 1){
             re.push_back(to_string(start)+"->"+to_string(upper));
        }
        return re;
    }
};