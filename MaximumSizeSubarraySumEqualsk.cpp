// Use sum(i,j) = sum[j]-sum[i-1]. Store sum[i] and i into a map.
typedef vector<int> vi;
class Solution {
public:
    vi sum;
    map<int,int> all;
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sz = nums.size();
        if(sz == 0) return 0;
        int maxp = 0;
        sum.push_back(0);
        for(int i = 0; i < sz; i++){
            sum.push_back(nums[i]+sum[i]);
        }
        for(int i = 0; i <= sz; i++){
            if(all.find(sum[i]) == all.end()) all[sum[i]] = i;
        }
        for(int j = 1; j <= sz; j++){
            int tar = sum[j]-k;
            if(all.find(tar) != all.end() && all[tar] <= j) maxp = max(maxp, j-all[tar]);
        }
        cout << maxp << endl;
        return maxp;
    }
};