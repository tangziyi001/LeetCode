typedef unsigned long long ull;
class TrieNode {
public:
    bool end;
    TrieNode* child[26];
    ull prefix_count;
    // Initialize your data structure here.
    TrieNode() {
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        end = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
        root->end = false;
        root->prefix_count = 0;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        cur->prefix_count++;
        for(ull i = 0; i < word.size(); i++){
            int letter = (int)word[i]-(int)'a';
            if(cur->child[letter] == NULL){
                cur->child[letter] = new TrieNode();
            }
            cur->child[letter]->prefix_count++;
            cur = cur->child[letter];
        }
        cur->end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for(ull i = 0; i < word.size(); i++){
            int letter = (int)word[i]-(int)'a';
            if(cur->child[letter] == NULL){
                return false;
            }
            cur = cur->child[letter];
        }
        return cur->end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(ull i = 0; i < prefix.size(); i++){
            int letter = (int)prefix[i]-(int)'a';
            if(cur->child[letter] == NULL){
                return false;
            }
            cur = cur->child[letter];
        }
        return true;
    }


};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");