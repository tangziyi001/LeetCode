// DFS Cycle Detection. Notice if the graph is a connected graph.
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
    vvi all;
    vi mark;
    int count = 0;
    bool check(int now, int p){
        mark[now] = 1;
        count++;
        int sz = all[now].size();
        bool flag = true;
        for(int i = 0; i < sz; i++){
            int tmp = all[now][i];
            if(mark[tmp] == 1 && tmp != p){
                return false;
            }
            if(mark[tmp] == 0){
                flag &= check(tmp,now);
            }
        }
        return flag;
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vi ttmp;
        all.assign(n,ttmp);
        mark.assign(n,0);
        int sz = edges.size();
        for(int i = 0; i < sz; i++){
            int f = edges[i].first;
            int s = edges[i].second;
            all[f].push_back(s);
            all[s].push_back(f);
        }
        return (check(0,0) && count == n);
        
    }
};