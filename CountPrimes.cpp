typedef long long ll;
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> bs(n+5,0);
        for(ll i = 2;  i < n; i++) if(bs[i] == 0){
            count++;
            for(ll j = i*i; j < n; j += i){
                bs[j] = 1;
            }
        }
        return count;
    }
};