class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> mm;
        set<string> exi;
        string tmp;
        stringstream ss(str);
        for(int i = 0; i < pattern.size(); i++){
            char now = pattern[i];
            ss >> tmp;
            //cout << tmp << endl;
            if(tmp == "") return false;
            if(mm.count(now) == 0){
                if(exi.count(tmp)) return false;
                mm[now] = tmp;
                exi.insert(tmp);
            } else {
                if(mm[now] == tmp) continue;
                else return false;
            }
        }
        if(ss >> tmp) return false;
        return true;
    }
};