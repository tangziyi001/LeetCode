const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
struct Node{
    bool end;
    int count;
    Node* child[26];
    Node() {
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        end = false;
        count = 0;
    }
};
struct Trie{
    Node* root;
    set<string> re;
    int rsz;
    int csz;
    vector<vector<char>> board; 
    Trie(vector<vector<char>> board_) : root(new Node()), board(board_) {
        rsz = board.size();
        csz = board[0].size();
    }
    void insert(string word){
        Node* cur = root;
        for(int i = 0; i < word.size(); i++){
            int idx = (int)word[i]-(int)'a';
            if(cur->child[idx] == NULL){
                cur->child[idx] = new Node();
            }
            cur->count++;
            cur = cur->child[idx];
        }
        cur->end = true;
    }
    void rec(Node* cur, int tx, int ty, string& tmp){
        char now = board[tx][ty];
        board[tx][ty] = '#';
        tmp += now;
        if(cur->child[(int)now-(int)'a'] == NULL){
        } else {
            if (cur->child[(int)now-(int)'a']->end == true){
                re.insert(tmp);
            }
            for(int i = 0; i < 4; i++){
                int dx = tx + dir[i][0];
                int dy = ty + dir[i][1];
                if(dx >= 0 && dx < rsz && dy >= 0 && dy < csz && board[dx][dy] != '#'){
                    rec(cur->child[(int)now-(int)'a'], dx, dy, tmp);
                }
            }
        }
        board[tx][ty] = now;
        tmp.pop_back();
    }
    set<string> process(){
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                Node* cur = root;
                string tmp = "";
                rec(cur, i, j, tmp);
            }
        }
        return re;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size() == 0 || board[0].size() == 0) return vector<string>(0,"");
        Trie* trie = new Trie(board);
        for(int i = 0; i < words.size(); i++){
            trie->insert(words[i]);
        }
        set<string> re = trie->process();
        vector<string> rv;
        for(auto it = re.begin(); it != re.end(); it++){
            rv.push_back(*it);
        }
        return rv;
    }
};