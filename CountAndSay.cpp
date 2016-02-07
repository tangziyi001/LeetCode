// Counter for a sequence. Pay attention to the ending sequence.
class Solution {
public:
    vector<string> all;
    string count(string prev){
        string re;
        int cont = 1;
        char tmp;
        int sz = prev.size();
        for(int i = 0; i < sz; i++){
            if(i == 0){
                tmp = prev[i];
                continue;
            }
            if(prev[i] != tmp){
                re += (to_string(cont) + tmp);
                cont = 0;
                tmp = prev[i];
            }
            cont++;
        }
        re += (to_string(cont) + tmp);
        return re;
    }
    string countAndSay(int n) {
        all.push_back("1");
        for(int i = 1; i <= n; i++){
            string nxt = count(all[i-1]);
            all.push_back(nxt);
            //cout  << nxt << endl;
        }
        return all[n-1];
    }
};