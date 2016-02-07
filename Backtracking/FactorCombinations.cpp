// Backtracking with pruning.
// 1 and the number itself cannot be treated as factors
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
    vvi re;
    vi tmp;
    int tn;
    int prune = 0;
    void rec(int n, int now){
        if(n == 1) {
            prune = 1;
            if(tmp.size() > 1)
                re.push_back(tmp);
            return ;
        }
        for(int i = now; i <= n; i++){
            if(n%i == 0){
                tmp.push_back(i);
                rec(n/i,i);
                tmp.pop_back();
                if(prune == 1){
                    prune = 0;
                    break;
                }
            }
        }
    }
    vector<vector<int>> getFactors(int n) {
        if(n == 1) return re;
        tn = n;
        rec(n,2);
        return re;
    }
};