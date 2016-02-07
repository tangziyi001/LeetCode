// Backtracking: Check each letter, either take it or abbreviate it. Maintain a counter. If 
// we want to keep a letter, then the previous counter must be appended and set to 0.
class Solution {
public:
    vector<string> all;
    string ori;
    int sz = 0;
    void rec(string now, int pos, int count){
        if(pos >= sz){
            if(count > 0)
                now += to_string(count);
            cout << now << endl;
            all.push_back(now);
        }
        else{
            rec(now, pos+1, count+1);
            rec(now + (count > 0 ? to_string(count) : "") +ori[pos], pos+1, 0);
        }
    }
    vector<string> generateAbbreviations(string word) {
        ori = word;
        sz = word.size();
        rec("",0,0);
        return all;
    }
};