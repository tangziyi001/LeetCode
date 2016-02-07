// Find positive numbers whose all prime factors are in the given prime list. Use an array idx to record the position of the next candidate to multiply in the result list. Find the smallest product of each prime number with its next candidate and add it to the result list.
typedef vector<int> vi;
class Solution {
public:
    vi idx;
    vi re;
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz = primes.size();
        idx.assign(sz,0);
        re.push_back(1);
        int tmp = 0;
        while(re.size() <= n){
            int nextnum = re[idx[0]]*primes[0];
            for(int i = 0; i < sz; i++){
                nextnum = min(nextnum, re[idx[i]]*primes[i]);
            }
            for(int i = 0; i < sz; i++){
                if(re[idx[i]]*primes[i] == nextnum) idx[i]++;
            }
            re.push_back(nextnum);
        }
        return re[n-1];
        
    }
};