// Technique for avoid duplicate
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
class Solution {
public:
    vvi re;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        if(sz == 0) return re;
        for(int i = 0; i < sz-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int a = i+1; int b = sz-1;
            //cout << a << " " << b << endl;
            while(a < b){
                //cout << nums[i] << " " << nums[a] << " " << nums[b] << endl;
                int sum = nums[i] + nums[a] + nums[b];
                if(sum > 0) b--;
                else if(sum < 0) a++;
                else{
                    vi tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[a]);
                    tmp.push_back(nums[b]);
                    re.push_back(tmp);
                    while(nums[a+1] == nums[a] && a <= sz-1) a++;
                    while(nums[b-1] == nums[b] && b >= i+1) b--;
                    a++;b--;
                }
            }
        }
        return re;
    }
};