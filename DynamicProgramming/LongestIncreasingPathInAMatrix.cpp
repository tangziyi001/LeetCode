const int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
class Solution {
public:
    int rsz,csz;
    int maxp = 0;
    vector<vector<int>> dp;
    vector<vector<int>> mm;
    int rec(int x, int y){
        if(dp[x][y] != -1) return dp[x][y];
        int tmpmax = 1;
        for(int i = 0; i < 4; i++){
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx >= 0 && tx < rsz && ty >= 0 && ty < csz && mm[tx][ty] > mm[x][y]){
                tmpmax = max(tmpmax, 1+rec(tx,ty));
            }
        }
        return dp[x][y] = tmpmax;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rsz = matrix.size();
        if(!rsz) return 0;
        csz = matrix[0].size();
        if(!csz) return 0;
        vector<int> ttmp(csz,-1);
        dp.assign(rsz,ttmp);
        mm = matrix;
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                    maxp = max(maxp,rec(i,j));
            }
        }
        return maxp;
    }
};