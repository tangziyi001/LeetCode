// Bi-directional BFS optimization for words
// Using unordered_set
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> start;
        unordered_set<string> end;
        unordered_set<string> next;
        wordList.erase(beginWord);
        wordList.erase(endWord);
        int cur = 2;
        start.insert(beginWord);
        end.insert(endWord);
        while(!start.empty()){
            for(auto it = start.begin(); it != start.end(); it++){
                string now = *it;
                string tmp = now;
                for(int i = 0; i < now.size(); i++){
                     for(int j = 0; j < 26; j++) {
                            tmp[i] = 'a' + j;
                            if(tmp == now) continue;
                            if(end.count(tmp)){
                                return cur;
                            }
                            if(wordList.count(tmp)){
                                next.insert(tmp);
                                wordList.erase(tmp);
                            }
                     }
                     tmp = now;
                }
            }
            swap(start, next); next.clear();
            if(start.size() > end.size()) swap(start,end);
            cur++;
        }
        return 0;
    }
};