// Binary Search for square root: Pay attention to the final check.
typedef long long ll;
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        while(low < high){
            double mid = (high+low)/2;
            if(mid*mid < x) low = mid+1;
            else if(mid*mid > x) high = mid-1;
            else return mid;
        }
        return low*low > x ? low-1 : low;
    }
};