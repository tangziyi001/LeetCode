// Transform upper letter to lower letter
class Solution {
public:
    bool check(string s){
        int sz = s.size();
        int i = 0; int j = sz-1;
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        int sz = s.size();
        string tmp = "";
        for(int i = 0; i < sz; i++){
            if(s[i] != ' ' && (int)(s[i])-(int)'a' >= 0 && (int)(s[i])-(int)'a' <= 25){
                tmp+=s[i];
            }
            else if(s[i] != ' ' && (int)(s[i])-(int)'A' >= 0 && (int)(s[i])-(int)'A' <= 25){
                tmp+=(char)((int)s[i]-((int)'A'-(int)'a'));
            }
            else if(s[i] != ' ' && (int)s[i] >= (int)'0' && (int)s[i] <= (int)'9'){
                tmp+=s[i];
            }
        }
        if(tmp.size() == 0) return true;
        return check(tmp);
    }
};