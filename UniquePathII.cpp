// DAG DP
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
    int rsz,csz;
    vvi all;
    vvi obs;
    int check(int x, int y){
        if(x >= 0 && x < rsz && y >= 0 && y < csz)
            return true;
        return false;
    }
    int rec(int x, int y){
        if(!check(x,y) || obs[x][y] == 1) return 0;
        if(x == rsz-1 && y == csz-1) return 1;
        if(all[x][y] != -1) return all[x][y];
        return all[x][y] = rec(x+1,y) + rec(x,y+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int re = rec(0,0);
        rsz = obstacleGrid.size();
        if(rsz == 0) return 0;
        csz = obstacleGrid[0].size();
        if(csz == 0) return 0;
        vi ttmp(csz,-1);
        all.assign(rsz,ttmp);
        obs = obstacleGrid;
        return rec(0,0);
    }
};