// Use MAP LIST PAIR to store the most recently seen element.

class Solution {
public:
    map<char, list<pair<char, int>>::iterator> mm;
    list<pair<char, int>> ll; // Most Recent
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int sz = s.size();
        int left = 0;
        int right = 0;
        int maxp = 0;
        while(right < sz){
            char now = s[right];
            if(mm.find(now) == mm.end()){
                if(mm.size() == 2){
                    pair<char,int> last = ll.back();
                    ll.pop_back();
                    left = last.second+1;
                    mm.erase(last.first);
                }
                ll.emplace_front(now,right);
                mm[now] = ll.begin();
                maxp = max(maxp, right-left+1);
            } else {
                auto it = mm[now];
                it->second = right;
                ll.splice(ll.begin(), ll, it);
                maxp = max(maxp, right-left+1);
            }
            right++;
        }
        return maxp;
    }
};