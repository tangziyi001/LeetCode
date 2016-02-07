// The array is not sorted
// The mark array can be substituted by bit set

// Array Mark 
class Solution {
public:
    vector<int> mark;
    int missingNumber(vector<int>& nums) {
        int sz = nums.size();
        mark.assign(sz+1,0);
        for(int i = 0; i < sz; i++){
            mark[nums[i]] = 1;
        }
        for(int i = 0; i <= sz; i++){
            if(mark[i] == 0) return i;
        }
    }
};