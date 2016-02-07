// BFS removing parentheses: the first valid one is the longest one, then find all valid string with the same length. 
class Solution {
public:
    queue<string> qq;
    vector<string> re;
    set<string> ss;
    bool check(string now){
        int sz = now.size();
        int count = 0;
        for(int i = 0; i < sz; i++){
            if(now[i] == '(') count++;
            else if(now[i] == ')'){
                count--;
                if(count < 0) return false;
            }
        }
        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        qq.push(s);
        bool found = false;
        int length = -1;
        while(!qq.empty()){
            string now = qq.front();qq.pop();
            int sz = now.size();
            if(sz < length) break;
            if(check(now)){
                re.push_back(now);
                found = true;
                length = sz;
            }
            if(found == true) continue;
            for(int i = 0; i < sz; i++){
                if(now[i] != '(' && now[i] != ')') continue;
                string tmp = now.substr(0,i)+now.substr(i+1,sz-i-1);
                if(ss.find(tmp) == ss.end()){
                    qq.push(tmp);
                    ss.insert(tmp);
                }
            }
        }
        return re;
    }
};