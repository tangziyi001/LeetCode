// Pay attention to the corner cases
class Solution {
public:
    stack<char> ss;
    bool isValid(string s) {
        int sz = s.size();
        for(int i = 0; i < sz; i++){
            char now = s[i];
            if(now == '(' || now == '[' || now == '{')
                ss.push(now);
            else if(ss.empty()) return false;
            else if((now == ')' && ss.top() == '(')
                    || (now == ']' && ss.top() == '[')
                    || (now == '}' && ss.top() == '{'))
                ss.pop();
            else
                return false;
        }
        if(ss.empty()) return true;
        else return false;
    }
};