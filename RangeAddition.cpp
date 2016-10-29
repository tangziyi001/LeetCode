class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> tmp(length,0);
        int sz = updates.size();
        for(int i = 0; i < sz; i++){
            vector<int> now = updates[i];
            tmp[now[1]] += now[2];
            if(now[0] != 0){
                tmp[now[0]-1] -= now[2];
            }
        }
        vector<int> re;
        re.assign(length,0);
        int sum = 0;
        for(int i = length-1; i >= 0; i--){
            sum += tmp[i];
            re[i] = sum;
        }
        return re;
    }
};