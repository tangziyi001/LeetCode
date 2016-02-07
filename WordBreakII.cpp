// Use DP to mark if a certain starting letter is possible. Prune the branch if not.
class Solution {
public:
    unordered_set<string> ss;
    string all;
    vector<string> re;
    vector<int> dp;
    int rec(int pos, int start, string now){
        if(dp[start] == 0) {
            return 0;
        }
        if(pos == all.size() && ss.find(all.substr(start,pos-start)) != ss.end()) {
            now+=all.substr(start,pos-start);
            re.push_back(now);
            return 1;
        }
        else if(pos == all.size()){
            return 0;
        }
        int flag = 0;
        if(ss.find(all.substr(start,pos+1-start)) != ss.end()){
            flag |= rec(pos+1, pos+1, now+all.substr(start,pos+1-start)+" ");
        }
        flag |= rec(pos+1,start,now);
        return dp[start] = flag;
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        ss = wordDict;
        all = s;
        dp.assign(s.size(),-1);
        rec(0,0,"");
        return re;
    }
};