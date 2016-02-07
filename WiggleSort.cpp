// Usage of Swap function
class Solution {
public:
    void swap(int* a, int* b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        if(sz <= 2) return;
        for(int i = 1; i < sz-1; i+=2){
            swap(&nums[i], &nums[i+1]);
        }
    }
};