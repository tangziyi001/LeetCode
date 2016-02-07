//DP: Update each cell's number as 1 plus the minimum number within its adjacent cells (top,left,top-left). 
//Find the maximal number after updating.
class Solution {
public:
    int rsz,csz;
    vector<vector<int> > all;
    bool check(int x, int y){
        if(x >= 0 && x < rsz && y >= 0 && y < csz)
            return true;
        return false;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxp = 0;
        rsz = matrix.size();
        if(rsz == 0) return maxp;
        csz = matrix[0].size();
        if(csz == 0) return maxp;
        vector<int> ttmp(csz,0);
        all.assign(rsz,ttmp);
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                all[i][j] = (int)matrix[i][j] - (int)'0';
                if(check(i-1,j) && check(i-1,j-1) && check(i,j-1) && all[i][j] == 1){
                    int minp = (int)1E9;
                    minp = min(minp, all[i-1][j]);
                    minp = min(minp, all[i][j-1]);
                    minp = min(minp, all[i-1][j-1]);
                    all[i][j] = 1 + minp;
                }
                maxp = max(maxp, all[i][j]);
            }
        }
        return maxp*maxp;
    }
};