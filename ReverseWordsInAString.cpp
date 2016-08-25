class Solution {
public:
    void reverseWords(string &s) {
        vector<string> words;
        stringstream ss(s);
        string tmp;
        while(ss >> tmp){
            words.push_back(tmp);
        }
        int sz = words.size();
        string re = "";
        for(int i = sz-1; i >= 0; i--){
            if(i != sz-1){
                re += " ";
            }
            re += words[i];
        }
        s = re;
    }
};