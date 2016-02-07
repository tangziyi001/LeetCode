// DP with Stock: Two states (after buy/sell)
class Solution {
public:
    vector<int> s1,s2;
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if(sz == 0) return 0;
        s1.assign(sz,0);
        s2.assign(sz,0);
        s1[0] = 0;
        s2[0] = -prices[0]; // After Buying
        cout << s1[0] << " " << s2[0] << endl;
        for(int i = 1; i < sz; i++){
            s1[i] = max(s2[i-1]+prices[i], s1[i-1]);
            s2[i] = max(s1[i-1]-prices[i], s2[i-1]);
            cout << s1[i] << " " << s2[i] << endl;
        }
        return max(s1[sz-1],s2[sz-1]);
    }
};