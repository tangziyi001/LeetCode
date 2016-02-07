// Flood Fill
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
class Solution {
public:
    vvi all;
    vi mark;
    int count = 0;
    int dfs(int pos){
        mark[pos] = 1;
        int sz = all[pos].size();
        for(int i = 0; i < sz; i++){
            int tmp = all[pos][i];
            if(mark[tmp] == 0)
                dfs(tmp);
        }
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        mark.assign(n,0);
        vi ttmp;
        all.assign(n,ttmp);
        int sz = edges.size();
        for(int i = 0; i < sz; i++){
            pi now = edges[i];
            all[now.first].push_back(now.second);
            all[now.second].push_back(now.first);
        }
        for(int i = 0; i < n; i++){
            if(mark[i] == 0){
                dfs(i);
                count++;
            }
        }
        return count;
        
    }
};