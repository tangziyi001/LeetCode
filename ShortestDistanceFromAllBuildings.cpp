// Multi Source BFS
#import <queue>
#import <vector>
typedef pair<int,int> pi;
typedef vector<pi> vpi;
int dir[4][2] = {{0,-1},{-1,0},{1,0},{0,1}};
class Solution {
public:
    int rsz;
    int csz;
    int check(int r, int c){
        if(r >= 0 && r < rsz && c >=0 && c < csz)
            return true;
        return false;
    }
    int shortestDistance(vector<vector<int>>& grid) {
        vpi buildings;
        queue<pi> qq;
        int counter = 0;
        rsz = grid.size();
        csz = grid[0].size();
        int sum[rsz+5][csz+5];
        int tmp[rsz+5][csz+5];
        memset(sum,0,sizeof(sum));
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                if(grid[i][j] == 1)
                    buildings.push_back(make_pair(i,j));
                if(grid[i][j] == 0)
                    counter++;
            }
        }
        if(counter == 0){
            return -1;
        }
        int nums = buildings.size();
        for(int i = 0; i < nums; i++){
            memset(tmp,-1,sizeof(sum));
            pi now = buildings[i];
            tmp[now.first][now.second] = 0;
            qq.push(now);
            while(!qq.empty()){
                pi ttmp = qq.front();qq.pop();
                int x = ttmp.first;
                int y = ttmp.second;
                for(int i = 0; i < 4; i++){
                    int tx = x+dir[i][0];
                    int ty = y+dir[i][1];
                    if(check(tx,ty) && grid[tx][ty] == 0 && tmp[tx][ty] == -1){
                        tmp[tx][ty] = tmp[x][y] + 1;
                        qq.push(make_pair(tx,ty));
                    }
                }
            }
            for(int i = 0; i < rsz; i++){
                for(int j = 0; j < csz; j++){
                     if(tmp[i][j] == -1){
                        sum[i][j] = -1;
                    }
                    else if(tmp[i][j] != -1 && sum[i][j] != -1)
                        sum[i][j] += tmp[i][j];
                }
                
            }
            
        }
        int minp = 1000000;
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                cout << sum[i][j] << endl;
                if(sum[i][j] < minp && grid[i][j] == 0 && sum[i][j] != -1){
                    minp = sum[i][j];
                }
            }
        }
        if(minp != 1000000)
            return minp;
        else
            return -1;
        
    }
};