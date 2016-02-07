// Recursion: Win Guarantee
class Solution {
public:
    int sz;
    string str;
    int rec(){
        for(int i = 0; i < sz-1; i++){
            if(str[i] == '+' && str[i+1] == '+'){
                str[i] = '-';
                str[i+1] = '-';
                int next = rec();
                str[i] = '+';
                str[i+1] = '+';
                if(!next) return 1;
            }
        }
        return 0;
    }
    bool canWin(string s) {
        sz = s.size();
        str = s;
        int re = 0;
        re = rec();
        return re;
    }
};