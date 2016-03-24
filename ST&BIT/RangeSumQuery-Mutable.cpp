// Use BIT to compute 1D range sum.
class NumArray {
public:
    vector<int> ft;
    int sz;
    vector<int> gnums;
    NumArray(vector<int> &nums) {
        sz = nums.size();
        gnums.assign(sz,0);
        ft.assign(sz+1,0);
        for(int i = 0; i < sz; i++){
            update(i,nums[i]);
        }
    }

    void update(int i, int val) {
        int diff = val - gnums[i];
        gnums[i] = val;
        i++;
        for(;i < sz+1; i+=(i&-i)){
            ft[i] += diff;
        }
    }
    int rsq(int b){
        b++;
        int sum = 0;
        for(;b > 0; b-=(b&-b))
            sum+=ft[b];
        return sum;
    }
    int sumRange(int i, int j) {
        return i == 0 ? rsq(j) : rsq(j) - rsq(i-1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);