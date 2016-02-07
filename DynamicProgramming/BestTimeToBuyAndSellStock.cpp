// Find largest difference
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if(sz == 0) return 0;
        int a = 0;
        int tmp = prices[a];
        int maxp = 0;
        for(int i = 0; i < sz; i++){
            if(prices[i] < prices[a]){
                a = i;
            }
            else{
                maxp = max(maxp, prices[i]-prices[a]);
            }
        }
        return maxp;
    }
};