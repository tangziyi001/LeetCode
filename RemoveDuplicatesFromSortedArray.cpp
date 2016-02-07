// When elements are removed in place, there must be a counter keeping track of the loop. 
// Solution1: Use vector erase.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int sz = nums.size();
       int tmp = 0;
       int length = sz;
       int loop = 0;
       for(int i = 0; i < sz && loop < sz; i++){
           if(i == 0) tmp = nums[i];
           else if(nums[i] != tmp) tmp = nums[i];
           else{
               nums.erase(nums.begin()+i);
               length--;
               i--;
           }
           loop++;
       }
       return length;
    }
};

// Solution2: Two Pointers: find unique element and place one by one into the vector
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        int p = 1;
        for(int i = 1; i < sz; i++){
            if(nums[i] != nums[i-1]){
                nums[p++] = nums[i];
            }
        }
        return p;
    }
};