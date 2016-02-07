// Stack
class Solution {
public:
    int cont[30];
    int visit[30];
    string re;
    string removeDuplicateLetters(string s) {
        memset(cont,0,sizeof(cont));
        memset(visit,0,sizeof(visit));
        int sz = s.size();
        for(int i = 0; i < sz; i++){
            cont[s[i]-'a']++;
        }
        re += "0";
        for(int i = 0; i < sz; i++){
            cont[s[i]-'a']--;
            if(visit[s[i]-'a']) continue;
            while(s[i] < re.back() && cont[(int)re.back()-'a'] > 0){
                visit[re.back()-'a'] = 0;
                cout << "rem" << re.back() << endl;
                re.pop_back();
            }
            re+=s[i];
            visit[s[i]-'a'] = 1;
        }
        cout << re << endl;
        return re.substr(1);
    }
};