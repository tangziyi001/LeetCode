const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> re;
        int rsz = matrix.size();
        if(rsz == 0)
            return re;
        int csz = matrix[0].size();
        if(csz == 0)
            return re;
        int d = 0;
        int x = 0;
        int y = 0;
        vector<vector<int>> mark(rsz, vector<int>(csz,0));
        int count = 0;
        while(count < rsz*csz){
            re.push_back(matrix[x][y]);
            mark[x][y] = 1;
            count++;
            int tx = x + dir[d][0];
            int ty = y + dir[d][1];
            if(tx >= 0 && tx < rsz && ty >= 0 && ty < csz && mark[tx][ty] == 0){
                x = tx;
                y = ty;
            } else {
                d++; d %= 4;
                x = x + dir[d][0];
                y = y + dir[d][1];
            }
        }
        return re;
    }
};