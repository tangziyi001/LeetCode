class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 1, j = nums.size()-1;
        while(i < j){
            int cnt = 0, mid = (i+j)/2;
            for(int i = 0; i < nums.size(); i++) if(nums[i] <= mid) cnt++;
            if(cnt > mid) j = mid;
            else i = mid+1;
        }
        return i;
    }
};