// Variant of Palindrome
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int s = 0;
        int t = num.size()-1;
        while(s <= t){
            if((num[s] == '6' && num[t] == '9') 
            || (num[s] == '9' && num[t] == '6') 
            || (num[s] == '1' && num[t] == '1') 
            || (num[s] == '8' && num[t] == '8') 
            || (num[s] == '0' && num[t] == '0') ){
            s++;t--;
            }
            else
                return false;
        }
        return true;
    }
};