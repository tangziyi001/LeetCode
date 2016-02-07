// Flood Fill
class Solution {
public:
    int rsz,csz;
    vector<vector<char>> all;
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    bool check(int x, int y){
        if(x >= 0 && x < rsz && y >= 0 && y < csz)
            return true;
        return false;
    }
    void dfs(int x, int y){
        all[x][y] = -1;
        for(int i = 0; i < 4; i++){
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(check(tx,ty) && all[tx][ty] == '1')
                dfs(tx,ty);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        rsz = grid.size();
        if(!rsz) return 0;
        csz = grid[0].size();
        if(!csz) return 0;
        all = grid;
        int count = 0;
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                if(all[i][j] == '1'){
                    count++;
                    dfs(i,j);
                }
            }
        }
        return count;
            
    }
};