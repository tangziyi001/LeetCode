// Recursion. Pay attention to the case of 0
class Solution {
public:
    string re;
    vector<string> result;
    char all[5] = {'0','1','8','6','9'};
    void rec(int sta,int ter){
        if(sta > ter){
            if(re[0] == '0' && re.size() != 1) return;
                result.push_back(re);
            return ;
        }
        for(int i = 0; i < 3; i++){
            re[sta] = all[i];
            re[ter] = all[i];
            rec(sta+1,ter-1);
        }
        if(sta < ter){
            re[sta] = all[3];
            re[ter] = all[4];
            rec(sta+1,ter-1);
            re[sta] = all[4];
            re[ter] = all[3];
            rec(sta+1,ter-1);
        }
    }
    vector<string> findStrobogrammatic(int n) {
        if(n == 0) return result;
        for(int i = 0; i < n; i++){
            re += "0";
        }
        rec(0,n-1);
        return result;
    }
};