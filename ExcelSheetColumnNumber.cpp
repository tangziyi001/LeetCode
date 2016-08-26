class Solution {
public:
    int titleToNumber(string s) {
        int sz = s.size();
        int re = 0;
        for(int i = 0; i < sz; i++){
            int power = sz - i - 1;
            re += (s[i]-'A'+1)*pow(26,power);
        }
        return re;
    }
};