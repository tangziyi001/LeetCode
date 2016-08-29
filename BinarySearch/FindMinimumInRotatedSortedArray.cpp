class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        int i = 0;
        int j = sz-1;
        while(i < j){
            int mid = (i+j)/2;
            if(nums[mid] >= nums[i] && nums[mid] > nums[j]){
                i = mid+1;
            } else {
                j = mid;
            }
        }
        return nums[j];
    }
};