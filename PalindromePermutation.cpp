// Observse the odd and even attribute of palindrome
class Solution {
public:
	
    int cont[10000];
    bool canPermutePalindrome(string s) {
        memset(cont,0,sizeof(cont));
        int sz = s.size();
        for(int i = 0; i < sz; i++){
            cont[(int)s[i]]++;
        }
        int odd = 0;
        for(int i = 0; i < 10000; i++){
            if(cont[i] > 0 && cont[i] % 2 != 0)
                odd++;
            if(odd > 1) break;
        }
        if(odd > 1)
            return false;
        else
            return true;
    }
};