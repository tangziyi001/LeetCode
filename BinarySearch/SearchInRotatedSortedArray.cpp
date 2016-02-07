// Use Binary Search to find the pivot.
// Then Binary Search on one side.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = 0;
        int sz = nums.size();
        if(sz == 0) return -1;
        int i = 0; int j = sz-1;
        while(i < j){
            int mid = (i+j)/2;
            if(nums[mid] >= nums[i] && nums[mid] > nums[j]){
                i = mid+1;
            }
            else if(nums[mid] <= nums[i] && nums[mid] < nums[j]){
                j = mid;
            }
            else j = mid;
        }
        pivot = i;
        i = 0; j = sz-1;
        cout << pivot << endl;
        if(target <= nums[j]) i = pivot;
        else if(target >= nums[i]) j = pivot-1;
        else return -1;
        while(i < j){
            int mid = (i+j)/2;
            if(nums[mid] < target)
                i = mid+1;
            else if(nums[mid] > target)
                j = mid-1;
            else
                return mid;
        }
        return nums[i] == target ? i : -1;
    }
};