// Pay attention to the 0 denominator
// If the number of zeros is more than 1, then all entries are 0.
// If the number of zero is 1, then only the entry i such that nums[i] = 0 has positive value.

// Solution 1: With Division:
class Solution {
public:
    vector<int> re;
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return re;
        int pro = 1;
        int zc = 0;
        int zidx = 0;
        for(int i = 0; i < sz; i++){
            if(nums[i] == 0){
                zidx = i;
                zc++;
            }
            else pro*=nums[i];
        }
        if(zc == 1){
            re.assign(sz,0);
            re[zidx] = pro;
        }
        else if(zc > 1){
            re.assign(sz,0);
        }
        else{
            for(int i = 0; i < sz; i++){
                re.push_back(pro/nums[i]);
            }
        }
        return re;
    }
};

// Solution 2: Without Division: Two pass multiplication
class Solution {
public:
    vector<int> re;
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        re.assign(sz,1);
        for(int i = 1; i < sz; i++){
            re[i] = nums[i-1]*re[i-1];
        }
        int m = 1;
        for(int i = sz-1; i >= 0; i--){
            re[i] *= m;
            m *= nums[i];
        }
        return re;
    }
};