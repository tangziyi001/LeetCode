class Solution {
public:
    string shortestPalindrome(string s) {
        string tmp = s;
        reverse(s.begin(), s.end());
        string t = tmp + "#" + s;
        // Construct KMP Table
        vector<int> table(t.size()+1, 0);
        int i = 0, j = -1;
        table[0] = -1;
        while(i < t.size()){
            while(j >= 0 && t[i] != t[j]){
                j = table[j];
            }
            i++; j++;
            table[i] = j;
        }
        int idx = table[t.size()];
        string sub = tmp.substr(idx, tmp.size()-idx);
        return s + sub;
    }
};