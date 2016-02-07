// Use stack to process RPN
class Solution {
public:
    stack<int> ss;
    int evalRPN(vector<string>& tokens) {
        int re;
        int sz = tokens.size();
        for(int i = 0; i < sz; i++){
            string now = tokens[i];
            if(now == "+"){
                int a = ss.top();ss.pop();
                int b = ss.top();ss.pop();
                ss.push(a+b);
            }
            else if(now == "-"){
                int a = ss.top();ss.pop();
                int b = ss.top();ss.pop();
                ss.push(b-a);
            }
            else if(now == "*"){
                int a = ss.top();ss.pop();
                int b = ss.top();ss.pop();
                ss.push(a*b);
            }
            else if(now == "/"){
                int a = ss.top();ss.pop();
                int b = ss.top();ss.pop();
                ss.push(b/a);
            }
            else{
                ss.push(stoi(now));
            }
        }
        return ss.top();
    }
};