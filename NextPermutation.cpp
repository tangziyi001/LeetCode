class Solution {
public:
    void myswap(int* a, int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        int i = sz-1;
        while(i > 0 && nums[i] <= nums[i-1])
            i--;
        if(i <= 0) sort(nums.begin(),nums.end());
        else{
            int j = sz-1;
            while(nums[j] <= nums[i-1])
                j--;
            myswap(&nums[i-1],&nums[j]);
            j = sz-1;
            while(j > i){
                myswap(&nums[i],&nums[j]);
                i++;
                j--;
            }
            
        }
        
    }
};