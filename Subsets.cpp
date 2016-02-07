// If sorted, no need to check if the previous element is smaller
class Solution {
public:
    vector<vector<int>> re;
    vector<int> tmp;
    vector<int> all;
    int sz;
    void rec(int pos, int prev){
        if(pos == sz){
            re.push_back(tmp);
            return ;
        }
        if(all[pos] >= prev){
            tmp.push_back(all[pos]);
            rec(pos+1, all[pos]);
            tmp.pop_back();
        }
        rec(pos+1,prev);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        all = nums;
        sz = nums.size();
        sort(all.begin(),all.end());
        if(sz == 0) return re;
        rec(0,-(int)1E9);
        return re;
    }
};