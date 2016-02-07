typedef long long ll;
class Solution {
    vector<int> all;
    vector<int> length;
public:
    int maxProduct(vector<string>& words) {
        int sz = words.size();
        for(int i = 0; i < sz; i++){
            string now = words[i];
            int bit = 0;
            for(int j = 0; j < now.size(); j++){
                bit |= (1 << (now[j]-'a'));
            }
            all.push_back(bit);
            length.push_back(now.size());
        }
        int maxp = 0;
        for(int i = 0; i < sz-1; i++){
            int now = all[i];
            for(int j = i+1; j < sz; j++){
                int nxt = all[j];
                if((all[i] & all[j]) == 0)
                    maxp = max(maxp, length[i]*length[j]);
            }
        }
        return maxp;
    }
};