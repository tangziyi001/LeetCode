// 8 Directions Check
typedef vector<vector<int>> vvi;
int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int m,n;
bool check(int x, int y){
    if(x >= 0 && x < m && y >= 0 && y < n)
        return true;
    return false;
}
class Solution {
public:
    vvi next;
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = 0;
        n = (m == 0 ? 0 : board[0].size());
        int tmp = 0;
        vector<int> ttmp;
        ttmp.assign(n,0);
        next.assign(m,ttmp);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int live = 0;
                for(int k = 0; k < 8; k++){
                    int ti = i + dir[k][0];
                    int tj = j + dir[k][1];
                    if(!check(ti,tj)) continue;
                    if(board[ti][tj] == 1)
                        live++;
                }
                if(board[i][j] == 0){
                    if(live == 3) next[i][j] = 1;
                    continue;
                }
                if(live < 2)
                    next[i][j] = 0;
                else if(live >= 2 && live <= 3)
                    next[i][j] = 1;
                else if(live > 3)
                    next[i][j] = 0;
                    
            }
        }
        board = next;
    }
};