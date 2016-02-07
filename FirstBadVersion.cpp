// Make sure to use long long
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
typedef long long ll;
class Solution {
public:
    int firstBadVersion(int n) {
        ll i = 1;
        ll j = n;
        while(i != j){
            ll mid = (i+j)/2;
            bool now = isBadVersion(mid);
            if(now == true)
                j = mid;
            else
                i = mid+1;
        }
        return (int)i;
    }
};