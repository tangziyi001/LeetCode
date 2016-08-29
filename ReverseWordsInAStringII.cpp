class Solution {
public:
    void reverseWords(string &s) {
        if(s == "") return ;
        auto i = s.begin();
        auto j = s.begin()+1;
        while(j != s.end() && i != s.end()){
            if(*j == ' '){
                reverse(i,j);
                i = j+1;
                j = i;
            }
            j++;
        }
        reverse(i,j);
        reverse(s.begin(), s.end());
    }
};