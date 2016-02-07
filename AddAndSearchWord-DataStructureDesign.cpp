// Recursive Backtracking on Trie
class WordDictionary {
public:
    typedef struct TrieNode{
        bool end;
        int cont;
        TrieNode* child[26];
    } TrieNode;
    
    TrieNode* head;
    WordDictionary(){
        head = new TrieNode();
        head->end = false;
        head->cont = 0;
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* cur = head;
        cur->cont++;
        for(int i = 0; i < word.size(); i++){
            int letter = word[i] - (int)'a';
            if(cur->child[letter] == NULL)
                cur->child[letter] = new TrieNode();
            cur->child[letter]->cont++;
            cur = cur->child[letter];
        }
        cur->end = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode* cur = head;
        return rec(word, cur, 0);
    }
    bool rec(string word, TrieNode* cur, int idx){
        if(idx == word.size()) return cur->end;
        bool flag = false;
        if(word[idx] == '.'){
            for(int i = 0; i < 26; i++){
                if(cur->child[i] != NULL)
                    flag |= rec(word, cur->child[i], idx+1);
            }
        }
        else{
            int letter = (int)word[idx] - (int)'a';
            if(cur->child[letter] == NULL) return false;
            flag = rec(word, cur->child[letter], idx+1);
        }
        return flag;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");