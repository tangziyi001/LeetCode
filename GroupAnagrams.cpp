// Use sort to create the key for map
typedef long long ll;
typedef pair<string,vector<string>> pll;
class Solution {
public:
    map<string,vector<string> > all;
    vector<vector<string>> re;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sz = strs.size();
        for(int i = 0; i < sz; i++){
            string key = strs[i];
            sort(key.begin(),key.end());
            all[key].push_back(strs[i]);
        }
        for(auto it = all.begin(); it != all.end(); ++it){
            vector<string> tmp;
            tmp = (*it).second;
            sort(tmp.begin(), tmp.end());
            re.push_back(tmp);
        }
        return re;
    }
};