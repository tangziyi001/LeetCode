class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> re;
        int sz = s.size();
        for(int i = 0; i < sz-1; i++){
            if(s[i] == '+' && s[i+1] == '+'){
                s[i] = '-';
                s[i+1] = '-';
                re.push_back(s);
                s[i] = '+';
                s[i+1] = '+';
            }
        }
        return re;
    }
};