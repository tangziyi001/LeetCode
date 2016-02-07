// Backtracking
typedef vector<int> vi;
typedef vector<vi> vvi;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
public:
    vector<vector<char>> all;
    int rsz,csz;
    vvi mark;
    int wsz;
    bool check(int x, int y){
        if(x >= 0 && x < rsz && y >= 0 && y < csz && mark[x][y] == 0)
            return true;
        return false;
    }
    int rec(int pos, int x, int y, string word){
        //cout << pos << " " << x << y << endl;
        if(pos == wsz-1) return 1;
        int flag = 0;
        for(int i = 0; i < 4; i++){
            int tx = x+dir[i][0];
            int ty = y+dir[i][1];
            if(check(tx,ty) && all[tx][ty] == word[pos+1]){
                mark[tx][ty] = 1;
                flag |= rec(pos+1, tx, ty, word);
                mark[tx][ty] = 0;
                if(flag) return 1;
            }
        }
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        all = board;
        if(word == "" || board.size() == 0) return false;
        rsz = board.size();
        wsz = word.size();
        if(rsz == 0) return false;
        csz = board[0].size();
        vi ttmp (csz,0);
        mark.assign(rsz, ttmp);
        int flag = 0;
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                if(all[i][j] == word[0]){
                    //cout << i << " " << j << endl;
                    mark[i][j] = 1;
                    flag |= rec(0, i, j, word);
                    mark[i][j] = 0;
                    if(flag) return true;
                }
            }
        }
        return false;
    }
};