// DP with two states: same as or before or not.
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
    vvi all;
    int numWays(int n, int k) {
        if(n == 0 || k == 0) return 0;
        if(n == 1) return k;
        if(n == 2) return k*(k-1)+k;
        vi ttmp;
        ttmp.assign(2,0);
        all.assign(n+1,ttmp);
        all[0][0] = 0;
        all[1][0] = k;
        all[1][1] = k;
        all[2][0] = all[1][0]*(k-1);
        all[2][1] = all[1][0];
        for(int i = 3; i <= n; i++){
            all[i][0] = (k-1)*all[i-1][0] + (k-1)*all[i-1][1];
            all[i][1] = all[i-1][0];
        }
        return all[n][0]+all[n][1];
    }
};