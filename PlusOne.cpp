class Solution {
public:
    stack<int> ss;
    vector<int> re;
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int sz = digits.size();
        for(int i = sz-1; i >= 0; i--){
            int now = digits[i];
            if(i == sz-1)
                now += 1;
            if(carry == 1)
                now += 1;
            if(now/10 > 0)
                carry = 1;
            else
                carry = 0;
            now%=10;
            ss.push(now);
        }
        if(carry == 1)
            ss.push(1);
        int rsz = ss.size();
        while(!ss.empty()){
            re.push_back(ss.top());
            ss.pop();
        }
        return re;
    }
};