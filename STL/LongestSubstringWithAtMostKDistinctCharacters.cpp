class Solution {
public:
    map<char, list<pair<char,int>>::iterator> mm;
    list<pair<char,int>> ll;
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int sz = s.size();
        int idx = 0;
        int maxp = 0;
        for(int i = 0; i < sz; i++){
            auto it = mm.find(s[i]);
            if(it != mm.end()){
                it->second->second = i; // Update Right most index for this char
                ll.splice(ll.begin(), ll, it->second); // Put it at front (Most Recent)
            } else {
                ll.emplace_front(s[i], i); // Push the new char at front
                mm[s[i]] = ll.begin();
            }
            if(mm.size() > k){
                char evict = ll.back().first; // Pop the least recent character
                idx = ll.back().second+1;
                ll.pop_back();
                mm.erase(evict);
            }
            maxp = max(i-idx+1, maxp);
        }
        return maxp;
    }
};