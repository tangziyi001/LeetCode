class Solution {
public:
    set<char> v;
    string reverseVowels(string s) {
        v.insert('a');
        v.insert('e');
        v.insert('i');
        v.insert('o');
        v.insert('u');
        v.insert('A');
        v.insert('E');
        v.insert('I');
        v.insert('O');
        v.insert('U');
        int i = 0, j = s.size()-1;
        while(i <= j){
            while(!v.count(s[i]) && i <= j) i++;
            while(i <= j && !v.count(s[j])) j--;
            if(i > j) break;
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;j--;
        }
        return s;
    }
};