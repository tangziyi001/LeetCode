class Solution {
public:
    int dir[8][2] = {{1,0},{0,-1},{0,1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    bool check(int x, int y, int n, int m){
        if(x >= 0 && x < n && y >= 0 && y < m){
            return true;
        } 
        return false;
    }
    int checkNei(int x, int y, int rsz, int csz, vector<vector<int> >& board){
        int cnt = 0;
        for(int i = 0; i < 8; i++){
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(check(tx,ty,rsz,csz) && (board[tx][ty] & 1))
                cnt++;
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int rsz = board.size();
        if(rsz == 0) return ;
        int csz = board[0].size();
        if(csz == 0) return ;
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                int liveNei = checkNei(i,j,rsz,csz,board);
                cout << liveNei << endl;
                if(board[i][j] & 1){
                    if(liveNei == 2 || liveNei == 3){
                        board[i][j] |= (1 << 1);
                    }
                } else {
                    if(liveNei == 3){
                        cout << "here" << endl;
                        board[i][j] |= (1 << 1);
                    }
                }
            }
        }
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                board[i][j] >>= 1;
            }
        }
    }
};