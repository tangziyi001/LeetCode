// One Edit Distances
class Solution {
public:
    bool check(string l, string s){
        int sz = s.size();
        int cont = 0;
        for(int i = 0; i < s.size(); i++){
            if(l[i] != s[i] && cont == 0){
                l.erase(l.begin()+i);
                i--;
                cont++;
            }
            else if(l[i] != s[i]) return false;
        }
        return true;
    }
    bool isOneEditDistance(string s, string t) {
        int ssz = s.size();
        int tsz = t.size();
        if(ssz == 0 && tsz == 0) return false;
        if(ssz == tsz){
            int cont = 0;
            for(int i = 0; i < ssz; i++){
                if(s[i] != t[i] && cont == 0) cont++;
                else if(s[i] != t[i]) return false;
            }
            if(cont == 1) return true;
            else return false;
        }
        else if(abs(ssz-tsz) == 1){
            if(ssz > tsz) return check(s,t);
            else return check(t,s);
        }
        else return false;
    }
};