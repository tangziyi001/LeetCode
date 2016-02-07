class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int sz = nums.size();
        int count = 0;
        sort(nums.begin(),nums.end());
        for(int a = 0; a < sz-2; a++){
            int c = sz-1;
            for(int b = a+1; b < sz-1; b++){
                while(nums[a]+nums[b]+nums[c] >= target && c > b)
                    c--;
                if(c <= b)
                    break;
                count+=(c-b);
            }
            
        }
        return count;
        
        
    }
};