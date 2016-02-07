// Add Binary: digit carry
class Solution {
public:
    string re;
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int sz = max(a.size(), b.size());
        int carry = 0;
        for(int i = 0; i < sz; i++){
            int tmp = 0;
            char x = '0', y = '0';
            if(i < a.size()) x = a[i];
            if(i < b.size()) y = b[i];
            tmp += ((int)x-(int)'0' + (int)y-(int)'0');
            if(carry){
                carry = 0; tmp+=1;
            }
            if(tmp>=2){
                tmp -= 2; carry = 1;
            }
            re+=(char)(tmp + (int)'0');
        }
        if(carry)
            re+='1';
        reverse(re.begin(),re.end());
        return re;
    }
};