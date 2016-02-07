// Maintain a row marker, col marker and ceil marker to record if a number has already existed
// The precedence of bit wise operator is lower than ==.
#define FILL(s,v) memset(s,v,sizeof(s));
typedef pair<int,int> pi;
class Solution {
public:
    int row[9];
    int col[9];
    int ceil[3][3];
    vector<pi> all;
    vector<vector<int>> copy;
    int sz;
    int flag = 0;
    void rec(int pos){
        if(flag == 1) return ;
        if(pos == sz) flag = 1;
        else{
            int x = all[pos].first;
            int y = all[pos].second;
            for(int i = 0; i < 9 && flag == 0; i++){
                if((row[x] & (1 << i)) == 0 && (col[y] & (1 << i)) == 0 && (ceil[x/3][y/3] & (1 << i))  == 0){
                    row[x] |= (1 << i);
                    col[y] |= (1 << i);
                    ceil[x/3][y/3] |= (1 << i);
                    copy[x][y] = i;
                    rec(pos+1);
                    if(flag == 1) break;
                    row[x] &= ~(1 << i);
                    col[y] &= ~(1 << i);
                    ceil[x/3][y/3] &= ~(1 << i);
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        FILL(row,0);
        FILL(col,0);
        FILL(ceil,0);
        vector<int> ttmp(9,-1);
        copy.assign(9,ttmp);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.')
                    all.push_back(make_pair(i,j));
                else{
                    int val = (int)board[i][j]-(int)'1';
                    row[i] |= (1 << val);
                    col[j] |= (1 << val);
                    ceil[i/3][j/3] |= (1 << val);
                    copy[i][j] = val;
                }
            }
        }
        sz = all.size();
        cout << sz << endl;
        rec(0);
        for(int i = 0; i < 9; i++) for(int j = 0; j < 9; j++){
            board[i][j] = (char)(copy[i][j]+(int)'1');
        }
    }
};