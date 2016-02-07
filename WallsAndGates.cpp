// Multi-source BFS
typedef pair<int,int> pi;
typedef vector<pi> vpi;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
public:
    vpi start;
    queue<pi> qq;
    int rsz, csz;
    bool check(int r, int c){
        if(r >= 0 && r < rsz && c >= 0 && c < csz)
            return true;
        return false;
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        rsz = rooms.size();
        if(rsz == 0) return ;
        csz = rooms[0].size();
        if(csz == 0) return ;
        for(int i = 0; i < rsz; i++) 
            for(int j = 0; j < csz; j++) 
                if(rooms[i][j] == 0) 
                    start.push_back(make_pair(i,j));
        int sz = start.size();
        for(int i = 0; i < sz; i++){
            pi sta = start[i];
            qq.push(sta);
            while(!qq.empty()){
                pi now = qq.front();qq.pop();
                int x = now.first;
                int y = now.second;
                for(int k = 0; k < 4; k++){
                    int tx = x+dir[k][0];
                    int ty = y+dir[k][1];
                    if(check(tx,ty) && rooms[tx][ty] != -1 && rooms[tx][ty] > 1+rooms[x][y]){
                        rooms[tx][ty] = 1+rooms[x][y];
                        qq.push(make_pair(tx,ty));
                    }
                }
            }
        }
    }
};