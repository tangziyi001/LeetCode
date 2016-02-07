// Use Binary Indexed Tree
// Update from right to left after each query
typedef vector<int> vi;
#define MAXN 20000
class Solution {
public:
    vi ft;
    int sz;
    int rsq(int b){
        int sum = 0;
        for(; b; b-=(b&(-b))){
            sum+=ft[b];
        }
        return sum;
    }
    int adjust(int pos, int val){
        for(; pos < MAXN-1; pos+=(pos&(-pos)))
            ft[pos] += val;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vi re;
        sz = nums.size();
        for(int i = 0; i < sz; i++){
            nums[i]+=10000;
        }
        re.assign(sz,0);
        ft.assign(MAXN+1,0);
        for(int i = sz-1; i >= 0; i--){
            re[i] = rsq(nums[i]-1);
            adjust(nums[i],1);
        }
        return re;
    }
};