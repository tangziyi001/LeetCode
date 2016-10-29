// Use Multiset to simulate a binary search tree

typedef long long ll;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, ll k, ll t) {
        multiset<ll> all;
        if(nums.size() == 0) return false;
        int i = 0, j = i+1;
        all.insert(nums[i]);
        while(j < nums.size()){
            while(j-i <= k && j < nums.size()){
                all.insert(nums[j]);
                auto it = all.find(nums[j]);
                auto it1 = prev(it, 1);
                auto it2 = next(it, 1);
                //cout << *it1 << " " << *it << " " << *it2 << endl;
                if(it != all.begin() && abs((*it1)-(ll)nums[j]) <= t)
                    return true;
                if(it2 != all.end() && abs((*it2)-(ll)nums[j]) <= t)
                    return true;
                j++;
            }
            all.erase(nums[i]);
            i++;
        }
        return false;
    }
};