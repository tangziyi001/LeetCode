class Solution {
public:
    void dfs(int idx, int num, vector<string>& re, int hour, int min){
        if(idx == 10 && num == 0){
            if(hour >= 12 || min >= 60) return ;
            string tmp = "";
            tmp += to_string(hour);
            tmp += ':';
            if(min < 10) tmp += '0';
            tmp += to_string(min);
            re.push_back(tmp);
            return ;
        } else if(idx == 10) return ;
        // Take this light
        if(num >= 1){
            if(idx < 4){
                int nxtHour = hour | (1 << idx);
                dfs(idx+1,num-1, re, nxtHour, min);
            } else {
                int nxtMin = min | (1 << (idx-4));
                dfs(idx+1,num-1, re, hour, nxtMin);
            }
        }
        // Not take this light
        dfs(idx+1, num, re, hour, min);
    }
    static bool mycomp(string a, string b){
        int it1 = a[1] == ':' ? 1 : 2;
        int it2 = b[1] == ':' ? 1 : 2;
        string ah = a.substr(0, it1);
        string bh = b.substr(0, it2);
        string am = a.substr(it1+1);
        string bm = b.substr(it2+1);
        if(ah == bh) return stoi(am) < stoi(bm);
        return stoi(ah) < stoi(bh);
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> re;
        dfs(0, num, re, 0, 0);
        sort(re.begin(), re.end(), mycomp);
        return re;
    }
};