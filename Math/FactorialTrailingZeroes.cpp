typedef long long ll;
class Solution {
public:
    int trailingZeroes(int n) {
        ll five = 0;
        if(n == 0) return 0;
        for(ll k = 1; k < 14; k++){
            five += n/(int)pow(5,k);
        }
        return five;
    }
};