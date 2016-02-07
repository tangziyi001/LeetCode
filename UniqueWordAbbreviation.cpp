// String Attribute Comparison
class ValidWordAbbr {
public:
    vector<string> all;
    bool check(string a, string b){
        int as = a.size();
        int bs = b.size();
        if(a[0] == b[0] && a[as-1] == b[bs-1])
            return true;
        return false;
    }
    ValidWordAbbr(vector<string> &dictionary) {
        all = dictionary;
    }

    bool isUnique(string word) {
        int sz = all.size();
        for(int i = 0; i < sz; i++){
            if(all[i].size() != word.size()) continue;
            if(all[i] == word) continue;
            if(check(all[i],word)) return false;
        }
        return true;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");