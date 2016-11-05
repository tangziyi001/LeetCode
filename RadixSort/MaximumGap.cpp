// The Radix Sort
// Use radix array to keep track of the number of elements with each ending bit
// Compute prefix sum and assign the number for each elements in reverse order
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        vector<int> tmp(nums.size(),0);
        int radix[2];
        if(nums.size() < 2) return 0;
        for(int k = 0; k < 32; k++){
            memset(radix, 0, sizeof(radix));
            for(int i = 0; i < nums.size(); i++)
                radix[(nums[i] & (1 << k))>>k]++;
            radix[1] += radix[0];
            //cout << k << " " << radix[0] << " " << radix[1] << endl;
            for(int i = nums.size()-1; i >= 0; i--)
                tmp[--radix[(nums[i] & (1 << k))>>k]] = nums[i];
            swap(nums,tmp);
        }
        int maxp = 0;
        for(int i = 1; i < nums.size(); i++){
           maxp = max(nums[i]-nums[i-1], maxp);
        }
        return maxp;
    }
};