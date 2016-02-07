// String check
class Solution {
public:
    vector<vector<string>> all;
    
    bool check(string a, string b){
        if(a == b) return true;
        int sz = a.size();
        int diff = (a[0]+26-b[0])%26;
        for(int i = 1; i < sz; i++) if((a[i]+26-b[i])%26 != diff) 
            return false;
        return true;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int sz = strings.size();
        for(int i = 0; i < sz; i++){
            string now = strings[i];
            int sz2 = all.size();
            bool f = 0;
            for(int j = 0; j < sz2; j++){
                string tmp = all[j][0];
                if(now.size() != tmp.size()) continue;
                if(check(now,tmp)){
                     f = 1;
                     all[j].push_back(now);
                     break;
                }
            }
            if(!f){
                cout << "push" << now << endl;
                vector<string> ttmp;
                ttmp.push_back(now);
                all.push_back(ttmp);
            }
        }
        sz = all.size();
        for(int i = 0; i < sz; i++){
            sort(all[i].begin(),all[i].end());
        }
        return all;
    }
};