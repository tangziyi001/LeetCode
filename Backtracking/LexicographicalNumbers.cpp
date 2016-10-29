class Solution {
public:
    void rec(vector<int>& re, int idx, int now, int n){
        for(int i = 0; i <= 9; i++){
            if(i == 0 && idx == 0) continue;
            int nxt = now*10+i;
            if(nxt <= n){
                re.push_back(nxt);
                rec(re, idx+1, nxt, n);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> re;
        rec(re, 0, 0, n);
        return re;
    }
};