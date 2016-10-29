class Solution {
public:
    string removeKdigits(string num, int k) {
        num = num+'0';
        for(int i = 0; i < num.size() && k; i++){
            int now = num[i];
            if(i+1 >= num.size()) break;
            int nxt = num[i+1];
            if(now > nxt){
                num.erase(num.begin()+i);
                i-=2;
                if(i == -2) i++;
                k--;
            }
        }
        while(num[0] == '0' && num != "0"){
            num.erase(num.begin());
        }
        if(num != "0") num.pop_back();
        return num;
    }
};