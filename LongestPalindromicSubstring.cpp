class Solution {
public:
    string longestPalindrome(string s) {
        string re = "";
        int maxj = -1;
        int sz = s.size();
        for(int i = 0; i < sz; i++){
            int j = 0;
            while(i-j >= 0 && i+j < sz){
                if(s[i+j] != s[i-j])
                    break;
                if(j > maxj){
                    re = s.substr(i-j,2*j+1);
                    maxj = j;
                }
                j++;
            }
        }
        for(int i = 0; i < sz-1; i++){
            int j = 0;
            while(i-j >= 0 && i+1+j < sz){
                if(s[i+1+j] != s[i-j])
                    break;
                if(j+1 > maxj){
                    re = s.substr(i-j,2*j+2);
                    maxj = j+1;
                }
                j++;
            }
        }
        return re;
    }
};