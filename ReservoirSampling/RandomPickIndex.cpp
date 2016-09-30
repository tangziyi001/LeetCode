// Reservoir Sampling
class Solution {

vector<int> num;
public:
    Solution(vector<int> nums) {
        this->num = nums;
    }
    
    int pick(int target) {
        int idx = -1;
        int count = 0;
        for(int i = 0; i < num.size(); i++){
            if(num[i] != target) continue;
            int ran = rand()%(++count);
            if(ran == 0) idx = i;
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */