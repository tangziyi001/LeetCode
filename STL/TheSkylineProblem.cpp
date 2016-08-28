class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        int sz = buildings.size();
        vector<pair<int,int>> all, re;
        multiset<int> hh;
        for(int i = 0; i < sz; i++){
            all.push_back(make_pair(buildings[i][0], -buildings[i][2]));
            all.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
        sort(all.begin(), all.end());
        hh.insert(0);
        int now = 0;
        for(int i = 0; i < all.size(); i++){
            if(all[i].second < 0){
                hh.insert(-all[i].second);
                cout << "Insert " << all[i].first << " " << all[i].second << endl;
            } else {
                hh.erase(hh.find(all[i].second));
                cout << "Remove " << all[i].first << " " << all[i].second << endl;
            }
            int tmp = *(hh.rbegin());
            if(tmp != now){
                re.push_back(make_pair(all[i].first, tmp));
                now = tmp;
            }
        }
        return re;
    }
};