class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int sz = org.size();
        if(sz == 1 && seqs.size() == 0) return false;
        vector<vector<int> > all;
        all.assign(sz,vector<int>(0,0));
        vector<int> deg(sz,0);
        vector<int> re;
        for(int i = 0; i < seqs.size(); i++){
            vector<int> now = seqs[i];
            if(now.size() == 0) {
                continue;
            }
            if(now.size() == 1){
                if(now[0] > sz || now[0] < 1) return false;
            }
            for(int j = 0; j < now.size()-1; j++){
                if(now[j] > sz || now[j+1] > sz || now[j] < 1 || now[j+1] < 1) return false;
                all[now[j]-1].push_back(now[j+1]-1);
                deg[now[j+1]-1]++;
            }
        }
        int cnt = 0;
        queue<int> qq;
        for(int i = 0; i < sz; i++){
            if(deg[i] == 0){
                cnt++; qq.push(i);
            }
            if(cnt == 2) return false;
        }
        qq.push(-1);
        cnt = 0;
        while(!qq.empty()){
            int now = qq.front();
            qq.pop();
            if(now == -1){
                cnt=0;
                if(!qq.empty()) qq.push(-1);
                continue;
            }
            cnt++;
            if(cnt == 2) return false;
            re.push_back(now+1);
            for(int i = 0; i < all[now].size(); i++){
                int nxt = all[now][i];
                deg[nxt]--;
                if(deg[nxt] == 0) qq.push(nxt);
            }
        }
        if(org != re) return false;
        return true;
    }
};