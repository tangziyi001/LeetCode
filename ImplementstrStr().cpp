// Simple String Check
class Solution {
public:
    bool check(string a, string b){
        return a == b;
    }
    int strStr(string haystack, string needle) {
        int sz = haystack.size();
        int ssz = needle.size();
        if(sz < ssz) return -1;
        for(int i = 0; i < sz-ssz+1; i++){
            if(check(needle, haystack.substr(i,ssz))) return i;
        }
        return -1;
    }
};