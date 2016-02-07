// DP: Coin Change
class Solution {
public:
    vector<int> sq;
    int sz;
    vector<int> dp;
    int rec(int remain){
        //cout << remain << endl;
        if(remain < 0) return (int)1E9;
        if(remain == 0)
            return 0;
        if(dp[remain] != -1)
            return dp[remain];
        else{
            int minp = (int)1E9;
            for(int i = sz-1; i > 0; i--){
                if(remain >= sq[i])
                    minp = min(minp, 1+rec(remain-sq[i]));
            }
            return dp[remain] = minp;
        }
        
    }
    int numSquares(int n) {
        dp.assign(n+1,-1);
        for(int i = 0; i*i <= n; i++){
            sq.push_back(i*i);
        }
        sz = sq.size();
        return rec(n);
    }
    
};