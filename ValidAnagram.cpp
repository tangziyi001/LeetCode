class Solution {
public:
    bool isAnagram(string s, string t) {
        int ss[26], tt[26];
        memset(ss,0,sizeof(ss));
        memset(tt,0,sizeof(tt));
        for(char& l : s){
            ss[l-'a']++;
        }
        for(char& l : t){
            tt[l-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(ss[i] != tt[i]) return false;
        }
        return true;
    }
};