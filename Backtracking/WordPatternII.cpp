class Solution {
public:
    int rec(string& str, string& pattern, map<char,string>& mm, set<string>& ss, int idx, int sta, int ter){
        if(idx == pattern.size() && sta == str.size()) return true;
        if(idx == pattern.size() || sta == str.size()) return false;
        if(ter == str.size()) return false;
        string cat = str.substr(sta, ter-sta+1);
        int flag = 0;
        flag |= rec(str, pattern, mm, ss, idx, sta, ter+1);
        if(mm.count(pattern[idx]) == 0){
            if(ss.count(cat) != 0) return flag;
            mm[pattern[idx]] = cat;
            ss.insert(cat);
            flag |= rec(str, pattern, mm, ss, idx+1, ter+1, ter+1);
            mm.erase(pattern[idx]);
            ss.erase(cat);
        } else {
            if(mm[pattern[idx]] == cat) 
                flag |= rec(str, pattern, mm, ss, idx+1, ter+1, ter+1);
            else return flag;
        }
        //cout << idx << " " << sta << " " << cat << " " << flag << endl;
        return flag;
    }
    bool wordPatternMatch(string pattern, string str) {
        map<char, string> mm;
        set<string> ss;
        return rec(str, pattern, mm, ss, 0, 0, 0);
    }
};