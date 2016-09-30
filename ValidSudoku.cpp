class Solution {
public:
    bool checkSquare(int x, int y, vector<vector<char>>& board){
        set<char> all;
        cout << x << y << endl;
        for(int i = x; i < x+3; i++){
            for(int j = y; j < y+3; j++){
                char now = board[i][j];
                if(board[i][j] != '.'){
                    if(all.count(now))
                        return false;
                    if((int)now > (int)('0' + 9) || (int)now < (int)('0')){
                        return false;
                    }
                    all.insert(now);
                }
            }
        }
        cout << all.size() << endl;
        return true;
    }
    bool checkRC(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            set<char> all;
            for(int j = 0; j < 9; j++){
                char now = board[i][j];
                if(now != '.'){
                    if(all.count(now)){
                        return false;
                    } 
                    if((int)now > (int)('0' + 9) || (int)now < (int)('0')){
                        return false;
                    }
                    all.insert(now);
                }
            }
        }
        for(int i = 0; i < 9; i++){
            set<char> all;
            for(int j = 0; j < 9; j++){
                char now = board[j][i];
                if(now != '.'){
                    if(all.count(now)){
                        return false;
                    } 
                    if((int)now > (int)('0' + 9) || (int)now < (int)('0')){
                        return false;
                    }
                    all.insert(now);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        if(!checkRC(board)) return false;
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                if(!checkSquare(i,j,board)) return false;
            }
        }
        if(!checkRC(board)) return false;
        return true;
    }
};