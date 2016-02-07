typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vector<int> > vvi; 
class Solution {
public:
    vvi all;
    vi cont;
    vi mark;
    queue<int> qq;
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vi ttmp;
        vi re;
        all.assign(n,ttmp);
        cont.assign(n,0);
        mark.assign(n,0);
        int remain = n;
        int sz = edges.size();
        for(int i = 0; i < sz; i++){
            pi now = edges[i];
            all[now.first].push_back(now.second);
            all[now.second].push_back(now.first);
            cont[now.first]++; cont[now.second]++;
        }
        if(n == 2){
            re.push_back(0);
            re.push_back(1);
            return re;
        }
        for(int i = 0; i < n; i++){
            if(cont[i] == 1){
                cout << i << endl;
                qq.push(i);
            }
        }
        qq.push(-1);
        while(!qq.empty()){
            int tmp = qq.front();qq.pop();
            cout << tmp << endl;
            if(tmp == -1){
                cout << "-1 " << remain << endl;
                if(remain <= 2) 
                    break;
                else{
                    qq.push(-1);
                    continue;
                }
            }
            mark[tmp] = 1; remain--;
            int sz = all[tmp].size();
            for(int i = 0; i < sz; i++){
                cont[all[tmp][i]]--;
                if(cont[all[tmp][i]] == 1)
                    qq.push(all[tmp][i]);
            }
        }
        for(int i = 0; i < n; i++){
            if(mark[i] == 0)
                re.push_back(i);
        }
        return re;
    }
};